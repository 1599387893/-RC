#include<iostream>
#include<vector>
using namespace std;

bool Is24(vector<int>& point, int level, double result)
{
	if (level == 3)
		return result == 24;
	level++;
	if ((Is24(point, level, result + point[level])))
		return true;
	if ((Is24(point, level, result - point[level])))
		return true;
	if ((Is24(point, level, result * point[level])))
		return true;
	if (result!=0 &&(Is24(point, level, result / point[level])))
		return true;
	return false;
}
int main()
{
	vector<int> point(4);
	for (int i = 0; i < 4; ++i)
		cin >> point[i];
	cout << Is24(point, 0, point[0]) << endl;
	return 0;
}