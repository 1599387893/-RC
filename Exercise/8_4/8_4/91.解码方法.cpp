//
//int numDecodings(string s) {
//	//dp[i]:表示s[0...i]的译码方法数
//	//如果 s[i] == '0' :
//	//	  如果s[i-1] = '1' || '2'   dp[i] = dp[i-2];
//	//	  否则 return 0;
//	//如果 s[i-1] == '1': dp[i] = dp[i-1] + dp[i-2];
//	//如果 s[i-1] == '2' 并且 '1' <=s[i] <= '6' 
//	//	  dp[i] = dp[i-1] + dp[i-2]
//	if (s[0] == '0') return 0;
//	int pre = 1, curr = 1;
//	for (int i = 1; i < s.size(); ++i)
//	{
//		int temp = curr;
//		if (s[i] == '0')
//		{
//			if (s[i - 1] == '1' || s[i - 1] == '2')
//				curr = pre;
//			else
//				return 0;
//		}
//		else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
//			curr += pre;
//		pre = temp;
//	}
//	return curr;
//}