#include <sys/types.h>

int            fb_init(void);
void           fb_deinit(void);
int            fb_setpixel(int width, int height, int x, int y, unsigned short color);
unsigned short fb_readpixel(int width, int height, int x, int y);
