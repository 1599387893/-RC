#if 0
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int nthUglyNumber(int n) {
	//��̬�滮  ���ڵĳ�������֮ǰ�ĳ���x2,x3,x5��õ�
	if (n <= 6) return n;
	unordered_map<int, bool> um;
	um.insert(make_pair(1, true));
	vector<int> uglyNum(n, 1);
	vector<int> pos(3, 0);
	int a = 0, b = 0, c = 0;
	int index = 1;
	while (index < n)
	{
		a = uglyNum[pos[0]] * 2;
		b = uglyNum[pos[1]] * 3;
		c = uglyNum[pos[2]] * 5;
		int num = a < b ? (a < c ? a : c) : (b < c ? b : c);
		num == a ? pos[0]++ : (num == b ? pos[1]++ : pos[2]++);
		if (!um[num])
		{
			uglyNum[index++] = num;
			um[num] = true;
		}
	}
	return uglyNum.back();
}
int main()
{
	cout << nthUglyNumber(10) << endl;
	return 0;
}
#endif