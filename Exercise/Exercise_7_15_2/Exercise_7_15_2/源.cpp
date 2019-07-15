//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
////»¯¼ò
//void Simplity(int& s, int& m)
//{
//	int a = s;
//	int b = m;
//	do{
//		int c;
//		do{
//			c = a % b;
//			a = b;
//			b = c;
//		} while (c != 0)
//			s /= b;
//		m /= b;
//	} while (b != 1)
//}
//string ItoS(int& s, int& m)
//{
//	string ret;
//	if (s>m)
//	{
//		int shang = s / m;
//		int yushu = s%m;
//		while (shang)
//		{
//			ret += (shang / 10 + 48);
//			shang /= 10;
//		}
//		ret += ' ';
//		while (yushu)
//		{
//			ret += (yushu / 10 + 48);
//			yushu /= 10;
//		}
//	}
//	else
//		ret += (s + 48);
//	ret += '/';
//	while (m)
//	{
//		ret += (m)
//	}
//}
//void Number_operation(int& s1, int& m1, int& s2, int& m2£©
//{
//	Simplity(s1, m1);
//	Simplity(s2, m2);
//	cout << ItoS(s1, m1) << " + " << ItoS(s2, m2) << " = " << Add(s1, m1, s2, m2) << endl;
//	cout << ItoS(s1, m1) << " - " << ItoS(s2, m2) << " = " << Sub(s1, m1, s2, m2) << endl;
//	cout << ItoS(s1, m1) << " * " << ItoS(s2, m2) << " = " << Nul(s1, m1, s2, m2) << endl;
//	cout << ItoS(s1, m1) << " / " << ItoS(s2, m2) << " = " << Div(s1, m1, s2, m2) << endl;
//}
//int main()
//{
//	long int m1, m2, s1, s2;
//	while (scanf("%ld/%ld %ld/%ld", &s1, &m1, &s2, &m2))
//		Number_operation(s1, m1, s2, m2);
//
//	return 0;
//}