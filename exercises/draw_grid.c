#include <SDL2/SDL.h>
#include <stdint.h>

extern uint32_t* color_buffer;
extern int window_width, window_height;

void draw_grid(void) {
    uint32_t color = 0xFF000000;

    for (int h = 0; h < window_height; h++) {
        if (h % 10 == 0) {
	        for (int w = 0; w < window_width; w++) {
	            color_buffer[(window_width * h) + w] = color;
	        }
	    }
        else {
	        for (int w = 0; w < window_width; w += 10) {
	            color_buffer[(window_width * h) + w] = color;
	        }
        }
    }
}
