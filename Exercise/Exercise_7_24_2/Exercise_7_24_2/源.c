#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>

int main()
{
	FILE* pf = fopen("Test.txt", "w");
	if (pf == NULL)
		printf("file open faild\n");
	else
		printf("file open success\n");
	fwrite("Hello RC\n", 2, 10,pf);
	fputs("rccccc", pf);
	char* str = "";
	//fgets(str, 5, pf);
	printf("%d\n", ftell(pf));
	//printf("%s\n", str);
	fclose(pf);
	system("pause");
	return 0;
}