#include<iostream>
#include<vector>
#include<string>

#if 0
using namespace std;
//1.最近公共祖先

class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		vector<int> v1;
		vector<int> v2;
		while (a >= 1)
		{
			v1.push_back(a);
			a /= 2;
		}
		while (b >= 1)
		{
			v2.push_back(b);
			b /= 2;
		}
		for (int i = 0; i < v1.size(); ++i)
		{
			auto it = find(v2.begin(), v2.end(), v1[i]);
			if (it != v2.end())
				return v1[i];
		}
	}
};
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (1)
		{
			if (a == b)
				return a;
			else if (a > b)
				a /= 2;
			else
				b /= 2;
		}
	}
};


//2. 求最大连续bit数
#include<iostream>
using namespace std;

int ContinueBit(int& n)
{
	int max = 0;
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			count++;
			n /= 2;
		}
		else
		{
			if (count > max)
				max = count;
			count = 0;
			n /= 2;
		}
	}
	if (max < count)
		max = count;
	return max;
}
int main()
{
	int n;
	while (cin >> n)
		cout << ContinueBit(n) << endl;
	return 0;
}

#endif