#if 0
class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		if(s1.size() != s2.size())
			return false;
		int sum = 0;
		for(int i = 0;i < s1.size() ;++i)
		{
			sum ^= s1[i]; // sum += s1[i];
			sum ^= s2[i]; // sum -= s2[i];
		}
		return sum == 0;
	}
};
#endif

#if 0
class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		return s1 == s2;
	}
};
#endif