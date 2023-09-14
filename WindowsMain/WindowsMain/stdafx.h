#pragma once
// ���� ���������, ���� ������� �ʴ� ������� ���ԵǴ� ���
// ������ ��ũ ������� �� ��� ���Ͽ� ������ ��

//============================================
//		## ������� ���� ##
//============================================

#include <Windows.h>
#include <windowsx.h>
// C++ ���� �Լ�
#include <iostream>
// WinMAin���� ������ ��, ���� �ý������� Console�� ����ϰڴ�
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
// STL ���
#include <string>
#include <vector>

//============================================
//		## ���� �����̽� ##
//============================================
using namespace std;

//============================================
//		## Defin ���� ##
//============================================
#define WIN_NAME "SBS_ACADEMY;"
#define WIN_START_X 500
#define WIN_START_Y	100
#define WIN_SIZE_WIDTH	800
#define WIN_SIZE_HEIGHT	800
#define WIN_STYLE (WS_CAPTION | WS_SYSMENU)

#define SAFE_DELETE(p) {if((p)){delete (p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p) {if((p)){delete[] (p); (p) = NULL;}}

//============================================
//		## ���� ���� ##
//============================================
// extern�� �ٿ��� �ٸ� cpp ���Ͽ����� ��� ���� �ϴ�
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _mousePos;