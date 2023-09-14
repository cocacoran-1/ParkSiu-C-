//============================================
//		## 헤더파일 선언 ##
//============================================
#include "stdafx.h"

//============================================
//		## 전역변수 선언 ##
//============================================
//전역변수 선언은 변수명 앞에 _ 를 붙여서 사용한다.
HINSTANCE _hInstance;
HWND _hWnd;
POINT _mousePos = {};

//============================================
//		## 함수 전방 선언 ##
//============================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void MultipleTable(int index, HDC hdc, RECT rc[]);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpszCmdParam, int nCmdShow)
{
	//HINSTANCE hInstance : 프로그램 인스터스 핸들
	//HINSTANCE hPrevInstance : Preview 인스턴스 핸들 (이전에 실행된 인스턴스 핸들) (게임에서는 사용안함)
	//char* lpszCmdParam : 명령행으로 입력된 프로그램 인수 (게임에서는 사용안함)
	//int nCmdShow : 프로그램이 시작될 형태 (최소화, 보통크기) (게임에서는 사용안함)

	_hInstance = hInstance;
	//-------------------------------
	// ## 1. 윈도우 등록 ## 
	//-------------------------------
	//RegisterClass : 윈도우 등록해주는 함수
	//int RegisterClassA(WNDCLASSA * lpWndClass);
	//WNDCLASS : 윈도우 구조체 (윈도우를 구성해주기 위해 쓰일 변수들)
	WNDCLASS wndClass{};

	wndClass.cbClsExtra = 0;											//클래스 여분 메모리 (게임에선 사용안함)
	wndClass.cbWndExtra = 0;											//윈도우 여분 메모리 (게임에선 사용안함)
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		//백그라운드 색
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);						//커서
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);					//아이콘
	wndClass.hInstance = _hInstance;									//인스턴스 핸들
	wndClass.lpfnWndProc = (WNDPROC)WndProc;							//윈도우 프로시저
	wndClass.lpszClassName = WIN_NAME;									//클래스 이름
	wndClass.lpszMenuName = NULL;										//메뉴 이름
	wndClass.style = CS_HREDRAW | CS_VREDRAW;							//윈도우 스타일

	RegisterClass(&wndClass);


	//-------------------------------
	// ## 2. 윈도우 생성 ## 
	//-------------------------------
	/*HWND CreateWindow(LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X,  int Y, int nWidth, int nHeight,  HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);*/
	_hWnd = CreateWindow(
		WIN_NAME							//lpClassName
		, WIN_NAME						//lpWindowsName
		, WIN_STYLE		// dwStyle
		, WIN_START_X							//x
		, WIN_START_Y							//y
		, WIN_SIZE_WIDTH							//width
		, WIN_SIZE_HEIGHT							//height
		, NULL							//부모 윈도우
		, NULL							//메뉴 핸들
		, _hInstance					//사용할 인스턴스 핸들
		, NULL							//부모가 나를생성했을때, 어떤 인자로 생성했는지
	);

	//-------------------------------
	// ## 3. 윈도우 출력 ## 
	//-------------------------------
	ShowWindow(_hWnd, nCmdShow);


	//-------------------------------
	// ## 4. 메세지 루프 ## 
	//-------------------------------
	MSG message;
	while (GetMessage(&message, nullptr, 0, 0))
	{
		RECT rc;
		GetClientRect(_hWnd, &rc);
		InvalidateRect(_hWnd, &rc, true);

		TranslateMessage(&message);
		DispatchMessage(&message);
	}



	return 0;
}
int index = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	RECT rc[9];
	
	// 3X3으로 박스 위치 
	int _xLine = 0;
	int _yLine = 0;
	for (int i = 0; i < 9; i++)
	{
		if (_xLine == 3)
		{
			_xLine = 0;
			_yLine++;
		}
		rc[i].left = 25 + _xLine * 250;
		rc[i].right = rc[i].left + 230;
		rc[i].top = 15 + _yLine * 250;
		rc[i].bottom = rc[i].top + 230;
		_xLine++;

		cout << "rc[" << i << "].left : " << rc[i].left << endl;
	}
	switch (message)
	{
		//윈도우가 생성됐을때 (초기화)
	case WM_CREATE:
		break;

		//화면을 그릴때
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		
		// 모든 박스 그리기
		for (int i = 0; i < 9; i++)
		{
			Rectangle(hdc, rc[i].left, rc[i].top, rc[i].right, rc[i].bottom);
		}
		// 1. 텍스트 그리기
		// A => 아스키 코드 약자 (멀티바이트)
		// W => 와이드 캐릭터 약자 (유니코드)
		
		// 박스에 번호, 구구단 그리기
		MultipleTable(index, hdc, &rc[index]);

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_LBUTTONDOWN:
	{
		// 누른 위치 가져오기
		for (int i = 0; i < 9; i++)
		{
			if (PtInRect(&rc[i], _mousePos))
			{
				index++;
				cout << "클릭" << endl;
				cout << "Index : " << index;
			}
		}
		
		break;
	}
	case WM_MOUSEMOVE:
	{
		_mousePos.x = GET_X_LPARAM(lParam);
		_mousePos.y = GET_Y_LPARAM(lParam);
		if (MK_RBUTTON == wParam)
		{
			cout << "X : " << _mousePos.x << endl;
			cout << "Y : " << _mousePos.y << endl;

		}

		// 화면 다시그리기 (WM_Paint로 보낸다)
		break;
	}
	//윈도우 종료 메세지를 받을때 (정상종료)
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
void MultipleTable(int index, HDC hdc, RECT rc[])
{
	int setNum = 1;

	// 박스 중앙에 숫자 출력
	for (int i = index; i < 9; i++)
	{
		int xPos = (rc[i].left + rc[i].right) / 2;
		int yPos = (rc[i].top + rc[i].bottom) / 2;
		string multipeLine = to_string(setNum);
		TextOutA(hdc, xPos, yPos, multipeLine.c_str(), multipeLine.size());
		setNum++;
	}
	// 박스 안에 구구단 출력
	int num1 = index;
	int num2 = 1;
	if (index > 0)
	{
		for (int i = 0; i < 9; i++)
		{
			cout << "AAAA :" << num1 << endl;
			string str = to_string(num1) + " X " + to_string(num2) + " = " + to_string(num1 * num2);
			TextOutA(hdc, rc[num1].left + 85, rc[num1].top + num2 * 21, str.c_str(), str.size());
			num2++;
		}
		
	}
	
}