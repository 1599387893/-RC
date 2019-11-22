//1.另类加法

//二进制加法。发现一个特点。
//位的异或运算跟求'和'的结果一致：
//异或 1^1=0   1^0=1   0^0=0
//求和 1+1=0   1+0=1   0+0=0

//位的与运算跟求'进位‘的结果一致：
//位与 1&1=1   1&0=0   0&0=0
//进位 1+1=1   1+0=0   0+0=0
//于是可以用异或运算和与运算来表示加法
#if 0
int addAB(int A, int B) {
	int xor, and;

	while (B != 0){//一直循环，直到计算的没有进位
		xor = A^B; //xor求得每一位的计算结果
		and = (A&B) << 1; //and用来保存进位
		A = xor;
		B = and;
	}
	return A;
}
//2.求路径总数

//a.如果n或者m为1，则只有一行或者一列，从左上角走到右下角的路径数为n + m
//比如： 1 * 1格子，可以先向下走，再向右走，到达右下角；或者先向右走，
//再向下走，到达右下角，共两条，即 1 + 1 = 2，对于1 * m和 n * m的
//情况同学们自己画一下

//b. 如果n,m都大于1，那么走到[n][m]格子的右下角只有两条路径，
//<1>: 从[n - 1][m]格子的右下角向下走，到达
//<2>: 从[n][m - 1]格子的右下角向右走，到达
//所以走到[n][m]格子的右下角的数量为[n-1][m] + [n][m - 1],可以通过递归实现，情况a为
//递归的终止条件。
#include<iostream>
using namespace std;
int CountPath(int n, int m)
{
	if ((n == 1) || (m == 1))
		return n + m;
	if (n == 1 && m == 1)
		return 0;
	return CountPath(n - 1, m) + CountPath(n, m - 1);
}
int main()
{
	int n, m;
	while (cin >> n >> m)
		cout << CountPath(n, m) << endl;
	return 0;
}
#endif