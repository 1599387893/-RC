class Solution {
public:
	int numRookCaptures(vector<vector<char>>& board) {
		int count = 0;
		int x, y;
		//���ҵ������ֱ����ĸ�����������ɫ�෴���䣬
		//����ҵ���ɫ���䣬������һ���������߽����������ֹͣѰ�ң�
		for (int i = 0; i < board.size(); ++i)
		{
			auto pos = find(board[i].begin(), board[i].end(), 'R');
			if (pos != board[i].end())
			{
				x = i;
				y = pos - board[i].begin();
			}
		}
		//��       
		for (int i = y; i >= 0; --i)
		{
			if (board[x][i] == 'B')
				break;
			else if (board[x][i] == 'p')
			{
				count++;
				break;
			}
		}
		//��
		for (int i = y; i<board.size(); ++i)
		{
			if (board[x][i] == 'B')
				break;
			else if (board[x][i] == 'p')
			{
				count++;
				break;
			}
		}
		//��
		for (int i = x; i >= 0; --i)
		{
			if (board[i][y] == 'B')
				break;
			else if (board[i][y] == 'p')
			{
				count++;
				break;
			}
		}
		//��
		for (int i = x; i < board[x].size(); ++i)
		{
			if (board[i][y] == 'B')
				break;
			else if (board[i][y] == 'p')
			{
				count++;
				break;
			}
		}
		return count;
	}
};