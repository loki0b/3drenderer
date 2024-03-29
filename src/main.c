#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "display.h"
#include "vector.h"

#define RENDER_COLOR_R 255
#define RENDER_COLOR_G 0
#define RENDER_COLOR_B 0
#define RENDER_ALPHA 255

#define BLACK 0xFF000000

bool is_running = false;

void setup(void) {
    // Allocate the required memory in bytes to hold the color buffer
    color_buffer = (uint32_t*) malloc(sizeof(uint32_t) * window_width * window_height);
    if (!color_buffer); // error
    
    // Creating a SDL texture that is used to display the color buffer
    color_buffer_texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        window_width,
        window_height        
    );
}

void process_input(void) {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                is_running = false;
            }
            break;
    }
}

void update(void) {

}

void render(void) {
    SDL_SetRenderDrawColor(
        renderer, 
        RENDER_COLOR_R, 
        RENDER_COLOR_G, 
        RENDER_COLOR_B, 
        RENDER_ALPHA
        );

    SDL_RenderClear(renderer);
    
    draw_line_grid();
    draw_pixel(30, 30, 0xFFFF00FF);
    draw_pixel(31, 31, 0xFFFF00FF);
    draw_pixel(32, 32, 0xFFFF00FF);
    draw_pixel(33, 33, 0xFFFF00FF);

    draw_rect(300, 200, 300, 150, 0xFFFFFF00);

    render_color_buffer();
    clear_color_buffer(BLACK);

    SDL_RenderPresent(renderer);
}

int main(void) {
    
    is_running = initialize_window();
    
    setup();

    while (is_running) {
        process_input();
        update();
        render();
    }
    
    destroy_window();

    return 0;
}
