void verLine(int x, int y1, int y2, char *screenBuff, char type);

void horLine(int x1, int x2, int y, char *screenBuff, char type);

void clearBuff(char *screenBuff, char type);

void setPixel(int x, int y, char *screenBuff, char type);

void writeBuff(char *screenBuff);

void msleep(int ms);

int kbhit(void);
