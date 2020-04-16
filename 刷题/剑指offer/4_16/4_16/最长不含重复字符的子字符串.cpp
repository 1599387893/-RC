#if 0
//滑动窗口
//1. 初始化头尾指针 head，tail；
//2. tail 指针右移，判断 tail 指向的元素是否在[head:tail] 的窗口内；
//		如果窗口中没有该元素，则将该元素加入窗口，同时更新窗口长度最大值，tail 指针继续右移；
//		如果窗口中存在该元素，则将 head 指针右移，直到窗口中不包含该元素。

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> um;  //保存滑动窗口内每个字符以及他的位置
		int res = 0, l = 0, r = 0; //滑动窗口由l和r确定；
		while (r<s.size())
		{
			//处理左边界
			if (um.find(s[r]) != um.end()) //查看当前元素是否在滑动窗口内重复
				l = max(l, um[s[r]] + 1); //如果重复：那么将窗口缩小到发生冲突的那个元素的下一个位置；
			//处理右边界
			um[s[r++]] = r; //将um更新，同时右边界扩大(向右移动r标志，同时将该元素和他的位置添加到unordered_map中)
			res = max(r - l, res); //更新最大不重复子串
		}
		return res;
	}
};

//动态规划
//dp[i]表示以第i个字符结尾的无重复字符子串长度；
//1. 如果第i个字符在之前没有出现过，那么 dp[i]=dp[i-1]+1;
//2. 如果第i个字符在之前出现过，那么用计算该字符上次出现的位置到当前的距离d；
//	   a.如果d小于等于dp[i-1]，那说明该字符上次出现在以i-1位置结尾的子串中，那么dp[i]= d;
//     b.如果d大于dp[i-1]，说明该字符不出现在以i-1字符为结尾的子串中，那么dp[i]=dp[i-1]+1;
//3.在遍历过程中，比较出最长无重复字符子串长度
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
			return 0;
		if (s.size()<2)
			return 1;
		unordered_map<char, int> um;
		vector<int> dp(s.size());
		um.insert(make_pair(s[0], 0));
		int res = 0;
		dp[0] = 1;
		for (int i = 1; i < s.size(); ++i)
		{
			auto it = um.find(s[i]);
			if (it == um.end())
			{
				dp[i] = dp[i - 1] + 1;
				um.insert(make_pair(s[i], i));
			}
			else
			{
				if ((i - (*it).second) <= dp[i - 1])
					dp[i] = i - (*it).second;
				else
					dp[i] = dp[i - 1] + 1;
				um[s[i]] = i;
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};

#endif