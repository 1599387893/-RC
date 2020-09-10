#if 0
#include <iostream>
#include <vector>
using namespace std;
int out_x;
int out_y;
int x;
int y;
int FindWay(vector<vector<bool>>& room, int cur_x, int cur_y, int roomCount)
{
	if (cur_x >= x || cur_x < 0 || cur_y >= y || cur_y <0)
		return 0;
	if (cur_x == out_x && cur_y == out_y)
		return (roomCount == (x * y) && !room[cur_x][cur_y]);
	if (room[cur_x][cur_y])
		return 0;
	room[cur_x][cur_y] = true;
	int res = 0;
	res += FindWay(room, cur_x + 1, cur_y, roomCount + 1);
	res += FindWay(room, cur_x - 1, cur_y, roomCount + 1);
	res += FindWay(room, cur_x, cur_y + 1, roomCount + 1);
	res += FindWay(room, cur_x, cur_y - 1, roomCount + 1);
	room[cur_x][cur_y] = false;
	return res;
}
int main()
{
	cin >> x >> y;
	vector<vector<bool>> room(x, vector<bool>(y, false));
	int in_x = 0, in_y = 0;
	cin >> in_x >> in_y >> out_x >> out_y;
	//room[in_x][in_y] = true;
	cout << FindWay(room, in_x, in_y, 1) << endl;
	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int W = 0, L = 0;
	cin >> W >> L;
	vector<int> heigh(L);
	for (int i = 0; i < L; ++i)
		cin >> heigh[i];
	int res = 0;
	vector<int> temp(heigh);
	for (int i = L - 2; i >= 0; --i)
		if (temp[i + 1] < temp[i])
			temp[i] = temp[i + 1];
	for (int i = 0; i < L; ++i)
		res += heigh[i] - temp[i];
	cout << res * W << endl;
	return 0;
}
#endif