#include "engine.h"

void verline(int x, int y1, int y2, char type, char *screen_buffer) {
    for (int y = y1; y <= y2; y++) {
        screen_buffer[y*SCREENWIDTH + x] = type;
    }
}

void horline(int x1, int x2, int y, char type, char *screen_buffer) {
    for (int x = x1; x <= x2; x++) {
        screen_buffer[y*SCREENWIDTH + x] = type;
    }
}

void initscrbuffer(char *screen_buffer) {
    for (int i = 0; i < SCREENWIDTH * SCREENHEIGHT; i++) {
        screen_buffer[i] = ' ';
    }
}

void drawbuffer(char *screen_buffer) {
    system("clear");

    for (int y = 0; y < SCREENHEIGHT; y++) {
        for (int x = 0; x < SCREENWIDTH; x++) {
            printf("%c", screen_buffer[y*SCREENWIDTH + x]);
        }
        printf("*\n");
    }
    for (int i = 0; i <= SCREENWIDTH; i++) {
        printf("*");
    }
}

void update() {
    
}

void draw(char *screen_buffer) {
    
}
