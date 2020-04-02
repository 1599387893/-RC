class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		vector<vector<int>> temp(board.size(), vector<int>(board[0].size(), 0));
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j<board[i].size(); ++j)
			{
				int count = 0; // ��Χ��ϸ����
				if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1)
					count++;
				if (i - 1 >= 0 && board[i - 1][j] == 1)
					count++;
				if (i - 1 >= 0 && j + 1<board[i].size() && board[i - 1][j + 1] == 1)
					count++;
				if (j + 1<board[i].size() && board[i][j + 1] == 1)
					count++;
				if (j + 1<board[i].size() && i + 1<board.size() && board[i + 1][j + 1] == 1)
					count++;
				if (i + 1<board.size() && board[i + 1][j] == 1)
					count++;
				if (i + 1<board.size() && j - 1 >= 0 && board[i + 1][j - 1])
					count++;
				if (j - 1 >= 0 && board[i][j - 1] == 1)
					count++;
				if (board[i][j] == 1) //��ʱΪ��ϸ��
				{
					if (count<2)
						temp[i][j] = 0;
					else if (count>3)
						temp[i][j] = 0;
					else
						temp[i][j] = 1;
				}
				else //��ʱΪ��ϸ��
				{
					if (count == 3)
						temp[i][j] = 1;
				}
			}
		}
		board = temp;
	}
};