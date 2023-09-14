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
		, WIN_STYLE		// dwStyle
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
	
	// 3X3���� �ڽ� ��ġ 
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
		//�����찡 ���������� (�ʱ�ȭ)
	case WM_CREATE:
		break;

		//ȭ���� �׸���
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		
		// ��� �ڽ� �׸���
		for (int i = 0; i < 9; i++)
		{
			Rectangle(hdc, rc[i].left, rc[i].top, rc[i].right, rc[i].bottom);
		}
		// 1. �ؽ�Ʈ �׸���
		// A => �ƽ�Ű �ڵ� ���� (��Ƽ����Ʈ)
		// W => ���̵� ĳ���� ���� (�����ڵ�)
		
		// �ڽ��� ��ȣ, ������ �׸���
		MultipleTable(index, hdc, &rc[index]);

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_LBUTTONDOWN:
	{
		// ���� ��ġ ��������
		for (int i = 0; i < 9; i++)
		{
			if (PtInRect(&rc[i], _mousePos))
			{
				index++;
				cout << "Ŭ��" << endl;
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

		// ȭ�� �ٽñ׸��� (WM_Paint�� ������)
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
void MultipleTable(int index, HDC hdc, RECT rc[])
{
	int setNum = 1;

	// �ڽ� �߾ӿ� ���� ���
	for (int i = index; i < 9; i++)
	{
		int xPos = (rc[i].left + rc[i].right) / 2;
		int yPos = (rc[i].top + rc[i].bottom) / 2;
		string multipeLine = to_string(setNum);
		TextOutA(hdc, xPos, yPos, multipeLine.c_str(), multipeLine.size());
		setNum++;
	}
	// �ڽ� �ȿ� ������ ���
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