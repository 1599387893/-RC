#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0, m = 0;
	cin >> n;
	vector<int> arr1(n);
	for (int i = 0; i < n; ++i)
		cin >> arr1[i];
	cin >> m;
	vector<int> arr2(m);
	for (int i = 0; i < m; ++i)
		cin >> arr2[i];
	vector<int> res;
	int pos1 = 0, pos2 = 0;
	while (pos1 < n && pos2 < m)
	{
		if (arr1[pos1] > arr2[pos2])
			pos1++;
		else if (arr1[pos1] < arr2[pos2])
			pos2++;
		else
		{
			res.push_back(arr1[pos1]);
			pos1++;
			pos2++;
		}
	}
	for (auto num : res)
		cout << num << " ";
	cout << endl;
	return 0;
}


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	unordered_map<int, vector<int>> um;
	int person = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> person; //每个小团队的人数
		int temp = 0;
		for (int j = 0; j < person; ++j)
		{
			cin >> temp;
			um[temp].push_back(i);
		}
	}
	cout << um.size() << endl;
}



#include <iostream>
#include <string>
#include <unordered_mutlimap>
#include <queue>
using namespace std;

bool comp(const pair<int, string>& p1, const pair<int, string>& p2)
{
	if (p1.first < p2.first)
		return true;
	return p1.second < p2.second;
}
int main()
{
	int N = 0, K = 0;
	cin >> N >> K;
	unordered_mutlimap<string, int> strs;
	string s;
	while (getline(cin, s))
		strs[s]++;
	priority_queue<pair<int, string>, unordered_mutlimap<string, int>, comp> pq;
	auto
		for (int i = 0; i < k; ++i)
			pq.push();

}



#include <iostream>
#include <string>
#include <unordered_map>
#include <map> 
#include <algorithm>
using namespace std;

bool comp(const pair<int, string>& p1, const pair<int, string>& p2)
{
	if (p1.first < p2.first)
		return true;
	return p1.second < p2.second;
}
int main()
{
	int N = 0, K = 0;
	cin >> N >> K;
	unordered_map<string, int> strs;
	string s;
	for (int i = 0; i < N; ++i)
	{
		cin >> s;
		strs[s]++;
	}
	vector<pair<int, string>> arr;
	for (auto p : strs)
		arr.push_back(make_pair(p.second, p.first));
	sort(arr.begin(), arr.end(), comp);
	for (int i = 0; i < K; ++i)
		cout << arr[i].second << " " << arr[i].first << endl;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < K; ++i)
		cout << arr[i].second << " " << arr[i].first << endl;
	return 0;
}
#endif


#if 0
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct classcomp {
	bool operator()(const pair<int, string>& p1, const pair<int, string>& p2)
	{
		if (p1.first < p2.first)
			return true;
		return p1.second < p2.second;
	}
};
bool comp(const pair<int, string>& p1, const pair<int, string>& p2)
{
	if (p1.first < p2.first)
		return true;
	return p1.second < p2.second;
}
int main()
{
	if (comp(make_pair(1, "1"), make_pair(2, "2")))
		cout << "f" << endl;
	int N = 0, K = 0;
	cin >> N >> K;
	unordered_map<string, int> strs;
	string s;
	for (int i = 0; i < N; ++i)
	{
		cin >> s;
		strs[s]++;
	}
	bool(*compptr)(const pair<int, string>&, const pair<int, string>&) = comp;
	multiset<pair<int, string>, bool(*)(const pair<int, string>&, const pair<int, string>&)> ms(compptr);
	if (comp(make_pair(2, "1"), make_pair(2, "2")))
		cout << "f" << endl;
	for (auto p : strs)
		ms.insert(make_pair(p.second, p.first));
	auto frontK = ms.begin();
	auto backK = ms.rbegin();
	while (K--)
	{
		cout << (*frontK).second << " " << (*frontK).first << endl;
		frontK++;
	}
	while (K--)
	{
		cout << (*backK).second << " " << (*backK).first << endl;
		backK++;
	}
	return 0;
}
#endif
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i)
	{
		int pos = 0;
		priority_queue< int, vector<int>, greater<int> >pq;
		while (pq.size() < (n / 2) && pos < n)
		{
			if (pos == i)
				continue;
			pq.push(arr[pos]);
			pos++;
		}
		while (pos < n)
		{
			if (pq.top() < arr[pos])
			{
				pq.pop();
				pq.push(arr[pos]);
			}
			pos++;
		}
		cout << pq.top() << endl;
	}
	return 0;
}