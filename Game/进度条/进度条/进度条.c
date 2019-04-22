#include<stdio.h>
#include<Windows.h>

int main()
{
	char bar[102];
	char laber[] = "|/-\\";
	memset(bar,0,sizeof(bar));
	for (int i = 0; i < 101; i++)
	{
		printf("[%-100s][%2d%%][%c]\r", bar,i,laber[i%4]);
		bar[i] = '*';
		
		Sleep(100);
	}
	printf("\0");

	return 0;
}