
#if 0
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if(ransomNote.empty())
			return true;
		if(magazine.empty())
			return false;
		vector<int> arr;
		arr.resize(26,0);
		for(int i = 0 ;i < magazine.size();++i)
			arr[magazine[i]-97]++;
		for(int i = 0;i < ransomNote.size();++i)
		{
			arr[ransomNote[i]-97]--;
			if(arr[ransomNote[i]-97]<0)
				return false;
		}
		return true;
	}
};
#endif
#if 0
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if (ransomNote.empty())
			return true;
		if (magazine.empty())
			return false;
		for (int i = 0; i < ransomNote.size(); ++i)
		{
			if (magazine.find(ransomNote[i]) == string::npos)
				return false;
			else
				if (count(ransomNote.begin(), ransomNote.end(), ransomNote[i])>count(magazine.begin(), magazine.end(), ransomNote[i]))
					return false;
		}
		return  true;
	}
};
#endif