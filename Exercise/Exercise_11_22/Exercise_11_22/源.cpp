//#include<iostream>
//using namespace std;
#if 0
int Func(unsigned int n)
{
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
	return n;
}
int main()
{
	unsigned int n = 197;
	cout << Func(n) << endl;
	system("pause");
	return 0;
}
#endif

#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
#include<unordered_map>

class Util
{
private:
	static std::unordered_map<std::string, std::string> dict;

public:
	//���ַ����е��ַ�ȫ��ת����Сд�ַ�
	static void StringToLower(std::string& s)
	{
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	}
	//���ַ����е��ַ�ȫ��ת���ɴ�д�ַ�
	static void StringToUpper(std::string& s)
	{
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
	}
	//�ַ���ת����
	static int StringToInt(std::string& s)
	{
		int ret = 0;
		std::stringstream ss(s);
		ss >> ret;
		return ret;
	}
	//����ת�ַ���
	static std::string IntToString(int n)
	{
		std::stringstream ss;
		ss << n;
		return ss.str();
	}
	static std::string GetStateCode(int code)
	{
		switch (code)
		{
		case 200:
			return "OK";
		case 404:
			return "NOT FOUND";
		default:
			return "UNKOWN";
		}
	}
	//���ַ����е��Ӵ���ɢ��Ȼ�󱣴���vector��
	static void TransfromVector(std::string& s, std::vector<std::string>& v)
	{
		int start = 0;
		auto pos = s.find('\n');
		while (pos != std::string::npos)
		{
			v.push_back(s.substr(start, pos - start));
			start = pos + 1;
			pos = s.find('\n', start);
		}
	}
	//��һ���ַ�������: ������key��value
	static void MakeKV(std::string& s, std::string& k, std::string& v)
	{
		auto pos = s.find(": ");
		if (pos == std::string::npos)
		{
			k = "";
			v = "";
			return;
		}
		k = s.substr(0, pos);
		v = s.substr(pos + 2);
	}
	static std::string SuffixToCT(std::string& suffix)
	{
		std::string ret = "Content-Type: ";
		auto pos = dict.find(suffix);
		if (pos != dict.end())
			ret += pos->second;
		else
			ret += ".text/html";
		return ret;
	};
	std::unordered_map<std::string, std::string> Util::dict{
			{ ".html", "text/html" },
			{ ".htm", "text/html" },
			{ ".css", "text.css" },
			{ ".js", "pplication/x-javascript" },
			{ ".jpg", "pplication/x-jpg" },
			{ ".gif", "mage/gif" }
	};
};