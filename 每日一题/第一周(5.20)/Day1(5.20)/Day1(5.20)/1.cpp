//1
//����n����飨3��һ�飩��ˮƽ��ʹ�����ж����еĵڶ���ˮƽ�˵ĺ����
//����ʾ����
//			2
//			1 2 3 2 3 2
//���ʾ����
//			4

#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;//������
	vector<int> v;//��Ŷ�Ա
	v.resize(n * 3);
	int sum = 0;//���ֵ

	for (int i = 0; i < 3 * n; ++i)
		cin >> v[i];

	std::sort(v.begin(), v.end());
	for (int i = n; i < 3 * n; i += 2)
		sum += v[i];

	cout << sum << endl;

	system("pause");
	return 0;

}
#endif


