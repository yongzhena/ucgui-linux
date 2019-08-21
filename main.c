
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> 
#include <limits.h>
#include "GUI.h"
extern const GUI_FONT GUI_FontHZ12;
extern const GUI_FONT GUI_FontHZ16;
extern const GUI_FONT GUI_FontHZ24;
extern unsigned char* getpng( int * dlen);

int dlen = 0;
unsigned char* pdata;

size_t GetFilePathName( char* dir,char* name, size_t len)  
{  
        char* path_end;  
        if(readlink("/proc/self/exe", dir,len) <=0)  
                return -1;  
        path_end = strrchr(dir,  '/');  
        if(path_end == NULL)  
                return -1;  
        ++path_end;  
        strcpy(name, path_end);  
        *path_end = '\0';  
        return (size_t)(path_end - dir);  
}  
void ShowJpeg(char* filename)
{

}
/*************************** End of file ****************************/
int main(int argc, char* argv[])
{ 
   char c;
   char dir[100];
   char name[100]; 
  //int i = 0;

  printf("is ucgui-linux test111aaaaaaaaaaaaaaaaaaaaaaa!\n");

  GUI_Init();
  GUI_SetBkColor(GUI_BLUE);
  GUI_Clear();
  GUI_SetColor(GUI_WHITE);
  GUI_SetTextAlign(GUI_TA_HCENTER);
  GUI_SetFont(&GUI_Font16B_ASCII);
  GUI_DispStringAt("hello world, ucgui-linux111aaaaaaaaaaaa",240,100);
  //GUI_GIF_Draw();
  GUI_DrawCircle(100,100,50);//
  //GUI_SetFont(&GUI_FontHZ12);
  //GUI_DispStringAt("\C4\E3\BAð\A1\A3\AC\CA\C0\BD硣\D6\D0\CE\C4\CF\D4ʾ12X12 GB2312",0,150);
  GetFilePathName(dir,name,100);
  printf("dir is %s,\nname is %s\n",dir,name);
 // for(i = 0;i <7;i++)
  
	 GUI_SetBkColor(GUI_BLUE);
     GUI_Clear();
     GUI_DispStringAt("hello world, GUI_BLUE",240,100);
     while ((c = getchar()) != '\n');
     GUI_SetBkColor(GUI_RED);
     GUI_Clear();
     GUI_DispStringAt("hello world, GUI_RED",240,100);
     while ((c = getchar()) != '\n');
    GUI_SetBkColor(GUI_GREEN);
     GUI_Clear();
     GUI_DispStringAt("hello world, GUI_GREEN",240,100);
     while ((c = getchar()) != '\n');

  pdata = getpng(&dlen);
  GUI_PNG_Draw(pdata,dlen,0,0);
  
     

  printf("system pause\n");
  //GUI_JPEG_Draw(ac1,sizeof(ac1),0,0);
  while ((c = getchar()) != '\n');
  system("pause");
  return 0;
}
