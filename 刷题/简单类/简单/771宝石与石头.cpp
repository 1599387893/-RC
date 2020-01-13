class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int count = 0;
		for (auto i = 0; i < S.size(); ++i)
		{
			if (J.find(S[i]) != string::npos)
				count++;
		}
		return count;
	}
};

#include<algorithm>
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int mycount = 0;
		for (int i = 0; i < J.size(); ++i)
			mycount += (int)count(S.begin(), S.end(), J[i]);
		return mycount;
	}
};