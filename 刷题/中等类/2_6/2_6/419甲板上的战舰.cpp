
//这题可以看做是数战舰的头部，战舰的头部只有两种形式，一种是上、左、右为空，一种是左、上、下为空。
#if 0
class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		int count = 0;
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[i].size(); ++j)
				if (board[i][j] == 'X')
				{
			if ((i>0 && board[i - 1][j] == 'X') || (j>0 && board[i][j - 1] == 'X'))
				continue;
			count++;
				}
		return count;
	}
};
#endif
#if 0
class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		int count = 0;
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[i].size(); ++j)
				if ((board[i][j] == 'X') && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.'))
					count++;
		return count;
	}
};
#endif