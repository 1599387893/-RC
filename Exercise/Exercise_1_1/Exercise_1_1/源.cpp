//跳石板
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//求出每个数的约数
void divisorNum(int& n, vector<int>& divNum)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n%i == 0)
		{
			divNum.push_back(i);
			if (n / i != i)
				divNum.push_back(n/i);
		}
	}
}
int Jump(int& n, int& m)
{
	vector<int> stepNum(m + 1, 0);
	stepNum[n] = 1;

	//从第N处开始跳
	for (int i = n; i < m; ++i)
	{
		vector<int> divNum;

		//0表示这个点不能到
		if (stepNum[i] == 0)
			continue;
		
		//将所有能走的步数保存
		divisorNum(i, divNum);
		
		for (int j = 0; j < divNum.size(); ++j)
		{
			if ((divNum[j] + i) <= m && stepNum[divNum[j] + i] != 0)
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1);
			else if ((divNum[j] + i) <= m)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
		if (stepNum[m] == 0)
			return -1;
		else
			return stepNum[m] - 1;
	}
}
int main()
{
	int n, m;
	while (cin >> n >> m)
		cout<<Jump(n, m)<<endl;
	return 0;
}