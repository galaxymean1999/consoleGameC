#include "engine.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <fcntl.h>

void verLine(int x, int y1, int y2, char *screenBuff, char type) {
    for (int y = y1; y < y2; y++) {
        screenBuff[x + y * SCREEN_WIDTH] = type;
    }
}

void horLine(int x1, int x2, int y, char *screenBuff, char type) {
    for (int x = x1; x < x2; x++) {
        screenBuff[x + y * SCREEN_WIDTH] = type;
    }
}

void clearBuff(char *screenBuff, char type) {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        screenBuff[i] = type;
    }
}

void setPixel(int x, int y, char *screenBuff, char type) {
    screenBuff[x + y * SCREEN_WIDTH] = type;
}

void writeBuff(char *screenBuff) {
    setCursorPosition(0, 0);

    for (int line = 0; line < 40; line++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            printf("%c", screenBuff[line * SCREEN_WIDTH + x]);
        }

        printf("\n");
    }
}

void msleep(int ms) {
    usleep(ms * 1000);
}

void drawRect(int x, int y, int width, int height, char *screenBuff, char type) {
    horLine(x, x + width -1, y, screenBuff, type);
    horLine(x, x + width, y + height -1, screenBuff, type);

    verLine(x, y, y + height -1, screenBuff, type);
    verLine(x + width -1, y, y + height -1, screenBuff, type);
}

void fillRect(int x, int y, int width, int height, char *screenBuff, char type) {
    for (int yPos = y; yPos < y + height; yPos++) {
        horLine(x, x + width, yPos, screenBuff, type);
    }
}

void drawSprite(int x, int y, int width, int height, char *screenBuff, char *texture) {
    for (int currentY = 0; currentY < height; currentY++) {
        for (int currentX = 0; currentX < width; currentX++) {
            if (texture[currentX + currentY * width] == ' ') {
                continue;
            }
            screenBuff[x + currentX + (y + currentY) * SCREEN_WIDTH] = texture[currentX + currentY * width];
        }
    }
}

void drawSpriteFlipped(int x, int y, int width, int height, char *screenBuff, char *texture) {
    for (int currentY = 0; currentY < height; currentY++) {
        for (int currentX = 0; currentX < width; currentX++) {
            if (texture[currentX + currentY * width] == ' ') {
                continue;
            }
            screenBuff[x + currentX + (y + currentY) * SCREEN_WIDTH] = texture[(height - 1) * (width) + currentX - currentY * width];
        }
    }
}

void setCursorPosition(int x,int y) {
    printf("%c[%d;%df",0x1B,y,x);
}

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
 
    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
 
    return 0;
}