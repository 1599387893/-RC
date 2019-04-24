//#include<stdio.h>
//#include<Windows.h>
//
//int main()
//{
//	char bar[102];
//	char laber[] = "|/-\\";
//	memset(bar,0,sizeof(bar));
//	for (int i = 0; i < 101; i++)
//	{
//		printf("[%-100s][%2d%%][%c]\r", bar,i,laber[i%4]);
//		bar[i] = '*';
//		
//		Sleep(100);
//	}
//	printf("\0");
//
//	return 0;
//}

#include<stdio.h>
#include<Windows.h>

int main()
{
	char bar[102] = { 0 };
	size_t i = 0;
	const char* laber = "|/-\\";

	while (i <= 100)
	{
		printf("\033[41m\033[37m\033[1m [%-3d%%]%s\033[0m\r", i, bar);
		fflush(stdout);
		bar[i++] = ' ';
		Sleep(1);
	}
	printf("\n");

return 0;
}
