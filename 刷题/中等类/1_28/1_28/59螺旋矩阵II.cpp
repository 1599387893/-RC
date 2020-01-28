#if 0
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res;
		res.resize(n,vector<int>(n,0));

		//边界值
		int left = 0,right = n-1,up = 0,down = n-1;
		int i = 1;
		int end = n*n;
		while(i<=end)
		{
			//向左
			for(int j = left;(i<=end)&&(j<=right); ++j )
				res[up][j] = i++;
			up++;
			//向下
			for(int j = up; (i<=end)&&(j<=down);++j)
				res[j][right] = i++;
			right--;
			//向右
			for(int j = right; (i<=end)&&(j>=left); --j)
				res[down][j] = i++;
			down--;
			//向上
			for(int j = down; (i<=end)&&(j>=up); --j)
				res[j][left] = i++;
			left++;
		}
		return res;
	}
};
#endif