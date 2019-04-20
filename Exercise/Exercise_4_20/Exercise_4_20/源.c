#include<string.h>
#include<stdio.h>
#include<Windows.h>

int main()
{
	int i = 0;
	char bar[102];
	memset(bar, 0, sizeof(bar));
	const char* laber = "|/-\\";
	while (i <= 100)
	{
		printf("[%-100s][%d%%][%c]\r", bar, i, laber[i % 4]);
		printf("\033[1m\033[45;33m HELLO_WORLD\033[0m");
		fflush(stdout);
		bar[i++] = '*';
		Sleep(100);
	}
	printf("\n");
	return 0;
}