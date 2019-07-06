//不用加减乘除做加法
//不得使用+，-，*，/四则运算符号；


//解法一
//汇编语言
int add(int a, int b)
{
	_asm;
	{
		MOV EAX, a;
		MOV ECX, b;
		ADD EAX, ECX;
	}
}

//解法二
//位运算
//1.两个数异或：相当于每一位相加，而不考虑进位；
//2.两个数相与，并左移一位：相当于求得进位；

class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2)
		{
			int sum = num1^num2;
			int carray = (num1 & num2) << 1;
			num1 = sum;
			num2 = carray;
		}
		return num1;
	}
};