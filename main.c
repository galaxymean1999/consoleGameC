#include <stdio.h>
#include <time.h>
#include "engine.h"

char screenBuffer[120*40];

int running = 1;

double x = 0.0;
double y = 0.0;

void checkKeys(char key) {
    if (key == 'w' && y > 0) {
        y--;
    }
    if (key == 's' && y < 39) {
        y++;
    }
    if (key == 'a' && x > 0) {
        x--;
    }
    if (key == 'd' && x < 119) {
        x++;
    }
}

int main() {
    system("clear");

    while (running == 1) {
        clock_t t = clock();
        
        if (kbhit()) {
            char key = getchar();

            checkKeys(key);
        }

        clearBuff(&screenBuffer, ' ');
        
        setPixel((int)x, (int)y, &screenBuffer, '#');

        writeBuff(&screenBuffer);
        
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC * 1000;
        msleep(1000/60 - time_taken); 
    }

    return 0;
}
