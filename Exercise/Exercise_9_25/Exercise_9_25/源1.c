#include<stdio.h>
#include<Windows.h>

int main()
{
	int a = 1;
	int b = 1;
	//a = -1;
	printf("a=%d,b=%d,%d\n",a,b,a---b);
	printf("result = %d\n",(a++)+(++b));
	/*a = 1;
	/*b = 1;"*/

	///* /* */  "*/"/*"/**/;
	///* /* /0* /** /1;
	
	//允许嵌套
	//：/* /* /0  */ * */1; //等价于 1
	
	//不允许嵌套
	/* / */ 0 * /**/ 1; //等价于 0 * 1；
	
	system("pause");
	return 0;
}