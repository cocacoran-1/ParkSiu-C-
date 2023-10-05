#pragma once
// ���� ���������, ���ֺ������ �ʴ� ������� ���ԵǴ� ���
// �����ӿ�ũ ������� �� ������Ͽ� ������ ��.

//===========================================
//    ## ��� ���� ���� ##
//===========================================

#include <Windows.h>
#include <windowsx.h>

//C++ ���� �Լ�
#include <iostream>
#include <algorithm>
//WinMain���� �����Ҷ�, ����ý������� Console�� ���ڴ�.
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 

//STL ���
#include <string>
#include <vector>
#include <format>
#include <unordered_set>

//gdipuls ����
#include <gdiplus.h>				//����
#pragma comment(lib,"gdiplus.lib")	//����
//using namespace Gdiplus;

#include "Types.h"
#include "Enums.h"
#include "Defines.h"

//�������� Common ��� ����
#include "CommonStruct.h"
#include "CommonFunction.h"

//�̱��� �������
#include "KeyManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "CollisionManager.h"

//===========================================
//    ## ���ӽ����̽� ##
//===========================================
using namespace std;

//===========================================
//    ## Define ���� ##
//===========================================
#define WINNAME "SBS_ACADEMY"
#define WIN_START_X 0
#define WIN_START_Y 0
#define WIN_SIZE_WIDTH 1310
#define WIN_SIZE_HEIGHT 655
#define WIN_STYLE (WS_CAPTION | WS_SYSMENU)

#define SAFE_DELETE(p) {if((p)) delete (p); (p) = NULL;}
#define SAFE_DELETE_ARRAY(p) {if((p)) delete[] (p); (p) = NULL;}

//===========================================
//    ## ���� ���� ## 
//===========================================
//extern�� �ٿ��� �ٸ� cpp���Ͽ����� ��밡���ϴ�.
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _mousePos;