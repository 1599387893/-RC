/*
【题目描述】
小 Q 正在攀登一座宝塔，这座宝塔很特别，塔总共有 n 层，但是每两层之间的净高却不相同，
所以造成了小 Q 爬过每层的时间也不同。如果某一层的高度为 x，那么爬过这一层所需的时间也是 x。 小 Q 还会使用一种魔法,每用一次可以让他向上跳一层或两层,但是每次跳跃后小 Q 都将用完魔法力,必须
爬过至少一层才能再次跳跃(你可以认为小 Q 需要跳两次一层才休息，最后也可以跳到塔外即超过塔高，跳
是不消耗时间的)。 小 Q 想用最短的时间爬到塔顶,希望你能告诉他最短时间是多少.*/

/*
输入描述: 
第一行一个数 n (n<=10000),表示塔的层数.
接下来的 n 行每行一个数 h(1 <= h <=100),表示从下往上每层的高度.*/

#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int level = 0;
	int h = 0;
	vector<int> p(10000);
	vector<int> j(10000);
	while (cin >> level)
	{
		for (int i = 1; i < level; ++i)
		{
			cin >> h;
			p[i] = min(p[i-1],j[i-1])+h;
			if (i == 1) continue;
			j[i] = min(p[i - 1], p[i - 2]);
		}
		cout << min(p[level - 1], j[level - 1])<<endl;
	}
	return 0;
}
#endif