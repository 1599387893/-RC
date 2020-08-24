//��ͨ����
class MapSum {
public:
	map<string, int> m;
	/** Initialize your data structure here. */
	MapSum() {
	}

	void insert(string key, int val) {
		m[key] = val;
	}

	int sum(string prefix) {
		int res = 0;
		string s;
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			s = it->first;
			if (!s.find(prefix))
				res += it->second;
		}
		return res;
	}
};

/**
* Your MapSum object will be instantiated and called as such:
* MapSum* obj = new MapSum();
* obj->insert(key,val);
* int param_2 = obj->sum(prefix);
*/



//�ֵ�������
class MapSum {
private:
	bool isEnd; // �Ƿ�Ϊ���һ����ĸ
	MapSum* next[26]; // ��ĸ��
	int value; // ��Ϊ���һ����ĸ�����Ӧ��ֵ

	// ������ȱ����㷨
	int dfs(MapSum* root) {
		if (!root) return 0; // �ݹ���������ǰ���ʵ�MapSumΪ�գ���ֱ�ӷ���0

		int res = 0;
		if (root->isEnd) res += root->value; // ����ǰ�ڵ㲻Ϊ����isEnd���������ֵ
		for (MapSum* cur : root->next) { // �ٱ�����ǰ�ڵ��next���������е�MapSum
			res += dfs(cur);
		}

		return res;
	}
public:
	/** Initialize your data structure here. */
	MapSum() {
		isEnd = false;
		memset(next, 0, sizeof(next));
		value = 0;
	}

	void insert(string key, int val) {
		MapSum* node = this;
		for (char ch : key) {
			if (node->next[ch - 'a'] == NULL) {
				node->next[ch - 'a'] = new MapSum();
			}
			node = node->next[ch - 'a'];
		}
		node->isEnd = true;
		node->value = val; // ��Ƚ�������ǰ׺����ֻ��������һ��value����
	}

	int sum(string prefix) {
		MapSum* node = this;
		for (char ch : prefix) {
			if (node->next[ch - 'a'] == NULL) return 0;
			node = node->next[ch - 'a'];
		}
		return dfs(node);
	}
};