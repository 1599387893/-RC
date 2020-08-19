#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int n = (int)a.size(), m = (int)b.size();
	vector<int> arr(n + m, 0);
	
	//模拟乘法运算，保存a和b每一位相乘的结果
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			arr[n + m - i - j - 2] = (a[i] - '0') * (b[j] - '0');

	for (int i = 0, c = 0; i < (int)arr.size(); ++i)
	{
		arr[i] += c;
		c = arr[i] / 10; //取到先前进的那一位
		arr[i] %= 10; //最终只保留最高一位（十位）
	}

	bool p = true;
	for (int i = (int)arr.size() - 1; i >= 0; --i)
	{
		if (p)
		{
			if (i && !arr[i])
				continue; //有效数字之前的0没有意义 不输出
			else
			{
				p = false;
				cout << arr[i];
			}
		}
		else
			cout << arr[i];
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif


//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	vector<int> s(n + m);
	
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			s[n + m - i - j - 2] += (a[i] - '0')*(b[j] - '0');
	for (int i = 0, c = 0; i<n + m; i++){
		s[i] += c;
		c = s[i] / 10;
		s[i] %= 10;
	}
	bool p = true;
	for (int i = n + m - 1; i >= 0; i--){
		if (p){
			if (i && !s[i])
				continue;
			else{
				p = false;
				cout << s[i];
			}
		}
		else
			cout << s[i];
	}
	cout << endl;
	system("pause");

	return 0;
}