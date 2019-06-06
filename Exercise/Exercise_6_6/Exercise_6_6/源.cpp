#if 0
#include<iostream>
using namespace std;

bool judge(int n)
{
	int temp = 1;
	for (int i = 2; i<n / 2; ++i)
		if (n%i == 0)
			temp += (i + (n / i));
	if (temp == n)
		return true;
	return false;
}
int Perfect_number_count(int n)
{
	int count = 0;
	for (int i = 1; i <= n; ++i)
		if (judge(i))
			++count;
	return count;
}
int main()
{
	int n = 0;
	int count = 0;
	while (cin >> n)
	{
		count = Perfect_number_count(n);
		cout << count << endl;
	}
	system("pause");
	return 0;
}
#endif

链接：https://www.nowcoder.com/questionTerminal/7299c12e6abb437c87ad3e712383ff84
来源：牛客网

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int num_s;
	while (cin >> num_s) {
		int temps = 0;
		for (int i = 2; i < num_s; i++) {
			vector <int> t_s;
			for (int ii = 1; ii <= sqrt(i); ii++) {
				if (i % ii == 0) {
					t_s.push_back(ii);
					if (i / ii != i) {
						t_s.push_back(i / ii);
					}
				}
			}
			int sum_s = 0;
			for (int iii = 0; iii < t_s.size(); iii++) {
				sum_s = sum_s + t_s[iii];
			}
			if (sum_s == i) {
				temps++;
			}
		}
		cout << temps << endl;
	}
	system("pause");
	return 0;
}