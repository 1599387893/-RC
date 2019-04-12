//#include<string>
//#include<iostream>
//using namespace std;

#if 0
int main()
{
	string s1;
	string s2("Hello!");
	string s3(s2);
	string s4(10,'a');
	string s5(s2, 2);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

	return 0;
}
#endif

#if 0
int main()
{
	string s("hello !!");
	
	cout << s << endl;
	cout << s.empty() << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	s.clear();
	cout << s << endl;
	cout << s.empty() << endl;
	s.resize(10, 'c');
	cout << s << endl;
	s.resize(5, 'c');
	cout<<s<<endl;
	return 0;
}
#endif

#if 0
int main()
{
	string s("hello");

	/*cout << s << endl;
	s.resize(10, 'c');
	cout << s << endl;
	s.resize(5, 'c');
	cout << s << endl;*/
	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	return 0;
}
#endif

#if 0
int main()
{
	string s("hello ");
	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	return 0;
}
#endif

#if 0
int main()
{
	string s("hello");
	const string s1("world");
	cout << s1[2] << endl;
	//s1[2] = 's';
	//cout << s1[2] << endl;
	cout << s[2] << endl;
	s[2] = 'm';
	cout << s[2] << endl;

	return 0;
}
#endif

#if 0
int main()
{
	string s("hello RC");
	s.push_back('a');
	//cout << s << endl;
	s.append("b");
	//cout << s << endl;
	s += 'c';
	//cout << s << endl;

	cout << s.find('R',3) << endl;
	cout << s.rfind('h',3) << endl;

	cout << s.substr(3, 20)<<endl;
	return 0;
}
#endif

#if 0
int main()
{
	// 获取file的后缀
	//string file1("string.cpp");
	//cout << file1 << endl;
	//cout << file1.substr(file1.find("."), file1.size() - file1.find(".")) << endl;

	// 取出url中的域名
	string url("http://www.cplusplus.com/reference/string/string/find/");
	size_t pos1 = url.find("://");
	pos1 += 3;
	size_t pos2 = url.find("/", pos1);
	cout << url.substr(pos1,pos2-pos1)<<endl;
	return 0;

}
#endif


#if 0
//反转字符串
void Swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	string s("Hi, RC");
	cout << s << endl;
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		Swap(&s[begin], &s[end]);
		begin++;
		end--;
	}
	cout << s << endl;

	return 0;
}
#endif


//
#if 0
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	size_t size = s.size();
	size_t pos1 = 0;
	while (pos1 <size)
	{
		size_t pos2 = 0;
		while (pos2<size)
		{
			if (pos1 == pos2 && s[pos1] != s[pos2])
			{
				pos2++;
				continue;
			}
			if (s[pos1] == s[pos2]&&pos1!=pos2)
				break;
			pos2++;
		}
		if (pos2==size)
			cout << s[pos2] << endl;
		pos1++;
	}
	cout << -1 << endl;

	system("pause");
}
#endif

#if 0
//求字符串最后一个单词的长度
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	size_t pos = s.rfind(" ");
	cout << (s.size() - pos - 1) << endl;

	return 0;
}
#endif

//验证回文串
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s)
	{
		//1.先将串s看成无空格和符号的进行判断
		//2.将对非字母和数字的情况加入
	}
};
