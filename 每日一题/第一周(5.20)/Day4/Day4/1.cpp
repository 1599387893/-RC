//1
//�����ǹ� �����ĸ��������ֱ��ʾA-B��B-C,A+B,B+C�����A��B��C
//����ʾ����
//			1 -2 3 4
//���ʾ����
//			2 1 3

#if 0
#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (c - a) / 2;
	int B2 = (b + d) / 2;
	if (B1 != B2)
		cout << "No";
	else
		cout << A << " " << B1 << " " << C << endl;
	system("pause");

	return 0;
}
#endif