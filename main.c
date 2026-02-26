#include <stdio.h>
#include <time.h>
#include "engine.h"

char screenBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

int running = 1;

double x = 0.0;
double y = 0.0;

void checkKeys(char key) {
    if (key == 'w' && y > 0) {
        y--;
    }
    if (key == 's' && y < SCREEN_HEIGHT - 1) {
        y++;
    }
    if (key == 'a' && x > 0) {
        x--;
    }
    if (key == 'd' && x < SCREEN_WIDTH - 1) {
        x++;
    }
}

int main() {
    

    while (running == 1) {
        clock_t t = clock();
        
        if (kbhit()) {
            char key = getchar();

            checkKeys(key);
        }

        clearBuff(&screenBuffer, ' ');
        
        setPixel((int)x, (int)y, &screenBuffer, '#');

        system("clear");
        writeBuff(&screenBuffer);
        
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC * 1000;
        msleep(1000/60 - time_taken); 
    }

    return 0;
}
