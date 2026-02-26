#include <stdio.h>
#include <time.h>
#include "engine.h"

char screenBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

int running = 1;

int carPosX = SCREEN_WIDTH / 2 - 2;

const char carTexture[] = {  
    ' ','#','#','#',' ',
    'o','-','#','-','o',
    ' ','#','#','#',' ',
    ' ','#','#','#',' ',
    ' ','#','#','#',' ',
    'O','-','#','-','O',
    '#','#','#','#','#'
};

void checkKeys(char key) {
    if (key == 'a' && carPosX > 0) {
        carPosX--;
    }
    if (key == 'd' && carPosX < SCREEN_WIDTH - 6) {
        carPosX++;
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

        drawSprite(carPosX, 30, 5, 7 , screenBuffer, carTexture);

        system("clear");
        writeBuff(screenBuffer);
        
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC * 1000;
        msleep(1000/60 - time_taken);
    }

    return 0;
}
