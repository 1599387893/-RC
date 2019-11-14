#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//1.两种排序方法
//int JudgeStr(vector<string>& vs)
//{
//	int islen = 1;
//	int isdic = 1;
//	for (int i = 0; i < vs.size() - 1; ++i)
//	{
//		if (islen == 1 && (vs[i].size() > vs[i + 1].size()))
//			islen = 0;
//		if (isdic == 1 && (vs[i] > vs[i+1]))
//			isdic = 0;
//	}
//	if (islen == 1 && isdic == 1)
//		return 2;
//	if (islen == 1 && isdic == 0)
//		return -1;
//	if (islen == 0 && isdic == 1)
//		return 1;
//	return 0;
//}
//int main()
//{
//	int n;
//	vector<string> vs;
//	while (cin >> n)
//	{
//		fflush(stdin);
//		vs.resize(n);
//		for (int i = 0; i<n; ++i)
//			getline(cin, vs[i]);
//		int ret = JudgeStr(vs);
//		cout << (ret == -1 ? "lengths" : (ret == 0 ? "none" : (ret == 1 ? "lexicographically" : "both"))) << endl;
//		vs.clear();
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
////求最小公倍数
//int main()
//{
//	int m, n;
//	while (cin >> m >> n)
//	{
//		if (n > m)
//			swap(m, n);
//		if (m%n == 0)
//		{
//			cout << m << endl;
//			continue;
//		}
//		int i = 0;
//		for (i = n*2; !(i%m == 0 && i%n == 0); i += n)
//			;
//		cout << i << endl;
//	}
//}


//--------------------------------------------------------
链接：https://www.nowcoder.com/questionTerminal/22948c2cad484e0291350abad86136c3
来源：牛客网

/* c++
最小公倍数 = 两数之积除以最大公约数
*/
#include<iostream>
using namespace std;

int gcd(int a, int b) // greatest common divisor
{
	while (a%b){
		int tmp = a;
		a = b;
		b = tmp%b;
	}
	return b;

}
int main()
{
	int a, b;
	while (cin >> a >> b){
		cout << a*b / gcd(a, b) << endl;
	}
	return 0;
}