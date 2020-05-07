class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		unordered_set<int> us;
		int pos = 0, count = 0, temp = 0;
		while (pos < arr.size())
		{
			temp = arr[pos];
			count = 0;
			while (pos < arr.size() && temp == arr[pos])
			{
				count++;
				pos++;
			}
			if (!us.insert(count).second)
				return false;
		}
		return true;
	}
};

class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> m;
		for (auto n : arr)
			m[n]++;
		set<int> s;
		for (auto p : m)
			s.insert(p.second);
		return m.size() == s.size();
	}
};