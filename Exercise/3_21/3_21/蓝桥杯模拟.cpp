////#include<iostream>
////#include<set>
////#include<vector>
////using namespace std;
////
////bool IsNine(int n)
////{
////	while (n)
////	{
////		if (n % 10 == 9)
////			return true;
////		n /= 10;
////	}
////	return false;
////}
////int main()
////{
////	int n = 2019;
////	int count = 0;
////	for (int i = 1; i <= n; ++i)
////	{
////		if (IsNine(i))
////			count++;
////	}
////	cout << count << endl;
////	cin >> n;
////	return 0;
////}
////
////#include<iostream>
////#include<string>
////#include<vector>
////using namespace std;
////bool IsYu(char& c)
////{
////	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
////		return true;
////	return false;
////}
////int main()
////{
////	string word;
////	vector<bool> part(4, false);
////	int n = 1;
////	cin >> word;
////	for (int i = 0; i < word.size(); ++i)
////	{
////		if (n == 1 || n == 3)
////		{
////			int j = i;
////			while (j < word.size() && !IsYu(word[j]))
////				j++;
////			if (i != j)
////			{
////				part[n-1] = true;
////				n++;
////			}
////			i = j;
////		}
////		if (n == 2 || n == 4)
////		{
////			int j = i;
////			while (j < word.size() && IsYu(word[j]))
////				j++;
////			if (i != j)
////			{
////				part[n-1] = true;
////				n++;
////			}
////			i = j;
////		}
////		if (n == 4 && part[n - 1])
////			break;
////	}
////	part[3] ? cout << "Yes" << endl : cout << "No" << endl;
////	cin >> word;
////	return 0;
////
////}
//
//
////#include<iostream>
////using namespace std;
////
////bool IsUp(int i)
////{
////	while (i>10)
////	{
////		if (i % 10 < (i / 10) % 10)
////			return false;
////		i /= 10;
////	}
////	return true;
////}
////int main()
////{
////	int n, count = 0;
////	cin >> n;
////	for (int i = 2; i < n; ++i)
////		if (IsUp(i))
////			count++;
////	cout << count << endl;
////	cin >> n;
////	return 0;
////}
//
////#include<iostream>
////#include<vector>
////using namespace std;
////bool IsThreeGroup(vector<int>& arr, int i)
////{
////	int step = 0;
////	for (int j = i - 1; j >= 0 && step<3;--j)
////		if (arr[i] > arr[j])
////		{
////			step++;
////			i = j;
////		}
////	if (step == 2)
////		return true;
////	return false;
////}
////int main()
////{
////	int n,count = 0;
////	vector<int> arr;
////	cin >> n;
////	arr.resize(n, 0);
////	for (int i = 0; i < n; ++i)
////		cin >> arr[i];
////	for (int i = arr.size()-1; i >= 2; --i)
////		if (IsThreeGroup(arr, i))
////			count++;
////	cout << count << endl;
////	cin >> n;
////	return 0;
////}
//
//#include<iostream>
//#include<vector>
//using namespace std;
//void Growup(vector<vector<char>>& land)
//{
//	int row = land.size();
//	int col = land[0].size();
//	for (int i = 0; i < row; ++i)
//	{
//		for (int j = 0; j < col; ++j)
//		{
//			if (land[i][j] == 'g')
//				continue;
//			if (i == 0 && j == 0 && (land[i + 1][j] == 'g' || land[i][j + 1] == 'g'))
//				land[i][j] = 'g';
//			else if (i == 0 && (land[i][j - 1] == 'g' || land[i][j + 1] == 'g' || land[i + 1][j] == 'g'))
//				land[i][j] = 'g';
//			else if (j == 0 && (land[i - 1][j] == 'g' || land[i + 1][j] == 'g' || land[i][j + 1] == 'g'))
//				land[i][j] = 'g';
//			else if (land[i][j - 1] == 'g' || land[i][j + 1] == 'g' || land[i + 1][j] == 'g' || land[i - 1][j] == 'g')
//				land[i][j] = 'g';
//		}
//	}
//}
//int main()
//{
//	int n, m, k;
//	cin >> n >> m;
//	vector<vector<char>> land(n, vector<char>(m));
//	for (int i = 0; i < n*m; ++i)
//		cin >> land[i / n][i%m];
//	cin >> k;
//	while (k--)
//		Growup(land);
//	for (const auto arr : land)
//	{
//		for (const auto c : arr)
//			cout << c;
//		cout << endl;
//	}
//	return 0;
//}