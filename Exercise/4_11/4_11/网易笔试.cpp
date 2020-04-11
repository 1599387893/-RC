#if 0
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void GetFar(vector<vector<int>>& board, vector<vector<double>>& far, const int& x, const int& y)
{
	for (size_t i = 0; i < board.size(); ++i)
	{
		for (size_t j = 0; j < board.size(); ++j)
		{
			//����õ�û�в���Ʒ����Ҫ���㣻
			if (board[i][j] == 0)
				continue;
			far[i][j] = sqrt(((x-i)*(x-i)) + ((y-j)*(y-j)));
		}
	}
}
void Knife(vector<vector<int>>& board, vector<vector<double>>& far, int& L)
{
	int temp = 0;
	do{
		temp = L;
		for (size_t i = 0; i < board.size(); ++i)
			for (size_t j = 0; j < board.size(); ++j)
				if (board[i][j] != 0 && L >= far[i][j])
				{
					L += board[i][j];
					board[i][j] = 0;
				}
	} while (temp < L);
}
int main()
{
	int T, M, L, x, y;
	cin >> T;
	while (T--)
	{
		cin >> M >> L;
		vector<vector<int>> board(M, vector<int>(M, 0));
		vector<vector<double>> far(M, vector<double>(M, 0));//��������ÿһ�㵽���ǵ�λ�ã�
		for (int i = 0; i < M*M; ++i)
			cin >> board[i / M][i%M];
		cin >> x >> y;
		GetFar(board, far, x, y);//���ÿһ�㵽��������λ�õľ��룻
		Knife(board, far, L);//�ӽ��ó��ȣ�
		cout << L << endl;
	}
	return 0;
}
#endif