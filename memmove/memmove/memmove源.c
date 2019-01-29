#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//void *memmove(void *dest, const void *src, size_t count);

void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);

	void* ret = dest;
	//从前向后
	if (dest > src)
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
		return ret;
	}
	//从后向前
	else
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}

		return ret;
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	my_memmove(arr + 2, arr, 12);
	system("pause");
	return 0;
}