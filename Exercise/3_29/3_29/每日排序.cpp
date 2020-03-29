//////#include<iostream>
//////#include<vector>
//////using namespace std;
//////
//////int Parition(vector<int>& arr, int left, int right)
//////{
//////	int& key = arr[right - 1];
//////	int begin = left, end = right - 1;
//////	while (begin < end)
//////	{
//////		while (begin < end && arr[begin] <= key)
//////			begin++;
//////		while (begin < end && arr[end] > key)
//////			end--;
//////		if (begin != end)
//////			swap(arr[begin], arr[end]);
//////	}
//////	return begin;
//////}
//////void QSort(vector<int>& arr, int left, int right)
//////{
//////	if (left < right)
//////	{
//////		int mid = Parition(arr, left, right);
//////		QSort(arr, left, mid);
//////		QSort(arr, mid + 1, right);
//////	}
//////}
//////
//////void Adjust(vector<int>&arr, int size, int parent)
//////{
//////	int child = parent * 2 + 1;
//////	while (child < size)
//////	{
//////		if (child + 1 < size && arr[child] > arr[child + 1])
//////			child++;
//////		if (arr[parent] > arr[child])
//////			swap(arr[child], arr[parent]);
//////		parent = child;
//////		child = parent * 2 + 1;
//////	}
//////}
//////void HeapSort(vector<int>& arr)
//////{
//////	for (int i = arr.size() / 2 - 1; i >= 0; --i)
//////		Adjust(arr, arr.size(), i);
//////	for (int i = arr.size() - 1; i > 0; --i)
//////	{
//////		swap(arr[i], arr[0]);
//////		Adjust(arr, i, 0);
//////	}
//////}
//////void merge(vector<int>& arr, int left, int mid, int right)
//////{
//////	vector<int> temp;
//////	for (int i = left; i <= right; ++i)
//////		temp.push_back(arr[i]);
//////	int l1 = left, l2 = mid + 1, r1 = mid, r2 = right;
//////	for (int i = left; i <= right; ++i)
//////	{
//////		if (l1 > mid)
//////			arr[i] = temp[(l2++) - left];
//////		else if (l2 > right || temp[l1 - left] > temp[l2 - left])
//////			arr[i] = temp[(l1++) - left];
//////		else
//////			arr[i] = temp[(l2++) - left];
//////	}
//////}
//////void MergeSort(vector<int>& arr, int left, int right)
//////{
//////	if (left < right)
//////	{
//////		int mid = left + (right - left) / 2;
//////		MergeSort(arr, left, mid);
//////		MergeSort(arr, mid + 1, right);
//////		merge(arr, left, mid, right);
//////	}
//////}
//////int main()
//////{
//////	vector<int> arr{2,5,8,1,3,4,6,7,9,0};
//////	//QSort(arr, 0, arr.size());
//////	//HeapSort(arr);
//////	MergeSort(arr, 0, arr.size() - 1);
//////	for (const auto c : arr)
//////		cout << c << " ";
//////	cout << endl;
//////	cin >> arr[0];
//////	return 0;
//////}
////
////#include<iostream>
////#include<string>
////#include<vector>
////#include<map>
////#include<algorithm>
////using namespace std;
////
////struct Node
////{
////	int x;
////	int y;
////	int w;
////	int h;
////	int ID;
////	bool type; //0为图片，1为文本
////	string Name;
////};
////typedef struct Node Node;
////
////
////int CountSame(const vector<struct Node>& UI)
////{
////	int countImage = 0;
////	int countText = 0;
////	for (size_t i = 0; i < UI.size(); ++i)
////	{
////		if (!UI[i].type)
////		{
////			for (size_t j = i + 1; j < UI.size(); ++j)
////				if ((UI[i].x == UI[j].x) && \
////					(UI[i].y == UI[j].y) && \
////					(UI[i].w == UI[j].w) && \
////					(UI[i].h == UI[j].h) && \
////					(UI[i].Name == UI[j].Name))
////					countImage++;
////		}
////		else
////		{
////			for (size_t j = i + 1; j < UI.size(); ++j)
////				if ((UI[i].x == UI[j].x) && \
////					(UI[i].y == UI[j].y) && \
////					(UI[i].w == UI[j].w) && \
////					(UI[i].h == UI[j].h))
////					countText++;
////		}
////	}
////	return (countImage + countText);
////}
////
////
////int main()
////{
////	int N, M;//(N:表示子节点个数，M:表示M个贴图)
////	vector<struct Node> UI; //保存所有的节点
////	map<string, int> instanceID; //保存贴图的ID
////	int id; // 字体ID
////	string s; //中间变量
////	int DC = 0; //DrawCall次数
////
////	//接收N行数据
////	for (int i = 0; i < N; ++i)
////	{
////		Node temp;
////		cin >> s;
////		if (s == "Image")
////		{
////			temp.type = 0;
////			cin >> temp.x >> temp.y >> temp.w >> temp.h >> temp.Name;
////		}
////		else
////		{
////			temp.type = 1;
////			cin >> temp.x >> temp.y >> temp.w >> temp.h;
////		}
////		UI.push_back(temp);
////	}
////	//接收贴图ID
////	for (int i = 0; i<M; ++i)
////	{
////		cin >> s >> id;
////		instanceID.insert(pair<string, int>(s, id));
////	}
////	//接收字体ID
////	cin >> id;
////	//将ID更新到每个节点中
////	for (auto node : UI)
////	{
////		if (node.type)
////			node.ID = id;
////		else
////			node.ID = instanceID[node.Name];
////	}
////
////	DC = UI.size();
////	DC -= CountSame(UI);
////
////	cout << DC << endl;
////	return 0;
////}
//
//
//
//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//
//struct classcomp {
//	bool operator() (const int p1, const int p2) const
//	{
//		return p1 > p2;
//	}
//};
//
//int main()
//{
//	int N, T, res = 0;
//	int L, E;
//	int time = 0; // 计时器
//	map<int, int, classcomp> m;
//	cin >> N >> T;
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> L >> E;
//		m.insert(pair<int, int>(E, L));
//	}
//	while (!m.empty())
//	{
//		auto it = m.begin();
//		if (time < (*it).second)
//		{
//			res += (*it).first;
//			time += (*it).second;
//		}
//		m.erase(m.begin());
//	}
//	cout << res << endl;
//	return 0;
//}
//
//
//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//
//int main()
//{
//	string s1, s2, res;
//	int n;
//	map<char, int> m;
//	cin >> n >> s1 >> s2;
//	for (const auto c : s2)
//		m[c]++;
//	for (int i = 3; i <= n; ++i)
//	{
//		for (const auto c : s1)
//			m[c]++;
//		res = s1 + s2;
//		s1 = s2;
//		s2 = res;
//	}
//	for (auto pa = m.begin(); pa != m.end(); ++pa)
//		cout << pa->first << ":" << pa->second << endl;
//	return 0;
//}