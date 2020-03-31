//递归+剪枝
#if 0

class Solution {
public:
	bool IsExist(vector<vector<char>>& board, int x, int y, string word, int pos)
	{
		if (x >= board.size() || y >= board[0].size() || x<0 || y<0 || board[x][y] != word[pos] || board[x][y] == '1')
			return false;
		if (pos == word.size() - 1)
			return true;
		char temp = board[x][y];
		board[x][y] = '1';
		bool flag = (IsExist(board, x + 1, y, word, pos + 1) || IsExist(board, x, y + 1, word, pos + 1) || \
			IsExist(board, x - 1, y, word, pos + 1) || IsExist(board, x, y - 1, word, pos + 1));
		board[x][y] = temp;
		return flag;
	}
	bool exist(vector<vector<char>>& board, string word) {
		if (word.size() == 0)
			return true;
		//先找到第一个字符的位置；
		for (int i = 0; i<board.size(); ++i)
			for (int j = 0; j<board[i].size(); ++j)
				if (word[0] == board[i][j] && IsExist(board, i, j, word, 0))
					return true;
		return false;
	}
};

#endif