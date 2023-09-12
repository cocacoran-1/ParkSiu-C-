//============================================
//		## ������� ���� ##
//============================================
#include <Windows.h>

//============================================
//		## �������� ���� ##
//============================================
//�������� ������ ������ �տ� _ �� �ٿ��� ����Ѵ�.
HINSTANCE _hInstance;
HWND _hWnd;
char _title[250] = "Happy Windows Api";

//============================================
//		## �Լ� ���� ���� ##
//============================================
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

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
	wndClass.lpszClassName = _title;									//Ŭ���� �̸�
	wndClass.lpszMenuName = NULL;										//�޴� �̸�
	wndClass.style = CS_HREDRAW | CS_VREDRAW;							//������ ��Ÿ��

	RegisterClass(&wndClass);


	//-------------------------------
	// ## 2. ������ ���� ## 
	//-------------------------------
	/*HWND CreateWindow(LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X,  int Y, int nWidth, int nHeight,  HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);*/
	_hWnd = CreateWindow(
		_title							//lpClassName
		, _title						//lpWindowsName
		, WS_CAPTION | WS_SYSMENU		// dwStyle
		, 50							//x
		, 50							//y
		, 700							//width
		, 800							//height
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
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

		EndPaint(hWnd, &ps);
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