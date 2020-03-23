//class MaxGap {
//public:
//	int findMaxGap(vector<int> A, int n) {
//		// write code here
//		int max = A[0];
//		for (int i = 1; i < A.size(); ++i)
//			if (A[i] > max)
//				max = A[i];
//		int left = A[0];
//		int right = A[A.size() - 1];
//		if (left > right)
//			return max - right;
//		return max - left;
//	}
//};

#include<iostream>
#include<vector>
using namespace std;
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		// write code here
		vector<int> v;
		int x1 = 0, y1 = 0;
		int x2 = n - 1, y2 = m - 1;
		while (x1 <= x2 && y1 <= y2)
		{
			for (int y = y1; y <= y2; ++y)
				v.push_back(mat[x1][y]);
			for (int x = x1 + 1; x<x2; ++x)
				v.push_back(mat[x][y2]);
			for (int y = y2; x1<x2 && y >= y1; --y)
				v.push_back(mat[x2][y]);
			for (int x = x2 - 1; y1<y2 && x>x1; --x)
				v.push_back(mat[x][y1]);
			x2--; y2--;
			y1++; x1++;
		}
		return v;
	}
int main()
{
	vector<vector<int>> mat{ {1,2,3,4,5}, {14,15,16,17,6}, {13,20,19,18,7}, {12,11,10,9,8} };
	vector<int> res = clockwisePrint(mat, 4, 5);
	for (const auto c : res)
		cout << c << " ";
	cout << endl;
	system("pause");
	return 0;
}