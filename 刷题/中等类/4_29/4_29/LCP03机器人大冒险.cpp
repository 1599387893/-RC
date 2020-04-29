//方法一：超时
class Solution {
public:
	bool IsCrush(vector<vector<int>>& obstacles, const int row, const int col)
	{
		for (auto arr : obstacles)
			if (arr[0] == row && arr[1] == col)
				return true;
		return false;
	}
	bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
		int pos = 0, row = 0, col = 0;
		while (row <= x && col <= y)
		{
			if (row == x && col == y)
				return true;
			if (IsCrush(obstacles, row, col))
				return false;
			//向上移动
			if (command[pos%command.size()] == 'U')
				col++;
			//向右移动
			else
				row++;
			pos++;
		}
		return false;
	}
};


//方法二：
//最终到达终点，会执行command命令K+1(k>=0)次,我们只需要判断最后一遍执行command命令能否到达终点；
//再反过头来，处理过程中的障碍
class Solution {
public:
	bool Togo(const string& command, const int row, const int col, const int dest_x, const int dest_y)
	{
		int pos_x = 0, pos_y = 0, k = 0;
		//判断需要执行command命令几次，注意除零错误
		k = row == 0 ? (col == 0 ? 0 : dest_y / col) : (col == 0 ? dest_x / row : min(dest_x / row, dest_y / col));
		//将前n次command命令的执行跳过，只处理最后一遍命令。
		pos_x = row*k;
		pos_y = col*k;
		for (int i = 0; i < command.size(); ++i)
		{
			if (pos_x == dest_x && pos_y == dest_y)
				return true;
			command[i] == 'U' ? pos_y++ : pos_x++;
		}
		if (pos_x == dest_x && pos_y == dest_y)
			return true;
		return false;
	}
	bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
		//先得出执行一次command命令所到达的位置
		int row = 0, col = 0;
		for (auto c : command)
			c == 'U' ? col++ : row++;

		//忽略有障碍的情况，判断是否能够到达终点
		if (!Togo(command, row, col, x, y)) return false;

		//此时表示无障碍可以到达，处理有障碍情况
		int r, c;
		for (auto arr : obstacles)
		{
			r = arr[0];
			c = arr[1];
			if (r>x || c>y) continue;
			if (Togo(command, row, col, r, c)) return false;
		}
		return true;
	}
};
