//1
//����������(����������Ϊ�ǵ������߷ǵݼ������У�����������һ�������еĲ���Ͳ��ȵĸ���)
//����ʾ����
//			6					||4					||6
//			1 2 3 2 2 5			||1 3 2 3			||1 2 3 3 2 1
//���ʾ����
//			2					||2					||2

//#if 0
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (size_t i = 0; i < n; ++i)
		cin >> v[i];

	int ret = 1;
	for (size_t i = 1; i < n-2; ++i)
	{
		if ((v[i]>=v[i - 1] && v[i] >= v[i + 1]) || (v[i] <= v[i - 1] && v[i] <= v[i + 1]))
		{
			++ret;
			//if (i != n - 3)
			if (i >= 2)
				++i;
		}
	}
	cout << ret << endl;

	system("pause");
	return 0;
}
//#endif