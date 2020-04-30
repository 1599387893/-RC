//如果一个数循环的等于他各个位上的数值，如果再某个时刻该数等于1，则称该数字为快乐数
class Solution {
public:
	bool isHappy(int n) {
		int temp = 0;
		for (int i = 0; i < 100; ++i)
		{
			do
			{
				temp += pow((n % 10), 2);
				n /= 10;
			} while (n);
			n = temp;
			temp = 0;
			if (n == 1)
				return true;
		}
		return false;
	}
};


class Solution {
public:
	bool isHappy(int n) {
		//不是快乐数的数称为不快乐数，
		//对于不快乐数的数位平方和计算，会进入循环（4->16->37->58->89->145->42->20->4）
		unordered_set<int> unhappynumber{ 4, 16, 20, 37, 42, 58, 89, 145 };
		int temp = 0;
		while (1)
		{
			do
			{
				temp += pow((n % 10), 2);
				n /= 10;
			} while (n);
			n = temp;
			temp = 0;
			if (n>145) continue;
			if (n == 1) break;
			if (unhappynumber.find(n) != unhappynumber.end()) return false;
		}
		return true;
	}
};

class Solution {
public:
	bool isHappy(int n) {
		if (n == 1) return true;
		//使用unordered_set保存出现过的数位平方和结果，如果该数出现过，则不为快乐数
		unordered_set<int> us;
		int temp = 0;
		while (us.find(n) == us.end())
		{
			us.insert(n);
			do
			{
				temp += pow((n % 10), 2);
				n /= 10;
			} while (n);
			n = temp;
			temp = 0;
			if (n == 1) return true;

		}
		return false;
	}
};


class Solution {
public:
	void Next(int& number)
	{
		int temp = 0;
		do{
			temp += pow((number % 10), 2);
			number /= 10;
		} while (number);
		number = temp;
	}
	bool isHappy(int n) {
		if (n == 1) return true;
		//快慢指针算法
		int fast = n, slow = n;
		do
		{
			Next(slow);
			Next(fast);
			Next(fast);
		} while (fast != slow && fast != 1);
		if (fast == 1)   return true;
		return false;
	}
};