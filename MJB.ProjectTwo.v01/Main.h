#ifndef _MAIN_H_
#define _MAIN_H_

#include <Windows.h>
#include "Game.h"

int screenWidth = GetSystemMetrics(SM_CXSCREEN); //Gets the width of the current monitor being used
int screenHeight = GetSystemMetrics(SM_CYSCREEN); //Gets the height of the current monitor being used
int sWidth = screenWidth - 150;
int sHeight = screenHeight - 150;


bool m_running; //Set to true on initialisation then set to false on exit
bool m_fullscreen; //

const char TITLE[] = "Project 2";

HWND hWindow;
MSG msg;

LRESULT CALLBACK WndProc(HWND hWindow, UINT msg, WPARAM wParam, LPARAM lParam);

Game *game;


#endif //!_MAIN_H_