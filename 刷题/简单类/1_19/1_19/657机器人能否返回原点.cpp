#if 0
class Solution {
public:
	bool judgeCircle(string moves) {
		int row = 0;
		int col = 0;
		for (auto c : moves)
		{
			if (c == 'R')
				row++;
			if (c == 'L')
				row--;
			if (c == 'U')
				col++;
			if (c == 'D')
				col--;
		}
		if (col == 0 && row == 0)
			return true;
		return false;
	}
};
class Solution {
public:
	bool judgeCircle(string moves) {
		int l = count(moves.begin(), moves.end(), 'L');
		int r = count(moves.begin(), moves.end(), 'R');
		int u = count(moves.begin(), moves.end(), 'U');
		int d = count(moves.begin(), moves.end(), 'D');
		if (l == r && u == d)
			return true;
		return false;
	}
};
#endif