#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define DEFAULT_RENDER -1
#define RENDER_NO_FLAG 0
#define RENDER_COLOR_R 255
#define RENDER_COLOR_G 0
#define RENDER_COLOR_B 0
#define RENDER_ALPHA 255


bool is_running = false;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool initialize_window(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return false;
    }
    
    // Create a SDL Window
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,        
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        fprintf(stderr, "Error creating SDL window.\n");
        return false;
    }

    // Create a SDL Renderer
    renderer = SDL_CreateRenderer(window, DEFAULT_RENDER, RENDER_NO_FLAG);
    if (!renderer) {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return false;
    }

    return true;
}

void setup(void) {

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

    return 0;
}
