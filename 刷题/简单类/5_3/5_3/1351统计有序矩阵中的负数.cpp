//暴力求解
class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
		int res = 0;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[0].size(); ++j)
				if (grid[i][j]<0)
					res++;
		return res;
	}
};

//二分查找
class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
		//先从右下角元素开始找
		//如果该元素是负数，结果加一行，找上一行最后一个元素；
		//如果该元素不是负数，向后移动找负值；
		int res = 0;
		for (auto arr : grid)
		{
			if (arr[0]<0)
				res += arr.size();
			else
			{
				int pos = -1;
				//使用二分查找，找到第一个负数
				int l = 0, r = arr.size() - 1, mid = 0;
				while (l <= r)
				{
					mid = l + ((r - l) >> 1);
					if (arr[mid]<0)
					{
						pos = mid;
						r = mid - 1;
					}
					else
						l = mid + 1;
				}
				if (pos != -1)
					res += arr.size() - pos;
			}
		}
		return res;
	}
};
	