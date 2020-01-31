#if 0
class Solution {
public:
	string toLowerCase(string str) {
		string res(str);
		transform(res.begin(), res.end(), res.begin(), ::tolower);
		return  res;
	}
};
#endif

#if 0
class Solution {
public:
	string toLowerCase(string str) {
		string res(str);
		for (int i = 0; i < res.size(); ++i)
			if (res[i] >= 'A' && res[i] <= 'Z')
				res[i] += 32;
		return res;
	}

};
#endif

#if 0
class Solution {
public:
	string toLowerCase(string str) {
		string res(str);
		for (int i = 0; i < res.size(); ++i)
			res[i] = tolower(res[i]);
		return res;
	}

};
#endif

#if 0
class Solution {
public:
	string toLowerCase(string str) {
		string res(str);
		for (int i = 0; i < res.size(); ++i)
			if (res[i] >= 'A' && res[i] <= 'Z')
				res[i] ^= 32;
		return res;
	}

};
#endif

#if 0
class Solution {
public:
	string toLowerCase(string str) {
		string res(str);
		for (int i = 0; i < res.size(); ++i)
			res[i] |= 32;
		return res;
	}

};
#endif