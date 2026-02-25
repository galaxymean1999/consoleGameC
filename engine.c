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
        screenBuff[x + y * 120] = type;
    }
}

void horLine(int x1, int x2, int y, char *screenBuff, char type) {
    for (int x = x1; x < x2; x++) {
        screenBuff[x + y * 120] = type;
    }
}

void clearBuff(char *screenBuff, char type) {
    for (int i = 0; i < 120 * 40; i++) {
        screenBuff[i] = type;
    }
}

void setPixel(int x, int y, char *screenBuff, char type) {
    screenBuff[x + y * 120] = type;
}

void writeBuff(char *screenBuff) {
    for (int line = 0; line < 40; line++) {
        for (int x = 0; x < 120; x++) {
            printf("%c", screenBuff[line * 120 + x]);
        }

        printf("\n");
    }
}

void msleep(int ms) {
    usleep(ms * 1000);
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
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}