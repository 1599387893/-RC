//1
//�����壨��һ����3*3�����Ͻ��е�������Ϸ��������ͬ�ʹ����ʤ����
//����ʾ����
//			[[1.0.1],[1.-1.-1],[1.-1.0]]
//���ʾ����
//			true

#include<iostream>
#include<vector>
using namespace std;

class Board {
public:
	bool checkWon(vector<vector<int> > board) 
	{
		// write code here
		if (board[0][0] + board[1][1] + board[2][2] == 3)
			return true;
		if (board[0][2] + board[1][1] + board[2][0] == 3)
			return true;
		for (int i = 0; i < 3; ++i)
		{
			if (board[i][0] + board[i][1] + board[i][2] == 3)
				return true;
			if (board[0][i] + board[1][i] + board[2][i] == 3)
				return true;
		}
		return false;
	}
};

