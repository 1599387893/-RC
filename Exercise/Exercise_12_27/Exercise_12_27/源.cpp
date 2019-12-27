//#include<iostream>
//using namespace std;
//
//int CountBit(int& num)
//{
//	int ret = 0;
//	bool flag = true;
//	int count = 0;
//	for (int i = 0; i < 8; ++i)
//	{
//		if (num >> i & 1)
//		{
//			if (flag)
//				count++;
//			else
//			{
//				flag = true;
//				count = 1;
//			}
//		}
//		else
//			flag = false;
//		if (count > ret)
//			ret = count;
//	}
//	return ret;
//}
//
////2.最大连续bit数
//int main()
//{
//	int num;
//	while (cin >> num)
//		cout << CountBit(num) << endl;
//	return 0;
//}


#include<iostream>
using namespace std;
int Ancestor(int& a, int& b)
{
	while (a > 1 && b > 1)
	{
		if (a == b)
			return a;
		while (a > b)
			a /= 2;
		while (b > a)
			b /= 2;
	}
	return 1;
}
void fool()
{
	/*
	struct st_task
	{
		uint16_t it;
		uint32_t value;
		uint64_t timestamp;
	};*/
}
class Test
{
private:
	int* a;
public:
	Test(){  };
	void S(){ cout << "1" << endl; }
	~Test(){ delete this; }
};
void Test1(const int& a, const int& b)
{
	cout << a << " " << b << endl;
}
int main()
{
#if 0
	int a, b;
	while (cin >> a >> b)
		cout << Ancestor(a, b) << endl;
#endif

	//fool();
	//Test t;
	int a = 0;
	Test1(a++,a++);
	system("pause");
	return 0;
}