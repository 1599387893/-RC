//2
//�����ַ�������һ���ַ����еĵ���ǰ�󽻻����Ե���Ϊ��λ��
//����ʾ����
//			i like beijing
//���ʾ����
//			beijing like i

#if 0
//����һ
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); ++i)
	{
		int j = i;
		while(s[j] != ' '&& j<s.size())
			++j;
		reverse(&s[i],&s[j]);
		i = j;
	}
	cout << s << endl;
	system("pause");
	return 0;
}


//������
#include <iostream>
#include <string>
using namespace std;

// cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢�����������
int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
		s2 = s1 + " " + s2;
	cout << s2 << endl;
	return 0;
}
#endif