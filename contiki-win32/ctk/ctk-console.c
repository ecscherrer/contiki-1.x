/*
 * Copyright (c) 2004, Adam Dunkels.
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution. 
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.  
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
 *
 * This file is part of the Contiki desktop environment
 *
 * $Id: ctk-console.c,v 1.2 2004/07/31 14:55:17 oliverschmidt Exp $
 *
 */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#include "ctk-console.h"

static HANDLE stdouthandle;

static unsigned char       saved_foreground;
static unsigned char       saved_background;
static char                saved_title[1024];
static DWORD               saved_consolemode;
static CONSOLE_CURSOR_INFO saved_cursorinfo;

static unsigned char reversed;
static unsigned char foreground;
static unsigned char background;

/*-----------------------------------------------------------------------------------*/
static BOOL WINAPI
consolehandler(DWORD event)
{
  if(event == CTRL_C_EVENT ||
     event == CTRL_BREAK_EVENT) {
    console_exit();
  }

  return FALSE;
}
/*-----------------------------------------------------------------------------------*/
void
console_init(void)
{
  CONSOLE_SCREEN_BUFFER_INFO consoleinfo;
  CONSOLE_CURSOR_INFO cursorinfo = {1, FALSE};

  stdouthandle = GetStdHandle(STD_OUTPUT_HANDLE);

  GetConsoleScreenBufferInfo(stdouthandle, &consoleinfo);
  saved_foreground = consoleinfo.wAttributes % 0x10;
  saved_background = consoleinfo.wAttributes / 0x10;

  GetConsoleTitle(saved_title, sizeof(saved_title));
  SetConsoleTitle("Contiki");

  GetConsoleMode(stdouthandle, &saved_consolemode);
  SetConsoleMode(stdouthandle, ENABLE_PROCESSED_OUTPUT);

  GetConsoleCursorInfo(stdouthandle, &saved_cursorinfo);
  SetConsoleCursorInfo(stdouthandle, &cursorinfo);

  SetConsoleCtrlHandler(consolehandler, TRUE);
}
/*-----------------------------------------------------------------------------------*/
void
console_exit(void)
{
  revers(0);
  textcolor(saved_foreground);
  bgcolor(saved_background);
  clrscr();
  gotoxy(0, 0);

  SetConsoleTitle(saved_title);
  SetConsoleMode(stdouthandle, saved_consolemode);
  SetConsoleCursorInfo(stdouthandle, &saved_cursorinfo);
}
/*-----------------------------------------------------------------------------------*/
static void
setcolor(void)
{
  SetConsoleTextAttribute(stdouthandle, reversed? background + foreground * 0x10 
					        : foreground + background * 0x10);
}
/*-----------------------------------------------------------------------------------*/
unsigned char
wherex(void)
{
  CONSOLE_SCREEN_BUFFER_INFO consoleinfo;

  GetConsoleScreenBufferInfo(stdouthandle, &consoleinfo);
  return consoleinfo.dwCursorPosition.X;
}
/*-----------------------------------------------------------------------------------*/
unsigned char
wherey(void)
{
  CONSOLE_SCREEN_BUFFER_INFO consoleinfo;

  GetConsoleScreenBufferInfo(stdouthandle, &consoleinfo);
  return consoleinfo.dwCursorPosition.Y;
}
/*-----------------------------------------------------------------------------------*/
void
clrscr(void)
{
  unsigned char i, width, height;

  screensize(&width, &height);
  for(i = 0; i < height; ++i) {
    cclearxy(0, i, width);
  }
}
/*-----------------------------------------------------------------------------------*/
void
revers(unsigned char c)
{
  reversed = c;
  setcolor();
}
/*-----------------------------------------------------------------------------------*/
void
cclear(unsigned char length)
{
  int i;
  for(i = 0; i < length; ++i) {
    putch(' ');
  }  
}
/*-----------------------------------------------------------------------------------*/
void
chline(unsigned char length)
{
  int i;
  for(i = 0; i < length; ++i) {
    putch(0xC4);
  }
}
/*-----------------------------------------------------------------------------------*/
void
cvline(unsigned char length)
{
  int i;
  for(i = 0; i < length; ++i) {
    putch(0xB3);
    gotoxy(wherex() - 1, wherey() + 1);
  }
}
/*-----------------------------------------------------------------------------------*/
void
gotoxy(unsigned char x, unsigned char y)
{
  COORD coord = {x, y};

  SetConsoleCursorPosition(stdouthandle, coord);
}
/*-----------------------------------------------------------------------------------*/
void
cclearxy(unsigned char x, unsigned char y, unsigned char length)
{
  gotoxy(x, y);
  cclear(length);
}
/*-----------------------------------------------------------------------------------*/
void
chlinexy(unsigned char x, unsigned char y, unsigned char length)
{
  gotoxy(x, y);
  chline(length);
}
/*-----------------------------------------------------------------------------------*/
void
cvlinexy(unsigned char x, unsigned char y, unsigned char length)
{
  gotoxy(x, y);
  cvline(length);
}
/*-----------------------------------------------------------------------------------*/
void
cputsxy(unsigned char x, unsigned char y, char *str)
{
  gotoxy(x, y);
  cputs(str);
}
/*-----------------------------------------------------------------------------------*/
void
cputcxy(unsigned char x, unsigned char y, char c)
{
  gotoxy(x, y);
  putch(c);
}
/*-----------------------------------------------------------------------------------*/
void
textcolor(unsigned char c)
{
  foreground = c;
  setcolor();
}
/*-----------------------------------------------------------------------------------*/
void
bgcolor(unsigned char c)
{
  background = c;
  setcolor();
}
/*-----------------------------------------------------------------------------------*/
void
bordercolor(unsigned char c)
{
}
/*-----------------------------------------------------------------------------------*/
void
screensize(unsigned char *x, unsigned char *y)
{
  CONSOLE_SCREEN_BUFFER_INFO consoleinfo;

  GetConsoleScreenBufferInfo(stdouthandle, &consoleinfo);
  *x = consoleinfo.dwMaximumWindowSize.X;
  *y = consoleinfo.dwMaximumWindowSize.Y;
}
/*-----------------------------------------------------------------------------------*/
