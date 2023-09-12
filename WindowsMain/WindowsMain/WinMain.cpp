//============================================
//		## 헤더파일 선언 ##
//============================================
#include <Windows.h>

//============================================
//		## 전역변수 선언 ##
//============================================
//전역변수 선언은 변수명 앞에 _ 를 붙여서 사용한다.
HINSTANCE _hInstance;
HWND _hWnd;
char _title[250] = "Happy Windows Api";

//============================================
//		## 함수 전방 선언 ##
//============================================
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

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
	wndClass.lpszClassName = _title;									//클래스 이름
	wndClass.lpszMenuName = NULL;										//메뉴 이름
	wndClass.style = CS_HREDRAW | CS_VREDRAW;							//윈도우 스타일

	RegisterClass(&wndClass);


	//-------------------------------
	// ## 2. 윈도우 생성 ## 
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
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

		EndPaint(hWnd, &ps);
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