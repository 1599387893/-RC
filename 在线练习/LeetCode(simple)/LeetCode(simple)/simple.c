//����֮��
int* twoSum(int* nums, int numsSize, int target) {

	static int ret[2];
	for (int i = 0; i<numsSize - 1; i++)
	{
		for (int j = i + 1; j<numsSize; j++)
		{
			if (target == nums[i] + nums[j])
			{
				ret[0] = i;
				ret[1] = j;
				return ret;
			}
		}
	}
	return NULL;
}

//������
bool isPalindrome(int x)
{
	if (x<0)
		return false;
	int ret = 0;
	int x2 = x;
	while (x2)
	{
		if (ret<-214748364 || ret>214748364) return false;
		ret = ret * 10 + x2 % 10;
		x2 /= 10;
	}
	if (x == ret)
		return true;
	else
		return false;
}
//2.0(rough)
#include<string.h>
bool isPalindrome(int x)
{
	if (x<0)
		return false;
	int ret = 0;
	int px = 0;
	int x2 = x;
	while (x)
	{
		ret = x % 10; //ret�������һλ�ϵ���
		//��õ�һλ�ϵ���
		px = x;
		while (px>10)
			px /= 10;
		//�ж����һλ�����һλ�����Ƿ����
		if (px != ret)
			return false;
		//ɾ�����λ
		char a[] = itoa(x);
		int length = strlen(a);
		x = atoi()
	}

}