#include"UIlib.h"

using namespace DuiLib;

#pragma comment(lib,"DuiLib_ud.lib")

#if 0
class CDuiFramWnd : public CWindowWnd, public INotifyUI
{
public:
	// CWindowWnd类的纯虚函数，在该函数中必须返回用户所定义窗口的类名称，注册窗口时需要用到
	virtual LPCTSTR GetWindowClassName() const
	{
		return _T("DuiFramWnd");
	}
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		if (uMsg == WM_CREATE) {
			m_PaintManager.Init(m_hWnd);

			CDialogBuilder builder;
			// duilib.xml需要放到exe目录下     
			CControlUI* pRoot = builder.Create(_T("diulib.xml"), (UINT)0, NULL, &m_PaintManager);
			m_PaintManager.AttachDialog(pRoot);
			m_PaintManager.AddNotifier(this);
			return lRes;
		}
		else if (uMsg == WM_NCACTIVATE)
		{
			if (!::IsIconic(m_hWnd))
			{
				return (wParam == 0) ? TRUE : FALSE;
			}
		}
		else if (uMsg == WM_NCCALCSIZE) { return 0; }
		else if (uMsg == WM_NCPAINT) { return 0; }



		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		//其他消息
		return __super::HandleMessage(uMsg, wParam, lParam);
	}

	virtual void Notify(TNotifyUI& msg)
	{
		//响应按钮点击消息
		if (msg.sType == _T("click"))
		{
			MessageBox(m_hWnd, _T("按钮单击"), _T("Test"), IDOK);
		}
	}
private:
	CPaintManagerUI m_PaintManager;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	// 设置资源的默认路径（此处设置为和exe在同一目录）
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	CDuiFramWnd framWnd;
	// Cashier即在窗口右上角显式的名字
	// UI_WNDSTYLE_FRAME: duilib封装的宏，代表窗口可视，具有标题栏，最大化最小化，关闭功能等
	// WS_EX_WINDOWEDGE: Win32的窗口风格，带有边框
	framWnd.Create(NULL, _T("Cashier"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	//显示窗口，激活消息循环
	framWnd.ShowModal();
	return 0;
}
#endif


#include"UIlib.h"

using namespace DuiLib;

#pragma comment(lib,"DuiLib_ud.lib")

class CDuiFramWnd : public WindowImplBase
{
	virtual CDuiString GetSkinFolder() //皮肤路径
	{
		return _T("");
	}
	virtual CDuiString GetSkinFile()  //xml文件名
	{
		return _T("duilib.xml");
	}
	virtual LPCTSTR GetWindowClassName(void) const  //
	{
		return _T("DuiWnd");
	}
	virtual void Notify(TNotifyUI& msg)
	{
		
		if (msg.sType == _T("click"))
		{
			CDuiString strName = msg.pSender->GetName();
			if (strName = _T("btn_close"))
			{
				Close();
			}
			else if (strName = _T("btn_min"))
			{
				MessageBox(NULL,_T("最小化"),_T("test"),0);
			}
			MessageBox(m_hWnd,_T("Test"),_T("sdfgsdfgsdfg"),NULL);
		}
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	// 设置资源的默认路径（此处设置为和exe在同一目录）
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	CDuiFramWnd framWnd;
	// Cashier即在窗口右上角显式的名字
	// UI_WNDSTYLE_FRAME: duilib封装的宏，代表窗口可视，具有标题栏，最大化最小化，关闭功能等
	// WS_EX_WINDOWEDGE: Win32的窗口风格，带有边框
	framWnd.Create(NULL, _T("Cashier"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);

	framWnd.CenterWindow();
	//显示窗口，激活消息循环
	
	framWnd.ShowModal();
	return 0;
}


