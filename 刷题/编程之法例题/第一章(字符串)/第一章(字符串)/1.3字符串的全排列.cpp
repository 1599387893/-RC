#if 0

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


//方法一： 递归实现
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

//调用库函数
bool CalcAllPermutation(char* str,int num)
{
	int i;
	//step1: 找到排列中最后一个升序的首位位置i,x=ai
	for (i = num - 1; (i >= 0) && (str[i] >= str[i + 1]); --i);
	
	//已经找到所有排列
	if (i < 0)
		return false;

	int k;
	//step2:找到排序中第i为右边最后一个比ai大的位置j，y=aj;
	for (k = num - 1; (k > i) && (str[k] <= str[i]); --k);

	//step3:交换x和y
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