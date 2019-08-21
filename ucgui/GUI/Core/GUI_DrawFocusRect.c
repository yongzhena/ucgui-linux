/*
*********************************************************************************************************
*                                                uC/GUI
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2002, SEGGER Microcontroller Systeme GmbH
*
*              µC/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed
*              in any way. We appreciate your understanding and fairness.
*
----------------------------------------------------------------------
File        : GUI_DrawFocusRect.C
Purpose     : Implementation of GUI_DrawFocusRect
---------------------------END-OF-HEADER------------------------------
*/

#include "GUI_Protected.h"

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _DrawFocusRect
*/
static void _DrawFocusRect(const GUI_RECT* pr) {
  int i; 
  for (i = pr->x0; i <= pr->x1; i += 1) {     //for (i = pr->x0; i <= pr->x1; i += 2) {  //Áõ¾©Íþ20141111
    LCD_DrawPixel(i, pr->y0); LCD_DrawPixel(i, pr->y0+1); LCD_DrawPixel(i, pr->y0+2); LCD_DrawPixel(i, pr->y0+3); //LCD_DrawPixel(i, pr->y0);   //Áõ¾©Íþ20141111
    LCD_DrawPixel(i, pr->y1); LCD_DrawPixel(i, pr->y1-1); LCD_DrawPixel(i, pr->y1-2); LCD_DrawPixel(i, pr->y1-3); //LCD_DrawPixel(i, pr->y1);   //Áõ¾©Íþ20141111
  }
  for (i = pr->y0; i <= pr->y1; i += 1) {     //for (i = pr->y0; i <= pr->y1; i += 2) {  //Áõ¾©Íþ20141111
    LCD_DrawPixel(pr->x0, i); LCD_DrawPixel(pr->x0+1, i); LCD_DrawPixel(pr->x0+2, i); LCD_DrawPixel(pr->x0+3, i); //LCD_DrawPixel(pr->x0, i);   //Áõ¾©Íþ20141111
    LCD_DrawPixel(pr->x1, i); LCD_DrawPixel(pr->x1-1, i); LCD_DrawPixel(pr->x1-2, i); LCD_DrawPixel(pr->x1-3, i); //LCD_DrawPixel(pr->x1, i);   //Áõ¾©Íþ20121111
  }
}
/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       GUI_DrawFocusRect
*/
void GUI_DrawFocusRect(const GUI_RECT *pRect, int Dist) {
  GUI_RECT r;
  GUI__ReduceRect(&r, pRect, Dist);
  GUI_LOCK();
  #if (GUI_WINSUPPORT)
    WM_ADDORG(r.x0, r.y0);
    WM_ADDORG(r.x1, r.y1);
    WM_ITERATE_START(&r); {
  #endif
    _DrawFocusRect(&r);
  #if (GUI_WINSUPPORT)
    } WM_ITERATE_END();
  #endif
  GUI_UNLOCK();
}

/*************************** End of file ****************************/
