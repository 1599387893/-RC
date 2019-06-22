#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>


//void *memcpy(void *dest, const void *src, size_t count);

void* my_memcpy(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
int main()
{
	int arr[] = {1,2,3,4,5,6};
	my_memcpy(arr + 2, arr, 12);
	system("pause");
	return 0;
}