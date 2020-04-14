class Solution {
public:
	vector<string> permutation(string s) {
		vector<string> res;
		sort(s.begin(), s.end());
		do
		{
			res.push_back(s);
		} while (next_permutation(s.begin(), s.end()));
		return res;
	}
};

//�ݹ�+�ж��ظ��ַ�
class Solution {
public:
	bool Judge(string& s, int from, int to)
	{
		//��֤ÿ���ַ�ֻ�ڴ�λ�̶�һ��
		for (int i = from; i<to; ++i)
			if (s[i] == s[to]) return true;
		return false;
	}
	void BackTrack(vector<string>& res, string& s, int from, int to)
	{
		if (from > to)
			return;
		if (from == to)
		{
			res.push_back(s);
			return;
		}
		for (int i = from; i <= to; ++i)
		{
			//���ַ��������ظ��ַ�ʱ�����з�����Ҳ�����ظ�������
			//Ϊ�ų��ظ����������ڹ̶�ĳλ�ַ�ʱ��
			//��֤��ÿ���ַ�ֻ�ڴ�λ�̶�һ�Ρ����������ظ��ַ�ʱ������
			if (Judge(s, from, i)) continue;

			swap(s[from], s[i]);
			BackTrack(res, s, from + 1, to);
			swap(s[from], s[i]);
		}
	}
	vector<string> permutation(string s) {
		vector<string> res;
		if (s.empty())   return res;
		BackTrack(res, s, 0, s.size() - 1);
		return res;
	}
};

//�ݹ�+�����ռ�set
class Solution {
public:
	void BackTrack(set<string>& ss, string& s, int from, int to)
	{
		if (from > to)
			return;
		if (from == to)
		{
			ss.insert(s);
			return;
		}
		for (int i = from; i <= to; ++i)
		{
			swap(s[from], s[i]);
			BackTrack(ss, s, from + 1, to);
			swap(s[from], s[i]);
		}
	}
	vector<string> permutation(string s) {
		vector<string> res;
		if (s.empty())   return res;
		set<string> ss;
		BackTrack(ss, s, 0, s.size() - 1);
		for (auto it = ss.begin(); it != ss.end(); ++it)
			res.push_back(*it);
		return res;
	}
};