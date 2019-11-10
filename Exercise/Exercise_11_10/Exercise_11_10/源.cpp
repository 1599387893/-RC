//#include<iostream>
//#include<string>
//using namespace std;
//
//string CountSubstr(string& s)
//{
//	if (s.size() == 0)
//		return nullptr;
//	string ret;
//	for (int i = 0; i < s.size(); ++i)
//	{
//		int count = 0;
//		int j = i;
//		while ((j<s.size()) && (s[j] >= '0' && s[j] <= '9'))
//		{
//			count++;
//			j++;
//		}
//		if (count > ret.size())
//		{
//			ret = s.substr(i, j);
//		}
//		i = j;
//	}
//	return ret;
//}
//
//int main()
//{
//	string s;
//	while (cin >> s)
//		cout << CountSubstr(s) << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int MoreThanHalfNum_Solution(vector<int> numbers) {
//	sort(numbers.begin(), numbers.end());
//	return numbers[numbers.size() / 2];
//}
//
//int main()
//{
//	vector<int> v{1,2,3,2,2,2,5,4,2};
//	cout << MoreThanHalfNum_Solution(v) << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int MoreThanHalfNum_Solution(vector<int> numbers)
//{
//	if (numbers.empty())
//		return 0;
//	if (numbers.size() == 1)
//		return numbers[0];
//	string s;
//	vector<int> count;
//	count.resize(numbers.size(), 0);
//	for (int i = 0; i < numbers.size(); ++i)
//	{
//		auto it = s.find(itoa(numbers[i]));
//		if (it != string::npos)
//		{
//			count[it - s.begin()]++;
//		}
//		else
//		{
//			count[s.size() - 1] = 1;
//		}
//	}
//	int max = 0;
//	int j = 0;
//	for (int i = 0; i < count.size(); ++i)
//		if (count[i] > max)
//		{
//		max = count[i];
//		j = i;
//		}
//	if (max > numbers.size() / 2)
//		return atoi(s[j]);
//	return 0;
//}
//int main()
//{
//
//}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int MoreThanHalfNum_Solution(vector<int> numbers)
//{
//	if (numbers.empty())
//		return 0;
//	if (numbers.size() == 1)
//		return numbers[0];
//	int result = numbers[0];
//	int times = 1;
//	for (int i = 1; i < numbers.size(); ++i)
//	{
//		if (times == 0)
//		{
//			result = numbers[i];
//			times = 1;
//		}
//		else if (numbers[i] == result)
//			times++;
//		else
//			times--;
//	}
//	int count = 0;
//	for (int i = 0; i < numbers.size(); ++i)
//		if (numbers[i] == result)
//			count++;
//	return (count>numbers.size() / 2) ? result : 0;
//}