//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//
////��һ��ģ�ⷽ�������(��ͳ)
//namespace bit1
//{
//	class string
//	{
//	public:
//		//���캯��
//		string(const char* s = "") 
//		{
//			if (nullptr == s)
//				s = "";
//
//			_str = new char[strlen(s) + 1];
//			strcpy(_str, s);
//		}
//		//�������캯��
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//		//��ֵ��������غ���
//		string& operator=(const string& s)
//		{
//			if (&s != this)
//			{
//				char* ptr = new char[strlen(s._str)+1];
//				strcpy(ptr, s._str);
//
//				delete[] _str;
//				_str = ptr;
//			}
//			return *this;
//		}
//		//��������
//		~string()
//		{
//			if (_str)
//			{
//				delete[] _str;
//			}
//		}
//	private:
//		char* _str;
//	};
//
//}
//void Teststring1()
//{
//	bit1::string s1;
//	bit1::string s2("hello");
//	bit1::string s3(s2);
//	s1 = s2;
//
//}
//
////�ڶ���ģ�ⷽ����������ִ���
//namespace bit2
//{
//	class string
//	{
//	public:
//		string(const char* str = "")
//		{
//			if (str == nullptr)
//				str = "";
//
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//		//�������캯��
//		string(const string& s) :_str(nullptr)
//		{
//			string temp(s._str);
//			swap(_str, temp._str);
//		}
//		//��ֵ���������
//		string& operator=(string s)// s�����ʱΪ��ʱ������һ����Դ����������ʱ��������
//		{
//			if (this != &s)
//			{
//				swap(_str, s._str);
//			}
//			return *this;
//		}
//		~string()
//		{
//			if (_str)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//
//	private:
//		char* _str;
//	};
//}
//void Teststring2()
//{
//	bit2::string s4(nullptr);
//	bit2::string s5("hello");
//	bit2::string s6(s5);
//	s4 = s5;
//}
//
////������ģ�ⷽ����дʱ���� ==��ǳ����+��������+�޸Ķ���ʱ�������
//
////��Ҫ�ر����޸Ķ�������ʱ�������s1[0] = 'A'��
//namespace bit3
//{
//	class string
//	{
//	public:
//		//���캯��
//		string(const char* str = "")
//		{
//			if (str == nullptr)
//				str = "";
//
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//			_pCount = new int(1);
//		}
//		//�������캯��
//		string(const string& s)
//			:_str(s._str)
//			, _pCount(s._pCount)
//		{
//			strcpy(_str, s._str);
//			memcpy(_pCount, s._pCount, sizeof(_pCount));
//			++(*_pCount);
//		}
//		//��ֵ�����������
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				Release();
//				_str = s._str;
//				_pCount = s._pCount;
//				++(*_pCount);
//			}
//			return *this;
//		}
//		//��������
//		~string()
//		{
//			Release();
//			//��֤��ʹ�������һ�����ö���Ҳָ���
//			_str = nullptr;
//			_pCount = nullptr;
//		}
//		char& operator[](size_t index)
//		{
//			//���޸Ķ�������ʱ��Ҫ��ֹһ��ȫ�ĵ���������ԣ���ʱҪ�������
//			if (*_pCount > 1)
//			{
//				string temp(_str);
//				Swap(temp);
//				//��ʱ�����ѱ����룬temp��������ԭλ�ã��ں�������ʱ�������temp����������������������1
//			}
//			return _str[index];
//		}
//		void Swap(string& temp)
//		{
//			swap(_str, temp._str);
//			swap(_str, temp._str);
//		}
//		const char& operator[](size_t index)const
//		{
//			return _str[index];
//		}
//		
//	private:
//		//�ж��Ƿ�Ϊ�����ռ��Դ������������Դ�������ǣ���������
//		void Release()
//		{
//			//�÷�ʽ�����̰߳�ȫ����
//			if (--(*_pCount) == 0)
//			{
//				delete[] _str;
//				delete _pCount;
//				_str = nullptr;
//				_pCount = nullptr;
//			}
//		}
//	private:
//		char* _str;
//		int* _pCount;
//	};
//}
//void Teststring3()
//{
//	bit3::string s1;
//	bit3::string s2(s1);
//	bit3::string s3("hello");
//	bit3::string s4(s3);
//	s1 = s3;
//}
//
//int main()
//{
//	Teststring1();
//	Teststring2();
//	Teststring3();
//
//	return 0;
//}