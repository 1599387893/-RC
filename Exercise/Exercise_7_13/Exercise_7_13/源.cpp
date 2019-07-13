//
//// write your code here cpp
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//		fflush(stdin);
//		string name;
//		getline(cin, name);
//		fflush(stdin);
//		int pos = s.find(name);
//		if (pos == -1)
//			cout << "Important!" << endl;
//		else
//		{
//			if (pos == 0)//这种情况下该姓名中不会含有 ","和" "
//			{
//				pos += name.size();
//				if (s[pos] == ',' && s[pos + 1] == ' ')
//					cout << "Ignore" << endl;
//				else
//					cout << "Important!" << endl;
//			}
//			else
//			{
//				if (s[pos - 1] == '\"' && s[pos + name.size()] == '\"')
//					cout << "Ignore" << endl;
//				else if (s[pos - 1] == ' ' && s[pos + name.size()] == ',')
//					cout << "Ignore" << endl;
//				else
//					cout << "Important!" << endl;
//			}
//
//		}
//	}
//	return 0;
//}