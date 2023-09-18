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
		, WS_CAPTION | WS_SYSMENU	// dwStyle
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

		TranslateMessage(&message);
		DispatchMessage(&message);
	}



	return 0;
}

int index = 0;
vector<RECT>rcVec;

CenterRect BigRect1;
CenterRect BigRect2;
CenterRect SmallRect;
bool inRect1 = true;
POINT goalPoint = { -1, -1 };


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{


	switch (message)
	{
		//윈도우가 생성됐을때 (초기화)
	case WM_CREATE:
		srand(time(NULL));
		SetTimer(hWnd, 0, 1000 / 60, (TIMERPROC)NULL);
		BigRect1 = Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, 200, 200);
		BigRect2 = Rect::MakeCenterRect(350, 500, 200, 200);
		SmallRect = Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, 50, 50);

		break;

		//화면을 그릴때
	case WM_TIMER:
	{
		switch (wParam)
		{
		case 0:
			if (false == (goalPoint.x == -1 && goalPoint.y == -1))
			{
				if (goalPoint.x < SmallRect.x)
				{
					int gap = SmallRect.x - goalPoint.x;
					int movePoint = min(gap, 5);
					SmallRect.x -= movePoint;
					if (inRect1 && Collision::RectOut(BigRect1, SmallRect))
					{
						BigRect1.x -= movePoint;
					}
					else if (!inRect1 && Collision::RectOut(BigRect2, SmallRect))
					{
						BigRect2.x -= movePoint;
					}

					// 큰상자1 안에 작은상자가 있을 때 큰상자2와 작은상자가 충돌
					if (inRect1 && Collision::RectInRect(BigRect2, SmallRect))
					{
						SmallRect.x -= movePoint;
						SmallRect.x = BigRect2.x;
						SmallRect.y = BigRect2.y;
						BigRect2.x -= movePoint;
						inRect1 = false;
					}
					else if (!inRect1 && Collision::RectInRect(BigRect1, SmallRect))
					{
						SmallRect.x -= movePoint;
						SmallRect.x = BigRect1.x;
						SmallRect.y = BigRect1.y;
						BigRect1.x -= movePoint;
						inRect1 = true;
					}
					// 큰상자와 큰상자가 충돌 했을 때
					if (Collision::RectInRect(BigRect1, BigRect2))
					{
						if (inRect1)
						{
							BigRect2.x -= movePoint;
						}
						else
						{
							BigRect1.x -= movePoint;
						}
					}
				}
				else if (goalPoint.x > SmallRect.x)
				{
					int gap = goalPoint.x - SmallRect.x;
					int movePoint = min(gap, 5);
					SmallRect.x += movePoint;
					if (inRect1 && Collision::RectOut(BigRect1, SmallRect))
					{
						BigRect1.x += movePoint;
					}
					else if (!inRect1 && Collision::RectOut(BigRect2, SmallRect))
					{
						BigRect2.x += movePoint;
					}
					// 큰상자1 안에 작은상자가 있을 때 큰상자2와 작은상자가 충돌
					if (inRect1 && Collision::RectInRect(BigRect2, SmallRect))
					{
						SmallRect.x += movePoint;
						SmallRect.x = BigRect2.x;
						SmallRect.y = BigRect2.y;
						BigRect2.x += movePoint;

						inRect1 = false;
					}
					else if (!inRect1 && Collision::RectInRect(BigRect1, SmallRect))
					{
						SmallRect.x += movePoint;
						SmallRect.x = BigRect1.x;
						SmallRect.y = BigRect1.y;
						BigRect1.x += movePoint;
						inRect1 = true;
					}
					// 큰상자와 큰상자가 충돌 했을 때
					if (Collision::RectInRect(BigRect1, BigRect2))
					{
						if (inRect1)
						{
							BigRect2.x += movePoint;
						}
						else
						{
							BigRect1.x += movePoint;
						}
					}	
				}

				if (goalPoint.y < SmallRect.y)
				{
					int gap = SmallRect.y - goalPoint.y;
					int movePoint = min(gap, 5);
					SmallRect.y -= movePoint;
					if (inRect1 && Collision::RectOut(BigRect1, SmallRect))
					{
						BigRect1.y -= movePoint;
					}
					else if (!inRect1 && Collision::RectOut(BigRect2, SmallRect))
					{
						BigRect2.y -= movePoint;
					}
					// 큰상자1 안에 작은상자가 있을 때 큰상자2와 작은상자가 충돌
					if (inRect1 && Collision::RectInRect(BigRect2, SmallRect))
					{
						SmallRect.y -= movePoint;
						SmallRect.x = BigRect2.x;
						SmallRect.y = BigRect2.y;
						BigRect2.y -= movePoint;

						inRect1 = false;
					}
					else if (!inRect1 && Collision::RectInRect(BigRect1, SmallRect))
					{
						SmallRect.y -= movePoint;
						SmallRect.x = BigRect1.x;
						SmallRect.y = BigRect1.y;
						BigRect1.y -= movePoint;

						inRect1 = true;
					}
					// 큰상자와 큰상자가 충돌 했을 때
					if (Collision::RectInRect(BigRect1, BigRect2))
					{
						if (inRect1)
						{
							BigRect2.y -= movePoint;
						}
						else
						{
							BigRect1.y -= movePoint;
						}
					}
				}
				else if (goalPoint.y > SmallRect.y)
				{
					int gap = goalPoint.y - SmallRect.y;
					int movePoint = min(gap, 5);
					SmallRect.y += movePoint;
					if (inRect1 && Collision::RectOut(BigRect1, SmallRect))
					{
						BigRect1.y += movePoint;
					}
					else if (!inRect1 && Collision::RectOut(BigRect2, SmallRect))
					{
						BigRect2.y += movePoint;
					}
					// 큰상자1 안에 작은상자가 있을 때 큰상자2와 작은상자가 충돌
					if (inRect1 && Collision::RectInRect(BigRect2, SmallRect))
					{
						SmallRect.y += movePoint;
						SmallRect.x = BigRect2.x;
						SmallRect.y = BigRect2.y;
						BigRect2.y += movePoint;

						inRect1 = false;
					}
					else if (!inRect1 && Collision::RectInRect(BigRect1, SmallRect))
					{
						SmallRect.y += movePoint;
						SmallRect.x = BigRect1.x;
						SmallRect.y = BigRect1.y;
						BigRect1.y += movePoint;

						inRect1 = true;
					}
					// 큰상자와 큰상자가 충돌 했을 때
					if (Collision::RectInRect(BigRect1, BigRect2))
					{
						if (inRect1)
						{
							BigRect2.y += movePoint;
						}
						else
						{
							BigRect1.y += movePoint;
						}
					}
				}
			}
			RECT rc;
			GetClientRect(_hWnd, &rc);
			InvalidateRect(_hWnd, &rc, true);

			return 0;
		default:
			break;
		}
	}
	case WM_KEYDOWN:
	{
		int speed = 10;


		switch (wParam)
		{
		case VK_UP:
			SmallRect.y -= speed;
			// 큰상자 1 안에서 작은 상자가 나갈 때
			if (inRect1 && Collision::RectOut(BigRect1, SmallRect))
			{
				BigRect1.y -= speed;
			}
			else if (!inRect1 && Collision::RectOut(BigRect2, SmallRect))
			{
				BigRect2.y -= speed;
			}

			// 큰상자1 안에 작은상자가 있을 때 큰상자2와 작은상자가 충돌
			if (inRect1 && Collision::RectInRect(BigRect2, SmallRect))
			{
				SmallRect.x = BigRect2.x;
				SmallRect.y = BigRect2.y;
				BigRect2.y -= speed;

				inRect1 = false;
			}
			else if (!inRect1 && Collision::RectInRect(BigRect1, SmallRect))
			{
				SmallRect.x = BigRect1.x;
				SmallRect.y = BigRect1.y;
				BigRect1.y -= speed;

				inRect1 = true;
			}

			// 큰상자와 큰상자가 충돌 했을 때
			if (Collision::RectInRect(BigRect1, BigRect2))
			{
				if (inRect1)
				{
					BigRect2.y -= speed;
				}
				else
				{
					BigRect1.y -= speed;
				}
			}


			break;
		case VK_LEFT:
			SmallRect.x -= speed;

			// 큰상자 1 안에서 작은 상자가 나갈 때
			if (inRect1 && Collision::RectOut(BigRect1, SmallRect))
			{
				BigRect1.x -= speed;
			}
			else if (!inRect1 && Collision::RectOut(BigRect2, SmallRect))
			{
				BigRect2.x -= speed;
			}

			// 큰상자1 안에 작은상자가 있을 때 큰상자2와 작은상자가 충돌
			if (inRect1 && Collision::RectInRect(BigRect2, SmallRect))
			{
				SmallRect.x = BigRect2.x;
				SmallRect.y = BigRect2.y;
				BigRect2.x -= speed;

				inRect1 = false;
			}
			else if (!inRect1 && Collision::RectInRect(BigRect1, SmallRect))
			{
				SmallRect.x = BigRect1.x;
				SmallRect.y = BigRect1.y;
				BigRect1.x -= speed;

				inRect1 = true;
			}

			// 큰상자와 큰상자가 충돌 했을 때
			if (Collision::RectInRect(BigRect1, BigRect2))
			{
				if (inRect1)
				{
					BigRect2.x -= speed;
				}
				else
				{
					BigRect1.x -= speed;
				}
			}


			break;
		case VK_RIGHT:
			SmallRect.x += speed;
			// 큰상자 1 안에서 작은 상자가 나갈 때
			if (inRect1 && Collision::RectOut(BigRect1, SmallRect))
			{
				BigRect1.x += speed;
			}
			else if (!inRect1 && Collision::RectOut(BigRect2, SmallRect))
			{
				BigRect2.x += speed;
			}

			// 큰상자1 안에 작은상자가 있을 때 큰상자2와 작은상자가 충돌
			if (inRect1 && Collision::RectInRect(BigRect2, SmallRect))
			{
				SmallRect.x = BigRect2.x;
				SmallRect.y = BigRect2.y;
				BigRect2.x += speed;

				inRect1 = false;
			}
			else if (!inRect1 && Collision::RectInRect(BigRect1, SmallRect))
			{
				SmallRect.x = BigRect1.x;
				SmallRect.y = BigRect1.y;
				BigRect1.x += speed;

				inRect1 = true;
			}

			// 큰상자와 큰상자가 충돌 했을 때
			if (Collision::RectInRect(BigRect1, BigRect2))
			{
				if (inRect1)
				{
					BigRect2.x += speed;
				}
				else
				{
					BigRect1.x += speed;
				}
			}
			break;
		case VK_DOWN:
			SmallRect.y += speed;
			// 큰상자 1 안에서 작은 상자가 나갈 때
			if (inRect1 && Collision::RectOut(BigRect1, SmallRect))
			{
				BigRect1.y += speed;
			}
			else if (!inRect1 && Collision::RectOut(BigRect2, SmallRect))
			{
				BigRect2.y += speed;
			}

			// 큰상자1 안에 작은상자가 있을 때 큰상자2와 작은상자가 충돌
			if (inRect1 && Collision::RectInRect(BigRect2, SmallRect))
			{
				SmallRect.x = BigRect2.x;
				SmallRect.y = BigRect2.y;
				BigRect2.y += speed;

				inRect1 = false;
			}
			else if (!inRect1 && Collision::RectInRect(BigRect1, SmallRect))
			{
				SmallRect.x = BigRect1.x;
				SmallRect.y = BigRect1.y;
				BigRect1.y += speed;

				inRect1 = true;
			}

			// 큰상자와 큰상자가 충돌 했을 때
			if (Collision::RectInRect(BigRect1, BigRect2))
			{
				if (inRect1)
				{
					BigRect2.y += speed;
				}
				else
				{
					BigRect1.y += speed;
				}
			}


			break;
		default:
			break;
		}

	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);


		Draw::Rectangle(hdc, BigRect1);
		Draw::Rectangle(hdc, BigRect2);
		Draw::Rectangle(hdc, SmallRect);

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_LBUTTONDOWN:
	{
		goalPoint = _mousePos;

		if (Collision::PtInRect(BigRect1, _mousePos))
		{
			cout << "충돌 되었다" << endl;
		}

		break;
	}
	case WM_RBUTTONDOWN:
	{

		if (Collision::RectInRect(BigRect1, SmallRect))
		{
			cout << "충돌했다" << endl;
		}
		break;
	}
	case WM_MOUSEMOVE:
	{
		_mousePos.x = GET_X_LPARAM(lParam);
		_mousePos.y = GET_Y_LPARAM(lParam);

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
