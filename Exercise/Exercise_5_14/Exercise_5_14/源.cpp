//////#include<iostream>
//////using namespace std;
//////
//////template <class T>
//////T Test(T num1, T num2)
//////{
//////	return num1 + num2;
//////}
//////int Test(int& num1, int& num2)
//////{
//////	return num1 + num2;
//////}
//////
//////int main()
//////{
//////	int a = 1;
//////	int b = 2;
//////	Test(a,b);
//////	Test(1, 2);
//////
//////	return 0;
//////
//////}
////
////#include<iostream>
////using namespace std;
////
////struct ServerInfo
////{
////	char _ip[32];//ip
////	int _port;   //¶Ë¿Ú
////};
////struct ConfigManager
////{
////public:
////	ConfigManager(const char* configfile = "bitserver.config")
////		:_configfile(configfile)
////	{}
////	void WriteBin(const ServerInfo& info)
////	{
////		ofstream ofs(_configfile, ifstream::in | ifstream::binary);
////		ofs.write((const char*)&info, sizeof£¨ServerInfo));
////		ofs.close();
////	}
////private:
////	string _configfile; //ÅäÖÃÎÄ¼þ
////};
//
//#include<stdio.h>
//
//#pragma pack(8)
//typedef struct Test
//{
//	char i : 8;
//	int a : 10;//4
//	
//	int b : 30;
//}Test;
//int main()
//{
//	Test t;
//	t.a = 1;
//	t.b = 2;
//	t.i = 3;
//	printf("%p\n", t.a);
//	printf("%p\n", t.b);
//	printf("%p\n", t.i);
//	printf("%d\n", sizeof(t));
//	return 0;
//}