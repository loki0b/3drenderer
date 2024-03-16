#include <SDL2/SDL.h>
#include <stdint.h>

extern uint32_t* color_buffer;
extern int window_width, window_height;

void draw_rect(int x, int y, int width, int height, uint32_t color) {
    for (int h = 0; h < window_height; h++) {
        for (int w = 0; w < window_width; w++) {
            if (w >= x && w <= x + width && h >= height && h <= y + height) {
                color_buffer[(window_width * h) + w] = color;
            }
        }
    }
}
