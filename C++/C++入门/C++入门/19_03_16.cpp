//#include<iostream>
////�����ռ���Զ�������ͺ���
//namespace N
//{
//	int a = 11;
//
//	int add(int num1, int num2)
//	{
//		return num1 + num2;
//	}
//}
////�����ռ����Ƕ��
//namespace N2
//{
//	//int a = 20;
//	int b = 30;
//	namespace N3
//	{
//		int c = 40;
//		int d = 50;
//	}
//}
//
//int a = 10;
////int main()
////{
////	int a = 1;
////	printf("%d\n", a);
////	printf("%d\n", ::a);
////	printf("%d\n", N::a);
////
////	system("pause");
////	return 0;
////}
//
////using namespace N2;
//using N2::b;
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", b);
//	printf("%d\n", b);
//
//	system("pause");
//	return 0;
//}



//ȱʡ���� 
//#include<iostream>
//using namespace std;
//
//
//int add(int a = 1, int b = 2)
//{
//	return a + b;
//}
//int main()
//{
//	cout << "Hello World!" << endl;
//	cout << "a+b=" << add(0,3) << endl;
//		system("pause");
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//


//�������� 
//int add(int a = 1, int b = 2)
//{
//	return a + b;
//}
//double add(double a = 0.0, double b = 3.0)
//{
//	return  a + b;
//}
//int main()
//{
//	cout << "a+b=" << add(0, 3) << endl;
//	cout << "a+b=" << add(0.0, 3.0) << endl;
//	system("pause");
//	return 0;
//}

//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//long Add(long left, long right)
//{
//	return left + right;
//}
//int main()
//{
//	cout<<Add(10, 20)<<endl;
//	cout<<Add(10.0, 20.0)<<endl;
//	cout<<Add(10L, 20L)<<endl;
//
//	system("pause");
//	return 0;
//}
//#include<iostream>
//using namespace std;
//


//����C���Թ��� 
//extern "C" int Add(int a, int b);
//void TestFunc(int a = 10)
//{
//	cout << "void TestFunc(int)" << endl;
//}
//void TestFunc(int a)
//{
//	cout << "void TestFunc(int)" << endl;
//}
//int main()
//{
//	Add(1, 2);
//	return 0;
//}
