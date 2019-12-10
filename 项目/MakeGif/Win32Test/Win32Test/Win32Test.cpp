#include <Windows.h>
#include <tchar.h>

POINT start;
POINT end;

//��Ϣ�ص�����
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
		if (IDOK == MessageBox(hWnd, _T("��ȷ���˳���"), _T("�˳�"), MB_OKCANCEL))
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
	//Step1:ע��һ��������
	HWND hwnd; //���ڵľ��
	WNDCLASSEX wc; //������ṹ
	wc.cbSize = sizeof(WNDCLASSEX);  //���ڽṹ�Ĵ�С
	wc.style = CS_VREDRAW | CS_HREDRAW; //���ڴ�ˮƽ�ʹ�ֱ�ķ�����ˢ��
	wc.lpszMenuName = 0;	//�Ƿ���в˵�
	wc.lpszClassName = _T("win32"); //��������������,�ڴ�������ʱ��ʹ�õ�
	wc.lpfnWndProc = WinProc; //��Ϣ�ص����� ******** ����Ա��Ҫ��д����
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc); //ע�ᴰ��


	//Step2:����һ������
	hwnd = CreateWindow(
		_T("Win32"), //���ڵ�������Ҳ�������������Զ���Ĵ����������
		_T("�ҵĵ�һ��Win32����"), //���ڵı��⣨title��
		WS_OVERLAPPEDWINDOW, //����style
		500, //����λ��x����
		300, //����λ��y����
		800, //���ڿ��
		600, //���ڸ߶�
		NULL, //�����ھ��
		NULL,//LoadMenu(hInstance,MAKEINTRESOURCE(IDR_MENU1)), //�˵����
		hInstance, //ʵ�����
		NULL //��������
		);
	if (!hwnd)
	{
		return FALSE;
	}
	ShowWindow(hwnd, SW_SHOW); //��ʾ����
	UpdateWindow(hwnd); //ˢ��

	//Step3:��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 0;
}


