//���һ����ѭ���ĵ���������λ�ϵ���ֵ�������ĳ��ʱ�̸�������1����Ƹ�����Ϊ������
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
		//���ǿ�����������Ϊ����������
		//���ڲ�����������λƽ���ͼ��㣬�����ѭ����4->16->37->58->89->145->42->20->4��
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
		//ʹ��unordered_set������ֹ�����λƽ���ͽ��������������ֹ�����Ϊ������
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
		//����ָ���㷨
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