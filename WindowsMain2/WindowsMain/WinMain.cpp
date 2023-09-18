//============================================
//		## ������� ���� ##
//============================================
#include "stdafx.h"

//============================================
//		## �������� ���� ##
//============================================
//�������� ������ ������ �տ� _ �� �ٿ��� ����Ѵ�.
HINSTANCE _hInstance;
HWND _hWnd;
POINT _mousePos = {};

//============================================
//		## �Լ� ���� ���� ##
//============================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void MultipleTable(int index, HDC hdc, RECT rc[]);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpszCmdParam, int nCmdShow)
{
	//HINSTANCE hInstance : ���α׷� �ν��ͽ� �ڵ�
	//HINSTANCE hPrevInstance : Preview �ν��Ͻ� �ڵ� (������ ����� �ν��Ͻ� �ڵ�) (���ӿ����� ������)
	//char* lpszCmdParam : ��������� �Էµ� ���α׷� �μ� (���ӿ����� ������)
	//int nCmdShow : ���α׷��� ���۵� ���� (�ּ�ȭ, ����ũ��) (���ӿ����� ������)

	_hInstance = hInstance;
	//-------------------------------
	// ## 1. ������ ��� ## 
	//-------------------------------
	//RegisterClass : ������ ������ִ� �Լ�
	//int RegisterClassA(WNDCLASSA * lpWndClass);
	//WNDCLASS : ������ ����ü (�����츦 �������ֱ� ���� ���� ������)
	WNDCLASS wndClass{};

	wndClass.cbClsExtra = 0;											//Ŭ���� ���� �޸� (���ӿ��� ������)
	wndClass.cbWndExtra = 0;											//������ ���� �޸� (���ӿ��� ������)
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		//��׶��� ��
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);						//Ŀ��
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);					//������
	wndClass.hInstance = _hInstance;									//�ν��Ͻ� �ڵ�
	wndClass.lpfnWndProc = (WNDPROC)WndProc;							//������ ���ν���
	wndClass.lpszClassName = WIN_NAME;									//Ŭ���� �̸�
	wndClass.lpszMenuName = NULL;										//�޴� �̸�
	wndClass.style = CS_HREDRAW | CS_VREDRAW;							//������ ��Ÿ��

	RegisterClass(&wndClass);


	//-------------------------------
	// ## 2. ������ ���� ## 
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
		, NULL							//�θ� ������
		, NULL							//�޴� �ڵ�
		, _hInstance					//����� �ν��Ͻ� �ڵ�
		, NULL							//�θ� ��������������, � ���ڷ� �����ߴ���
	);

	//-------------------------------
	// ## 3. ������ ��� ## 
	//-------------------------------
	ShowWindow(_hWnd, nCmdShow);


	//-------------------------------
	// ## 4. �޼��� ���� ## 
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
		//�����찡 ���������� (�ʱ�ȭ)
	case WM_CREATE:
		srand(time(NULL));
		SetTimer(hWnd, 0, 1000 / 60, (TIMERPROC)NULL);
		BigRect1 = Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, 200, 200);
		BigRect2 = Rect::MakeCenterRect(350, 500, 200, 200);
		SmallRect = Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, 50, 50);

		break;

		//ȭ���� �׸���
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

					// ū����1 �ȿ� �������ڰ� ���� �� ū����2�� �������ڰ� �浹
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
					// ū���ڿ� ū���ڰ� �浹 ���� ��
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
					// ū����1 �ȿ� �������ڰ� ���� �� ū����2�� �������ڰ� �浹
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
					// ū���ڿ� ū���ڰ� �浹 ���� ��
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
					// ū����1 �ȿ� �������ڰ� ���� �� ū����2�� �������ڰ� �浹
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
					// ū���ڿ� ū���ڰ� �浹 ���� ��
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
					// ū����1 �ȿ� �������ڰ� ���� �� ū����2�� �������ڰ� �浹
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
					// ū���ڿ� ū���ڰ� �浹 ���� ��
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
			// ū���� 1 �ȿ��� ���� ���ڰ� ���� ��
			if (inRect1 && Collision::RectOut(BigRect1, SmallRect))
			{
				BigRect1.y -= speed;
			}
			else if (!inRect1 && Collision::RectOut(BigRect2, SmallRect))
			{
				BigRect2.y -= speed;
			}

			// ū����1 �ȿ� �������ڰ� ���� �� ū����2�� �������ڰ� �浹
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

			// ū���ڿ� ū���ڰ� �浹 ���� ��
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

			// ū���� 1 �ȿ��� ���� ���ڰ� ���� ��
			if (inRect1 && Collision::RectOut(BigRect1, SmallRect))
			{
				BigRect1.x -= speed;
			}
			else if (!inRect1 && Collision::RectOut(BigRect2, SmallRect))
			{
				BigRect2.x -= speed;
			}

			// ū����1 �ȿ� �������ڰ� ���� �� ū����2�� �������ڰ� �浹
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

			// ū���ڿ� ū���ڰ� �浹 ���� ��
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
			// ū���� 1 �ȿ��� ���� ���ڰ� ���� ��
			if (inRect1 && Collision::RectOut(BigRect1, SmallRect))
			{
				BigRect1.x += speed;
			}
			else if (!inRect1 && Collision::RectOut(BigRect2, SmallRect))
			{
				BigRect2.x += speed;
			}

			// ū����1 �ȿ� �������ڰ� ���� �� ū����2�� �������ڰ� �浹
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

			// ū���ڿ� ū���ڰ� �浹 ���� ��
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
			// ū���� 1 �ȿ��� ���� ���ڰ� ���� ��
			if (inRect1 && Collision::RectOut(BigRect1, SmallRect))
			{
				BigRect1.y += speed;
			}
			else if (!inRect1 && Collision::RectOut(BigRect2, SmallRect))
			{
				BigRect2.y += speed;
			}

			// ū����1 �ȿ� �������ڰ� ���� �� ū����2�� �������ڰ� �浹
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

			// ū���ڿ� ū���ڰ� �浹 ���� ��
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
			cout << "�浹 �Ǿ���" << endl;
		}

		break;
	}
	case WM_RBUTTONDOWN:
	{

		if (Collision::RectInRect(BigRect1, SmallRect))
		{
			cout << "�浹�ߴ�" << endl;
		}
		break;
	}
	case WM_MOUSEMOVE:
	{
		_mousePos.x = GET_X_LPARAM(lParam);
		_mousePos.y = GET_Y_LPARAM(lParam);

		break;
	}
	//������ ���� �޼����� ������ (��������)
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
