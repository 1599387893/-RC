#if 0
#include<iostream>
#include<math.h>//��sqrt�����������������������ӵ�ʱ��
using namespace std;
int main()
{
	int n, i, t;
	while (cin>>n)
	{
		t = 0;
		for (i = 2; i <= sqrt(n); i++)
		{
			if (n%i == 0)//�õ�һ������
			{
				n = n / i;
				t++;
			}
			while (n%i == 0)
			{
				n = n / i;//��ʣ��Ĵ����ӳ���
			}
		}
		if (n != 1)
		{
			t++;
		}//����Ǳ�sqrt(n)��Ҫ���������������Ҫ����ȥ,��֤��
		cout << t << endl;
	}
	return 0;
}



#include<stdio.h>
#include<unistd.h>

int main()
{
	fork();
	fork();
	fork();
	printf("hello\n");
	return 0;
}
#endif
// [7,7,9,5,1,6,7,9,3,2,6]
// [6,7,6,7,1,5,7,9,3,9,2]

//int i = 0, j = 1;
//while (i < len && j < len){
//	while (i < len && (arr[i] & 1) == 0) i += 2;
//	while (j < len && (arr[j] & 1) == 1) j += 2;
//	if (i < len && j < len) swap(arr[i], arr[j]);

