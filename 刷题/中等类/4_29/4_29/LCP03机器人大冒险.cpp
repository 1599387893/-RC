//����һ����ʱ
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
			//�����ƶ�
			if (command[pos%command.size()] == 'U')
				col++;
			//�����ƶ�
			else
				row++;
			pos++;
		}
		return false;
	}
};


//��������
//���յ����յ㣬��ִ��command����K+1(k>=0)��,����ֻ��Ҫ�ж����һ��ִ��command�����ܷ񵽴��յ㣻
//�ٷ���ͷ������������е��ϰ�
class Solution {
public:
	bool Togo(const string& command, const int row, const int col, const int dest_x, const int dest_y)
	{
		int pos_x = 0, pos_y = 0, k = 0;
		//�ж���Ҫִ��command����Σ�ע��������
		k = row == 0 ? (col == 0 ? 0 : dest_y / col) : (col == 0 ? dest_x / row : min(dest_x / row, dest_y / col));
		//��ǰn��command�����ִ��������ֻ�������һ�����
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
		//�ȵó�ִ��һ��command�����������λ��
		int row = 0, col = 0;
		for (auto c : command)
			c == 'U' ? col++ : row++;

		//�������ϰ���������ж��Ƿ��ܹ������յ�
		if (!Togo(command, row, col, x, y)) return false;

		//��ʱ��ʾ���ϰ����Ե���������ϰ����
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
