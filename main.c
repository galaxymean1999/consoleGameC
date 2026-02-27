#include <stdio.h>
#include <time.h>
#include "engine.h"
#include "car.h"

#define CAR_COUNT 8

char screenBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

int running = 1;

int carPosX = SCREEN_WIDTH / 2 - 2;

struct Car cars[CAR_COUNT];

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

    if (key == 'q') {
        running = 0;
    }
}

void initCars() {
    for (int i = 0; i < CAR_COUNT; i++) {
        cars[i].x = i * CAR_WIDTH + 25 + i * 2;
        cars[i].y = 0;
    }
}

int main() {
    initCars();

    system("clear");
    
    while (running == 1) {
        clock_t t = clock();
        
        if (kbhit()) {
            char key = getchar();

            checkKeys(key);
        }

        for (int i = 0; i < CAR_COUNT; i++) {
            if (cars[i].y <= SCREEN_HEIGHT - CAR_HEIGHT - 2) {
                cars[i].y += CAR_SPEED;
            }
        }

        //
        //  DRAW
        //
        clearBuff(&screenBuffer, ' ');

        // sides
        fillRect(0, 0, 20, SCREEN_HEIGHT, screenBuffer, '-');
        fillRect(SCREEN_WIDTH - 21, 0, 20, SCREEN_HEIGHT, screenBuffer, '-');

        // player car
        drawSprite(carPosX, 30, 5, 7 , screenBuffer, carTexture);

        for (int i = 0; i < CAR_COUNT; i++) {
            drawSpriteFlipped(cars[i].x, cars[i].y, CAR_WIDTH, CAR_HEIGHT, screenBuffer, carTexture);
        }
        
        writeBuff(screenBuffer);
        
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC * 1000;
        msleep(1000/FPS - time_taken);
    }

    return 0;
}
