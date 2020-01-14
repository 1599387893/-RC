//该题的本质是使用切比雪夫距离
#if 0
#include<cmath>
class Solution {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int time = 0;
		int x1 = points[0][0], y1 = points[0][1];
		int x2, y2;
		for (auto i = 1; i < points.size(); ++i)
		{
			x2 = points[i][0];
			y2 = points[i][1];
			time += max(fabs(x1 - x2), fabs(y1 - y2));
			x1 = x2;
			y1 = y2;
		}
		return time;
	}
};
#endif