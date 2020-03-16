#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int res = __INT_MAX__;
vector<vector<int>>visited(10, vector<int>(10, 0));
void find_path(vector<vector<char>>&m, int sx, int sy, int tx, int ty, int tmp){
	if (sx<0 || sy<0 || visited[sx][sy] || sx >= 10 || sy >= 10)return;
	if (m[sx][sy] == '#')return;
	if (tmp>res)return;
	if (sx == tx&&sy == ty){ if (tmp<res)res = tmp; return; }
	visited[sx][sy] = 1;
	find_path(m, sx - 1, sy, tx, ty, tmp + 1);
	find_path(m, sx, sy - 1, tx, ty, tmp + 1);
	find_path(m, sx + 1, sy, tx, ty, tmp + 1);
	find_path(m, sx, sy + 1, tx, ty, tmp + 1);
	visited[sx][sy] = 0;
}
int main(){
	string s;
	while (cin >> s){
		res = __INT_MAX__;
		vector<vector<char>>m(10, vector<char>(10));
		for (int i = 0; i<10; i++){
			for (int j = 0; j<10; j++){
				if (i == 0)m[i][j] = s[j];
				else cin >> m[i][j];
			}
		}
		find_path(m, 0, 1, 9, 8, 0);
		cout << res << endl;
	}
	return 0;
}