////—°‘Ò≈≈–Ú
//#if 0
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int array[] = { 7, 4, 2, 9, 5, 8, 3, 1, 0, 6 };
//	int len = sizeof(array) / sizeof(array[0]);
//
//	for (int i = 0; i < len - 1; ++i)
//	{
//		int minpos = i;
//		int j = i + 1;
//		for (; j < len; ++j)
//			if (array[minpos] > array[j])
//				minpos = j;
//		swap(array[i],array[minpos]);
//	}
//	for (auto& e : array)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}
//#endif
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int array[] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
//	int col = 0;
//	int row = 3;
//	int find;
//	cin >> find;
//
//	while (col < 4 && row >= 0)
//	{
//		int key = array[col * 3 + row];
//		if (key == find)
//		{
//			cout << col << " " << row << endl;
//			break;
//		}
//		else if (find < key)
//			row--;
//		else
//			col++;
//	}
//	if (col >= 4 || row < 0)
//		cout << "Fuck" << endl;
//	return 0;
//}