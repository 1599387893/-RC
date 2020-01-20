#if 0
class Solution {
public:
	int heightChecker(vector<int>& heights) {
		int count = 0;
		vector<int> checker(101);
		for (auto i : heights)
			checker[i]++;
		for (int i = 0, j = 0; i < checker.size(); ++i)
		{
			while (checker[i]-- > 0)
				if (i != heights[j++])
					count++;
		}
		return count;
	}
};
class Solution {
public:
	int heightChecker(vector<int>& heights) {
		int count = 0;
		vector<int> check(heights);
		sort(check.begin(),check.end());
		for(int i = 0; i < chech.size();++i)
			if(check[i]!=heights)
				count++;
		return count;
	}
};
#endif