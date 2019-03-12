#include<iostream>
using namespace std;

class CMyString
{
private:
	char* m_pData;
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);
	
};
//1.0
CMyString& CMyString::operator = (const CMyString& str)
{
	if (this == &str)
		return *this;
	delete[]m_pData;
	m_pData = NULL;
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}
//2.0
CMyString& CMyString::operator = (const CMyString& str)
{
	if (this != &str)
	{
		CMyString strTemp(str);

		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}