//从队伍中选出下标分别为 i、j、k 的 3 名士兵，他们的评分分别为 rating[i]、rating[j]、rating[k]
//作战单位需满足： rating[i] < rating[j] < rating[k] 或者 rating[i] > rating[j] > rating[k] ，其中  0 <= i < j < k < n

//暴力求解法
class Solution {
public:
	
	int numTeams(vector<int>& rating) {
		int count = 0;
		for (int i = 0; i < rating.size(); ++i)
			for (int j = i + 1; j < rating.size(); ++j)
				for (int k = j + 1; k < rating.size(); ++k)
					if ((rating[i]<rating[j] && rating[j]<rating[k]) || (rating[i]>rating[j] && rating[j]>rating[k]))
						count++;
		return count;
	}
};

//枚举中间点
class Solution {
public:
	int numTeams(vector<int>& rating) {
		int count = 0;
		//针对于每一个非开始和结束位置的数，计算该数左边小于个数乘以右边大于个数的值。
		//第i个元素表示该位置左边小于rating[i]的个数和大于rating[i]的个数
		vector<pair<int, int>> left(rating.size());
		//第i个元素表示该位置右边小于rating[i]的个数和大于rating[i]的个数
		vector<pair<int, int>> right(rating.size());
		for (int i = 1; i < rating.size(); ++i)
			for (int j = i - 1; j >= 0; --j)
				if (rating[j]<rating[i])
					left[i].first++;
				else
					left[i].second++;
		for (int i = rating.size() - 2; i >= 0; --i)
			for (int j = i + 1; j<rating.size(); ++j)
				if (rating[i]>rating[j])
					right[i].first++;
				else
					right[i].second++;
		for (int i = 1; i<rating.size() - 1; i++)
			count += left[i].first*right[i].second + left[i].second*right[i].first;
		return count;
	}
};


//动态规划
class Solution {
public:
	int numTeams(vector<int>& rating) {
		if (rating.size() <= 2) return 0;
		vector<int> min(rating.size(), 0);//小于rating[i]的个数
		vector<int> max(rating.size(), 0);//大于rating[i]的个数
		int res = 0;
		for (int i = 0; i < rating.size(); ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (rating[i]>rating[j])
				{
					min[i]++;
					res += min[j];
				}
				if (rating[i] < rating[j])
				{
					max[i]++;
					res += max[j];
				}
			}
		}
		return res;
	}
};
