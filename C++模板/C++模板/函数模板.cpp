//#include<iostream>
//using namespace std;
//
//template <class ElemType>
//ElemType F(ElemType x)
//{
//	ElemType y;
//	y = x * (ElemType)5.8;
//	return y;
//}
//int main()
//{
//	cout << F(5) << endl;
//	cout << F(5.0) << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void ShowMax(int a, int b)
//{
//	int max = (a > b) ? a : b;
//	cout << "调用int,maxValue = " << max << endl;
//}
//void ShowMax(double a, double b)
//{
//	int max = (a > b) ? a : b;
//	cout << "调用double,maxValue = " << max << endl;
//}
//
//template <class ElemType1,class ElemType2>
//void ShowMax(ElemType1 a, ElemType2 b)
//{
//	ElemType1 max = (a >(ElemType1) b) ? a : (ElemType2)b;
//	cout << "调用函数模板,maxValue = " << max << endl;
//}
//
//int main()
//{
//	ShowMax(16, 518);
//	ShowMax(16.0, 518.0);
//	ShowMax(16.0, 518);
//
//	system("pause");
//	return 0;
//}