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
#pragma comment(lib, "Winmm.lib")

//STL ���
#include <string>
#include <vector>
#include <unordered_set>
#include <map>
#include <functional>

//gdiplus ����
#include <gdiplus.h>				
#pragma comment(lib, "gdiplus.lib")	
//using namespace Gdiplus;

#pragma comment(lib, "Msimg32.lib")

//===========================================
//    ## ���ӽ����̽� ##
//===========================================
using namespace std;

#include "Defines.h"
#include "Types.h"
#include "Enums.h"

//�������� Common ��� ����
#include "CommonStruct.h"
#include "CommonFunction.h"

//�̱��� �������
#include "DataManager.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "ResourceManager.h"


//===========================================
//    ## Define ���� ##
//===========================================
#define WINNAME "FlappyBird"
#define WIN_START_X 0
#define WIN_START_Y 0
#define WIN_SIZE_WIDTH 1200
#define WIN_SIZE_HEIGHT 915
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