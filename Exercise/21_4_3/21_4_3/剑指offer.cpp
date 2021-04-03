// 03
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int ret = -1;
		for (int i = 0; i < nums.size(); ++i)
		{

			while (nums[i] != i)
			{
				if (nums[nums[i]] != nums[i])
				{
					swap(nums[i], nums[nums[i]]);
					i = nums[i];
				}
				else
				{
					ret = nums[i];
					break;
				}
			}
		}
		return ret;
	}
};


//04
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int row = 0;
		int col = matrix[0].size() - 1;
		while (row < matrix.size() && col >= 0)
		{
			if (target == matrix[row][col])
				return true;
			else if (target > matrix[row][col])
				row++;
			else
				col--;
		}
		return false;
	}
};


//05
class Solution {
public:
	string replaceSpace(string s) {
		string ret;
		for (auto c : s)
		{
			if (c == ' ')
				ret += "%20";
			else
				ret += c;
		}
		return ret;
	}
};

//06
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	void reverseP(ListNode* head, vector<int>& res)
	{
		if (!head)
			return;
		else
			reverseP(head->next, res);
		res.push_back(head->val);
	}
	vector<int> reversePrint(ListNode* head) {
		vector<int> res;
		reverseP(head, res);
		return res;
	}
};


//011
class Solution {
public:
	int minArray(vector<int>& numbers) {
		int low = 0, high = numbers.size() - 1;
		int ret = 0, mid = 0;
		while (low < high)
		{
			mid = low + (high - low) / 2;
			if (numbers[mid] < numbers[high])
				high = mid;
			else if (numbers[mid] > numbers[high])
				low += 1;
			else
				high--;
		}
		return numbers[high];
	}
};


//012
class Solution {
public:
	bool dfs(vector<vector<char>>& board, int x, int y, string word, int pos)
	{
		if (x > board.size() - 1 || x < 0 || y > board[0].size() - 1 || y < 0 || pos == word.size() || board[x][y] != word[pos])
			return false;
		if (pos == word.size() - 1 && word[pos] == board[x][y])
			return true;
		char temp = board[x][y];
		board[x][y] = '0';
		if (dfs(board, x + 1, y, word, pos + 1) || dfs(board, x, y + 1, word, pos + 1) || dfs(board, x - 1, y, word, pos + 1) || dfs(board, x, y - 1, word, pos + 1))
			return true;
		board[x][y] = temp;
		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
				if (dfs(board, i, j, word, 0))
					return true;
		return false;
	}
};
