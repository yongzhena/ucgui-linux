#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/mman.h>
#include <linux/fb.h>

static unsigned char*  npu8_fbmem;
static int             ns32_fb;
static unsigned int    nu32_screensize;

static void* _fb_mmap(int fd, unsigned int screensize)
{
    caddr_t fbmem;

    if ((fbmem = mmap(0, screensize, PROT_READ | PROT_WRITE,
                      MAP_SHARED, fd, 0)) == MAP_FAILED) {
        perror(__func__);
        return (void *) (-1);
    }

    return fbmem;
}

static int _fb_munmap(void *start, size_t length)
{
    return (munmap(start, length));
}

static int _fb_stat(int fd, unsigned int *width, unsigned int *height, unsigned int *depth)
{
    //struct fb_fix_screeninfo fb_finfo;
    struct fb_var_screeninfo fb_vinfo;

    //if (ioctl(fd, FBIOGET_FSCREENINFO, &fb_finfo)) {
    //    perror(__func__);
    //    return -1;
    //}

    if (ioctl(fd, FBIOGET_VSCREENINFO, &fb_vinfo)) {
        perror(__func__);
        return -1;
    }

    *width  = fb_vinfo.xres;
    *height = fb_vinfo.yres;
    *depth  = fb_vinfo.bits_per_pixel;

    return 0;
}

int fb_init(void)
{ 
  unsigned int  fbw, fbh, fbd;
  
  ns32_fb = open("/dev/fb0", O_RDWR);
  if(ns32_fb<0){
    printf("can not open fb0\n");
    return -1;
  }
  if( _fb_stat(ns32_fb, &fbw, &fbh, &fbd) < 0 ) return -1;
  printf("%d, %d, %d\n", fbw, fbh, fbd);
  nu32_screensize = fbw * fbh * fbd / 8;
  npu8_fbmem = _fb_mmap(ns32_fb, nu32_screensize);
  return 0;
}

void fb_deinit(void)
{ 
  close(ns32_fb);
  _fb_munmap(npu8_fbmem, nu32_screensize);
}

int fb_setpixel(int width, int height, int x, int y, unsigned short color)
{
    if ((x > width) || (y > height))
        return -1;

    unsigned short *dst = ((unsigned short *)npu8_fbmem + y * width + x);

    *dst = color;
    return 0;
}

unsigned short fb_readpixel(int width, int height, int x, int y)
{
  if ((x > width) || (y > height)) return -1;
  unsigned short *dst = ((unsigned short *)npu8_fbmem + y * width + x);
  return *dst;
}

