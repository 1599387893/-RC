//��Сд��ĸ����ƥ�䣬ֱ�Ӻ���
//����д��ĸ����ƥ�䣬���� falsefalse
//������Ƿ񵽴�ĩβ

class Solution {
public:
	struct TreeNode {
		bool end;
		vector<TreeNode*> children;
		TreeNode() : end(false), children(128, nullptr) {}
		void insert(string& s) {
			TreeNode *p = this;
			for (int i = 0; i < s.length(); ++i) {
				if (!p->children[s[i]]) p->children[s[i]] = new TreeNode; // ����˴�����Ҫ if() �ж�
				p = p->children[s[i]];
			}
			p->end = true;
		}
		bool find(string& s) {
			TreeNode *p = this;
			for (int i = 0; i < s.length(); ++i) {
				if (s[i] > 96) {
					if (!p->children[s[i]]) continue;
					p = p->children[s[i]];
				}
				else {
					if (!p->children[s[i]]) return false;
					p = p->children[s[i]];
				}
			}
			return p->end;
		}
	};
	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		TreeNode *Trie = new TreeNode;
		Trie->insert(pattern);
		vector<bool> res(queries.size());
		transform(queries.begin(), queries.end(), res.begin(),
			[&](string& s){return Trie->find(s); });
		return res;
	}
};
