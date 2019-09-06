//两数之和
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

//回文数
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
		ret = x % 10; //ret保存最后一位上的数
		//求得第一位上的数
		px = x;
		while (px>10)
			px /= 10;
		//判断最后一位数与第一位的数是否相等
		if (px != ret)
			return false;
		//删除最高位
		char a[] = itoa(x);
		int length = strlen(a);
		x = atoi()
	}

}