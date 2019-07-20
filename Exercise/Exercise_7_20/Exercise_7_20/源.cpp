#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

#if 0
int findMaxGap(vector<int> A, int n) {
	// write code here
	int ret = 0;
	int Max = 0;
	int leftMax = 0;
	int rightMax = A.size() - 1;
	int size = A.size();
	for (int i = 1; i<size; ++i)
		if (A[Max] < A[i])
			Max = i;
	if (Max == 0)
		ret = A[Max] - A[size - 1];
	else if (Max == size-1)
		ret = A[Max] - A[0];
	else
	{
		for (int i = 0; i<Max; ++i)
			if (A[leftMax] < A[i])
				leftMax = i;
		for (int i = rightMax; i>Max; --i)
			if (A[rightMax]<A[i])
				rightMax = i;
		A[leftMax]>A[rightMax] ? ret = (abs(A[Max] - A[rightMax])) : ret = (abs(A[Max] - A[leftMax]));
	}

	return ret;
}

int main()
{
	vector<int> v{1,2,10,3,4,5,6,7,8,9};
	cout << findMaxGap(v, v.size()) << endl;
	return 0;
}
#endif

vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
	// write code here
	vector<int>v;
	int cut = 0;
	int circle = ((n<m ? n : m) - 1) / 2 + 1;//圈数
	while( cut<circle)
	{
		//添加上行
		int upRow = 0;
		for (upRow = cut; upRow<n; ++upRow)
			v.push_back(mat[cut][upRow]);
		//添加右列
		int rightCol = 0;
		for (rightCol = cut + 1; rightCol<m; ++rightCol)
			v.push_back(mat[rightCol][upRow-1]);
		n--;
		//添加下行
		int downRow = 0;
		for (downRow = n - 1; (downRow > cut) && (n - 1 - downRow > downRow); --downRow)
			v.push_back(mat[rightCol-1][downRow]);
		m--;
		//添加左列
		int leftCol = 0;
		for (leftCol = m; (leftCol > cut) && (m - 1 - leftCol > leftCol); --leftCol)
			v.push_back(mat[leftCol][cut]);
		cut++;
	}
	return v;
}

int main()
{
	vector<vector<int>> vv{ { 11,12,13,14,15 }, 
							{ 21, 22, 23, 24, 25 }, 
							{ 31, 32, 33, 34, 35 }, 
							{ 41, 42, 43, 44, 45 }, 
							{ 51, 52, 53, 54, 55 } ,
							{61,62,63,64,65},
							{71,72,73,74,75}
		}; 
	clockwisePrint(vv, 5, 7);
	return 0;
}