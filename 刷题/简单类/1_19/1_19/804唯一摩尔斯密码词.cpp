#if 0
class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		vector<string> dict{ ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
		set<string> ret;
		for (auto arr : words)
		{
			string temp;
			for (auto c : arr)
				temp += dict[c - 97];
			ret.insert(temp);
		}
		return ret.size();
	}
};
#endif