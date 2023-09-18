#pragma once
// 자주 사용하지만, 자주 변경되지 않는 내용들이 포함되는 헤더
// 프레임 워크 내용들은 이 헤더 파일에 정의할 것

//============================================
//		## 헤더파일 정의 ##
//============================================

#include <Windows.h>
#include <windowsx.h>
#include <time.h>
// C++ 관련 함수
#include <iostream>
#include <algorithm>
// WinMAin으로 시작할 때, 서브 시스템으로 Console을 사용하겠다
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// STL 헤더
#include <string>
#include <vector>

//내가 만든 헤더 파일
#include "CommonStruct.h"
#include "CommonFunction.h"


//============================================
//		## 네임 스페이스 ##
//============================================
using namespace std;


//============================================
//		## Defin 정의 ##
//============================================
#define WIN_NAME "SBS_ACADEMY;"
#define WIN_START_X 500
#define WIN_START_Y	100
#define WIN_SIZE_WIDTH	1240
#define WIN_SIZE_HEIGHT	1024
#define WIN_STYLE (WS_CAPTION | WS_SYSMENU)

#define SAFE_DELETE(p) {if((p)){delete (p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p) {if((p)){delete[] (p); (p) = NULL;}}

//============================================
//		## 전역 변수 ##
//============================================
// extern을 붙여야 다른 cpp 파일에서도 사용 가능 하다
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _mousePos;