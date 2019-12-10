#include"UIlib.h"

using namespace DuiLib;

#pragma comment(lib,"DuiLib_ud.lib")

#if 0
class CDuiFramWnd : public CWindowWnd, public INotifyUI
{
public:
	// CWindowWnd��Ĵ��麯�����ڸú����б��뷵���û������崰�ڵ������ƣ�ע�ᴰ��ʱ��Ҫ�õ�
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
			// duilib.xml��Ҫ�ŵ�exeĿ¼��     
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

		//������Ϣ
		return __super::HandleMessage(uMsg, wParam, lParam);
	}

	virtual void Notify(TNotifyUI& msg)
	{
		//��Ӧ��ť�����Ϣ
		if (msg.sType == _T("click"))
		{
			MessageBox(m_hWnd, _T("��ť����"), _T("Test"), IDOK);
		}
	}
private:
	CPaintManagerUI m_PaintManager;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	// ������Դ��Ĭ��·�����˴�����Ϊ��exe��ͬһĿ¼��
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	CDuiFramWnd framWnd;
	// Cashier���ڴ������Ͻ���ʽ������
	// UI_WNDSTYLE_FRAME: duilib��װ�ĺ꣬�����ڿ��ӣ����б������������С�����رչ��ܵ�
	// WS_EX_WINDOWEDGE: Win32�Ĵ��ڷ�񣬴��б߿�
	framWnd.Create(NULL, _T("Cashier"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	//��ʾ���ڣ�������Ϣѭ��
	framWnd.ShowModal();
	return 0;
}
#endif


#include"UIlib.h"

using namespace DuiLib;

#pragma comment(lib,"DuiLib_ud.lib")

class CDuiFramWnd : public WindowImplBase
{
	virtual CDuiString GetSkinFolder() //Ƥ��·��
	{
		return _T("");
	}
	virtual CDuiString GetSkinFile()  //xml�ļ���
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
				MessageBox(NULL,_T("��С��"),_T("test"),0);
			}
			MessageBox(m_hWnd,_T("Test"),_T("sdfgsdfgsdfg"),NULL);
		}
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	// ������Դ��Ĭ��·�����˴�����Ϊ��exe��ͬһĿ¼��
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	CDuiFramWnd framWnd;
	// Cashier���ڴ������Ͻ���ʽ������
	// UI_WNDSTYLE_FRAME: duilib��װ�ĺ꣬�����ڿ��ӣ����б������������С�����رչ��ܵ�
	// WS_EX_WINDOWEDGE: Win32�Ĵ��ڷ�񣬴��б߿�
	framWnd.Create(NULL, _T("Cashier"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);

	framWnd.CenterWindow();
	//��ʾ���ڣ�������Ϣѭ��
	
	framWnd.ShowModal();
	return 0;
}


