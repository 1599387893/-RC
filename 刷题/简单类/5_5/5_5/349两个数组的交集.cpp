class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		//先排序，在使用指针移动求交集
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int pos1 = 0, pos2 = 0;
		set<int> s;
		vector<int> res;
		while (pos1 < nums1.size() && pos2 < nums2.size())
		{
			if (nums1[pos1] == nums2[pos2])
			{
				s.insert(nums1[pos1]);
				pos1++;
				pos2++;
			}
			else if (nums1[pos1]<nums2[pos2])
				pos1++;
			else
				pos2++;
		}
		for (auto it = s.begin(); it != s.end(); ++it)
			res.push_back(*it);
		return res;
	}
};

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> us(nums1.begin(), nums1.end());
		vector<int> res;
		for (auto i : nums2)
			if (us.erase(i))
				res.push_back(i);
		return res;
	}
};


class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s1(nums1.begin(), nums1.end());
		set<int> s2(nums2.begin(), nums2.end());
		vector<int> res;
		set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(res));
		//set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<vector<int>>(res,res.begin()));

		return res;
	}
};