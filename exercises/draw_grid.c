#include <SDL2/SDL.h>
#include <stdint.h>

extern uint32_t* color_buffer;
extern int window_width, window_height;

uint32_t color = 0xFF333333;

void draw_line_grid(void) {
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

void draw_dot_grid(void) {
    for (int h = 0; h < window_height; h += 10) {
        for (int w = 0; w < window_width; w += 10) {
            color_buffer[(window_width * h) + w] = color;
        }
    } 
}
