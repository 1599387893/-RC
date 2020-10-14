#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
void dumplist(int n, ...)
{
	va_list p;
	int i;
	va_start(p, n);
	while (n-- > 0)
	{
		i = va_arg(p, int);
		printf("%d ", i);
	}
	va_end(p);
}


int main()
{
	char str[] = "peace";
	char* s = str;
	printf("%s\n", s++ + 3);
	return 0;
	/*unsigned char;
	FILE* fp;
	fp = fopen("trial", "r");
	if (!fp)
	{
		printf("Unable open file");
		exit(1);
	}
	fclose(fp);
	*/
	union test
	{
		int i;
		float f;
		char c;
	};
	union test* t;
	t = (union test*) malloc(sizeof(union test));
	t->f = 10.10f;
	printf("%f", t->f);
	dumplist(2, 4, 8);
	dumplist(3, 6, 9, 7);
	printf("%x\n", -2 << 2);
	return 0;
}