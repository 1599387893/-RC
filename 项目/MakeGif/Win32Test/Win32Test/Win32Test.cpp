#include <Windows.h>
#include <tchar.h>

POINT start;
POINT end;

//消息回调函数
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//HDC hdc;
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		//MessageBox(NULL,_T("LBUTTONDOWN"),_T("Test"),IDOK);
		start.x = HIWORD(lParam);
		start.y = LOWORD(lParam);
		return 0;
	}
	case WM_LBUTTONUP:
	{
		end.x = HIWORD(lParam);
		end.y = LOWORD(lParam);

		HDC hdc = GetDC(hWnd);

		/*MoveToEx(hdc, start.x, start.y, NULL);
		LineTo(hdc, end.x, end.y);
		ReleaseDC(hWnd, hdc);*/

		Rectangle(hdc,start.x,start.y ,end.x,end.y);
		ReleaseDC(hWnd, hdc); 

		start = end;
		return 0;
	}

	case WM_CLOSE:
		if (IDOK == MessageBox(hWnd, _T("你确定退出？"), _T("退出"), MB_OKCANCEL))
		{
			DestroyWindow(hWnd);
			return 0;
		}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//Step1:注册一个窗口类
	HWND hwnd; //窗口的句柄
	WNDCLASSEX wc; //窗口类结构
	wc.cbSize = sizeof(WNDCLASSEX);  //窗口结构的大小
	wc.style = CS_VREDRAW | CS_HREDRAW; //窗口从水平和垂直的方向上刷新
	wc.lpszMenuName = 0;	//是否具有菜单
	wc.lpszClassName = _T("win32"); //窗口类对象的名字,在创建窗口时会使用到
	wc.lpfnWndProc = WinProc; //消息回调函数 ******** 程序员主要编写部分
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc); //注册窗口


	//Step2:创建一个窗口
	hwnd = CreateWindow(
		_T("Win32"), //窗口的类名，也就是上面我们自定义的窗口类的名字
		_T("我的第一个Win32程序"), //窗口的标题（title）
		WS_OVERLAPPEDWINDOW, //窗口style
		500, //窗口位置x坐标
		300, //窗口位置y坐标
		800, //窗口宽度
		600, //窗口高度
		NULL, //父窗口句柄
		NULL,//LoadMenu(hInstance,MAKEINTRESOURCE(IDR_MENU1)), //菜单句柄
		hInstance, //实例句柄
		NULL //创建数据
		);
	if (!hwnd)
	{
		return FALSE;
	}
	ShowWindow(hwnd, SW_SHOW); //显示窗口
	UpdateWindow(hwnd); //刷新

	//Step3:消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 0;
}


