//============================================
//		## ������� ���� ##
//============================================
#include "stdafx.h"
#include "Game.h"

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
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void SetWindowSize(int x, int y, int width, int height);

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
	wndClass.lpszClassName = WINNAME;									//Ŭ���� �̸�
	wndClass.lpszMenuName = NULL;										//�޴� �̸�
	wndClass.style = CS_HREDRAW | CS_VREDRAW;							//������ ��Ÿ��

	RegisterClass(&wndClass);


	//-------------------------------
	// ## 2. ������ ���� ## 
	//-------------------------------
	/*HWND CreateWindow(LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X,  int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);*/
	_hWnd = CreateWindow(
		WINNAME							//lpClassName
		, WINNAME						//lpWindowsName
		, WS_CAPTION | WS_SYSMENU		//dwStyle
		, WIN_START_X					//x
		, WIN_START_Y					//y
		, WIN_SIZE_WIDTH				//width
		, WIN_SIZE_HEIGHT				//height
		, NULL							//�θ� ������
		, NULL							//�޴� �ڵ�
		, _hInstance					//����� �ν��Ͻ� �ڵ�
		, NULL							//�θ� ��������������, � ���ڷ� �����ߴ���
	);

	SetWindowSize(0, 0, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT);

	//-------------------------------
	// ## 3. ������ ��� ## 
	//-------------------------------
	ShowWindow(_hWnd, nCmdShow);


	//-------------------------------
	// ## 4. �޼��� ���� ## 
	//-------------------------------
	Game game;
	MSG message;
	// ������ ���ν��� => �̺�Ʈ�� ������ ��� �̺�Ʈ�� ó������ �������ִ� ����
	// GetMessage  => ������ �̺�Ʈ�� �������� �۵�
	// PeekMessage => ������ �̺�Ʈ�� �ȿ͵� �۵�
	
	game.Init();

	while (true)
	{
		if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			//���ӷ��� 
			game.Render();
			game.Update();
		}
		
	}

	return 0;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_MOUSEMOVE:
	{
		//Windows API���� ���� Ȯ���ϰ� ������
		//1��° Ȯ�� ��� : ��������� Ȯ��
		//2��° Ȯ�� ��� : �ܼ�â�� ����� Ȯ��
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

void SetWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	//���� ������ ũ�� ���� (rc�� ����ش�)
	AdjustWindowRect(&rc, WS_CAPTION | WS_SYSMENU, false);

	//rc�� ������� ������ ������ ����
	SetWindowPos(_hWnd, NULL, x, y, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);
}