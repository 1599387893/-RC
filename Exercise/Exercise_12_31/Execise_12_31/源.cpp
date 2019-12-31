#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
int Function(unsigned int n) 
{
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555); 
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
	return n; 
}
//void perm(int list[], int k, int m) { if ( ) { copy(list,list+m,ostream_iterator<int>(cout," ")); cout<<endl; return; }for (int i=k; i<=m; i++) { swap(&list[k],&list[i]); ( ); swap(&list[k],&list[i]); } }
int main()
{
#if 0
	char ccString1[] = "Is Page Fault??";
	char ccString2[] = "No Page Fault??"; 
	strcpy(ccString1, "No"); 
	if (strcmp(ccString1, ccString2) == 0) 
		cout << ccString2; 
	else
		cout << ccString1;
#endif
	char str[] = "glad to test something"; 
	char *p = str; p++; 
	int *p1 = reinterpret_cast<int *>(p);
	p1++; 
	p = reinterpret_cast<char *>(p1); 
	printf("result is %s\n", p);

	//cout<<Function(197)<<endl;
	system("pause");
	return 0;
}
