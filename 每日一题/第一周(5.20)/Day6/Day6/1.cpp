//1
//��Ҫ����ÿ�������ŷ����þ���Ϊ2��λ�ò��ܷ��ã���ŷ����ù�ʽ��(X1 - X2)^2 + (Y1 - Y2)^2������ƽ������
//����ʾ����
//			4 3
//���ʾ����
//			5

#if 0
#include<iostream>
using namespace std;

int main()
{
	int count = 0;
	int w, h;
	cin >> w >> h;

	for (int i = 0; i < w; ++i)
		for (int j = 0; j < h; ++j)
			if (((i % 4 == 1 || i % 4 == 0) && (j % 4 == 1 || j % 4 == 0)) || ((i % 4 == 2 || i % 4 == 3) && (j % 4 == 2 || j % 4 == 3)))
				count++;

	cout<<count << endl;
	system("pause");
	return 0;
}



#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int w, h, res = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto& e : a)
		e.resize(h, 1);
	for (int i = 0; i<w; i++)
	{
		for (int j = 0; j<h; j++)
		{
			if (a[i][j] == 1)
			{
				res++;
				// ��ǲ��ܷŵ����λ��
				if ((i + 2)<w)
					a[i + 2][j] = 0;
				if ((j + 2)<h)
					a[i][j + 2] = 0;
			}
		}
	}
	cout << res;
	system("pause");
	return 0;
}
#endif