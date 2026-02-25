#include <stdio.h>
#include "engine.h"

char screen_buffer[120*40];

int main(int argc, char **argv) {
    initscrbuffer(&screen_buffer);

    verline(0, 0, 10, '#', &screen_buffer);

    drawbuffer(&screen_buffer);

    return 0;
}
