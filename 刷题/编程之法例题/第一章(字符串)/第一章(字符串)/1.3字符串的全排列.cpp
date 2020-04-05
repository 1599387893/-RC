#if 0

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


//����һ�� �ݹ�ʵ��
void CalcAllPermutation(char* perm,int from,int to)
{
	if (to <= 1)
		return;
	if (from == to)
	{
		for (int i = 0; i <= to; ++i)
			cout << perm[i];
		cout << endl;
	}
	else
	{
		for (int j = from; j <= to; ++j)
		{
			swap(perm[j],perm[from]);
			CalcAllPermutation(perm,from+1,to);
			swap(perm[j], perm[from]);
		}
	}
}

//���ÿ⺯��
bool CalcAllPermutation(char* str,int num)
{
	int i;
	//step1: �ҵ����������һ���������λλ��i,x=ai
	for (i = num - 1; (i >= 0) && (str[i] >= str[i + 1]); --i);
	
	//�Ѿ��ҵ���������
	if (i < 0)
		return false;

	int k;
	//step2:�ҵ������е�iΪ�ұ����һ����ai���λ��j��y=aj;
	for (k = num - 1; (k > i) && (str[k] <= str[i]); --k);

	//step3:����x��y
	swap(str[i], str[k]);
	reverse(str+1+i,str+num);
	return true;
}

void Test(char* str, int num)
{
	do{
		cout << str << endl;
	} while (CalcAllPermutation(str,num));
}
int main()
{
	char str[] = "abc";
	//CalcAllPermutation(str,0,2);
	//CalcAllPermutation(str,3);
	Test(str, 3);
	system("pause");
	return 0;
}

#endif