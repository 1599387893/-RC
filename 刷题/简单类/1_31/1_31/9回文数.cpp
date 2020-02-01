#if 0
class Solution {
public:
	bool isPalindrome(int x) {
		if(x<0 || (x>=10 && x%10==0))
			return false;
		if(x<10)
			return true;
		int num = 0;
		while(x > num)
		{
			num = num*10+x%10;
			x/=10;
		}
		return x==num || x==num/10;
	}
};
#endif

#if 0
class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0)
			return false;
		if (x<10)
			return true;
		vector<int> bit;
		while (x)
		{
			bit.push_back(x % 10);
			x /= 10;
		}
		int begin = 0, end = bit.size() - 1;
		while (begin<end)
			if (bit[begin++] != bit[end--])
				return  false;
		return true;
	}
};
#endif

#if 0
class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0)
			return false;
		if (x<10)
			return true;
		stringstream ss;
		ss << x;
		string s;
		ss >> s;
		string temp(s);
		reverse(temp.begin(), temp.end());
		if (s == temp)
			return true;
		return false;
	}
};
#endif