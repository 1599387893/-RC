#if 0
#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	int i = 0;

	while (envp[i++])
	{
		printf("%s\n", envp[i]);
	}
	system("pause");
	return 0;
}
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{

	int i;
	printf("Total %d arguments\n", argc);

	for (i = 0; i < argc; i++)
	{
		printf("\nArgument argv[%d]  = %s \n", i, argv[i]);
	}

	system("pause");
	return 0;
}
