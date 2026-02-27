#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 40

#define FPS 30

void verLine(int x, int y1, int y2, char *screenBuff, char type);

void horLine(int x1, int x2, int y, char *screenBuff, char type);

void drawRect(int x, int y, int width, int height, char *screenBuff, char type);
void fillRect(int x, int y, int width, int height, char *screenBuff, char type);

void drawSprite(int x, int y, int width, int height, char *screenBuff, char *texture);

void drawSpriteFlipped(int x, int y, int width, int height, char *screenBuff, char *texture);

void clearBuff(char *screenBuff, char type);

void setPixel(int x, int y, char *screenBuff, char type);

void writeBuff(char *screenBuff);

void msleep(int ms);

void setCursorPosition(int x,int y);

int kbhit(void);
