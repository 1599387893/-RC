//算法
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//-----------------------Fibonacci---
//解法一
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		int f, f1 = 1, f2 = 1;
		for (int i = 3; i <= n; ++i)
		{
			f = f1 + f2;
			f2 = f1;
			f1 = f;
		}
		return f;
	}
};
//解法二
class Solution {
public:
	int Fibonacci(int n) {
		vector<int> f(40, 0);
		f[0] = 0;
		f[1] = 1;
		f[2] = 1;
		for (int i = 3; i<40; ++i)
			f[i] = f[i - 1] + f[i - 2];
		return f[n];
	}
};
//解法三
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		return (Fibonacci(n - 1) + Fibonacci(n - 2));
	}
};

//---------------------变态青蛙跳台阶-------------
//解法一
class Solution {
public:
	int jumpFloorII(int number)
	{
		if (number <= 1)
			return number;
		return pow(2, number - 1);
	}
};
//解法二
class Solution {
public:
	int jumpFloorII(int number) {
		if (number == 0)
			return 0;
		if (number == 1)
			return 1;
		return 1 << (number - 1);
	}
};
//解法三
class Solution {
public:
	int jumpFloorII(int number) {
		if (number <= 1)
			return number;
		int total = 1;
		for (int i = 1; i<number; ++i)
			total *= 2;
		return total;
	}
};

//---------------------连续子数组的最大和-----------
//解法一
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
			return 0;
		int sum = array[0];
		int maxsum = array[0];
		for (int i = 1; i<array.size(); ++i)
		{
			sum = (sum>0) ? sum + array[i] : array[i];
			maxsum = (maxsum < sum) ? sum : maxsum;
		}
		return maxsum;
	}
};
