#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n = 0, m = 0;
	int Q = 0, q;
	int lose = 0; //�����
	cin >> n >> m;
	vector<int> arr(n, 0); //����ÿ֧��Ʊ��ÿ������
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	cin >> Q;
	Q = 2;
	while (Q--)
	{
		cin >> q;
		lose = 0;
		int day = 1;
		//���Ҫ���۵Ĺ�Ʊ��==�ܵĹ�Ʊ������ô�����ۿ�������ģ�
		//������۵Ĺ�Ʊ�� < �ܵĹ�Ʊ������ô����ǰq����������������q���е����ļ���
		int sum = 0;
		int pos = 0;
		if (q >= n)
			pos = arr.size() - 1;//ȫ�����ۣ�
		else
			pos = arr.size() - q;//ֻ����һ����
		while (pos >= 0)
		{
			sum = 0;
			//ѭ��һ�ξ���һ��Ҫ���۵���
			for (int i = 0; i<m && pos >= 0; ++i)
				sum += arr[pos--];
			lose += sum*(day++);
		}
		cout << lose << endl;
	}
	return 0;
}
#endif
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
int solve(vector<pair<int, int>>& v)
{
	sort(v.begin(), v.end());
	pair<int, int> temp = v[0];
}
/******************************����д����******************************/


int main() {
	int n = 0, start = 0, end = 0;
	cin >> n;
	vector<pair<int,int>> v;
	while (n--)
	{
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	cout << solve(v) << endl;
	return 0;

}
