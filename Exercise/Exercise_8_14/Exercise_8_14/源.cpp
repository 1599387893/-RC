#include<iostream>
using namespace std;

int main()
{
#if 0
	cout << "1&2 : " << (1 & 2) << endl;
	cout << "2&4 : " << (2 & 4) << endl;
	cout << "2^4 : " << ((2 ^ 4)>>1) << endl;
	cout << "2&1 : " << (2 & 1) << endl;
	cout << "1|2 : " << (1 | 2) << endl;
	cout << "2|1 : " << (2 | 1) << endl;
	cout << "2&2 : " << (2 & 3) << endl;
#endif

	int arr[6] = { 0,2,4,6,8,10 };
	int* p = arr+1;
	//cout << *(p--) << endl;
	//cout << *(--p) << endl;
	cout << *(p--) << endl;
	cout << *p << endl;
	system("pause");
	return 0;
}