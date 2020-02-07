#if 0
class Solution {
public:
	vector<char> Digit(int n)
	{
		vector<char> res;
		while (n)
		{
			res.push_back(n % 10 + '0');
			n /= 10;
		}
		reverse(res.begin(), res.end());
		return res;
	}
	int compress(vector<char>& chars) {
		if (chars.size() == 1 || chars.size() == 0)
			return chars.size();
		int ret = 0, temp = 0;
		int size = chars.size();
		for (int i = 0; i < size; ++i)
		{
			chars.push_back(chars[i]);
			temp = 1;
			for (int j = i + 1; j < size && chars[i] == chars[j]; ++j, temp++);
			if (temp == 1)
				continue;
			else if (temp == 2)
				chars.push_back('2');
			else
			{
				vector<char> res = Digit(temp);
				chars.insert(chars.end(), res.begin(), res.end());
			}
			i += temp - 1;
		}
		chars.erase(chars.begin(), chars.begin() + size);
		return chars.size();
	}
};
#endif