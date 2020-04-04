class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() <= 2)
			return 0;
		int res = 0;
		vector<int> max_left(height.size()), max_right(height.size());
		max_left[0] = height[0];
		max_right[height.size() - 1] = height[height.size() - 1];
		for (int i = 1; i<height.size(); ++i)
			max_left[i] = max(height[i], max_left[i - 1]);
		for (int i = height.size() - 2; i >= 0; --i)
			max_right[i] = max(height[i], max_right[i + 1]);
		for (int i = 1; i<height.size(); ++i)
			res += min(max_left[i], max_right[i]) - height[i];
		return res;
	}
};



class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() <= 2)
			return 0;
		int count = 0;
		for (int i = 0; i <height.size() - 1; ++i)
		{
			int left = 0, right = 0;
			for (int j = i; j >= 0; --j)
				left = max(left, height[j]);
			for (int j = i; j<height.size(); ++j)
				right = max(right, height[j]);
			count += min(left, right) - height[i];
		}
		return count;
	}
};