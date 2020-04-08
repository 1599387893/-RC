class Solution {
public:
	string reverseWords(string s) {
		int k = 0;
		for (int i = 0; i < s.size(); ++i){
			while (i < s.size() && s[i] == ' ') ++i;  //�ҵ���һ���ǿո��ַ�
			if (i == s.size()) break;
			int j = i;
			while (j < s.size() && s[j] != ' ') ++j;    //����1���ǿյ���
			reverse(s.begin() + i, s.begin() + j);      //��ת1������
			if (k) s[k++] = ' ';
			while (i < j) s[k++] = s[i++];      //��ת���1�����ʸ���s[k]
		}
		s.erase(s.begin() + k, s.end());   //ɾ�� k����ո�
		reverse(s.begin(), s.end());
		return s;
	}
};