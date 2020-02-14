#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#if 0
int Parition(vector<int>& arr, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = arr[end];

	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		while (begin < end && arr[end] >= key)
			end--;
		if (begin < end)
			swap(arr[begin], arr[end]);
	}
	if (arr[begin] != key)
		swap(arr[begin], arr[right - 1]);
	return begin;
}
void Qsort(vector<int>& arr,int left,int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = Parition(arr,left,right);
		Qsort(arr,left,mid);
		Qsort(arr,mid+1,right);
	}
}

int Parition1(vector<int>& arr, int left, int right)
{
	int begin = left;
	int end = right-1;
	int key = arr[end];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;

		if (begin < end)
			arr[end--] = arr[begin];

		while (begin < end && arr[end] >= key)
			end--;

		if (begin < end)
			arr[begin++] = arr[end];
	}
	arr[begin] = key;
	return begin;
}
void Qsort1(vector<int>& arr, int left, int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = Parition1(arr,left,right);
		Qsort1(arr, left, mid);
		Qsort1(arr, mid + 1, right);
	}
}
#endif


void merge(int r[], int s[], int x1, int x2, int x3)
{
	int i, j, k;
	i = x1;    //第一部分的开始位置
	j = x2 + 1;  //第二部分的开始位置
	k = x1;
	while ((i <= x2) && (j <= x3))    //当i和j都在两个要合并的部分中时
		if (r[i] <= r[j])    //筛选两部分中较小的元素放到数组s中
		{
		s[k] = r[i];
		i++;
		k++;
		}
		else
		{
			s[k] = r[j];
			j++;
			k++;
		}
	while (i <= x2)    //将x1〜x2范围内未比较的数顺次加到数组r中
		s[k++] = r[i++];
	while (j <= x3) //将x2+l〜x3范围内未比较的数顺次加到数组r中
		s[k++] = r[j++];
}
//归并排序
void merge_sort(int r[],int s[], int m, int n)
{
	int p;
	int t[20];
	if (m == n)
		s[m] = s[n];
	else
	{
		p = (m + n) / 2;
		merge_sort(r,t,m,p);
		merge_sort(r, t, p + 1, n);
		merge(t, s, m, p, n);
	}
}
int main()
{
	vector<int> arr{ 9, 5, 1, 2, 6, 7, 3, 4, 8, 10 };
	//Qsort1(arr,0,arr.size());
	int r[] = {9,7,5,3,1};
	int s[5] = {8,6,4,2,0};
	merge_sort(r, s, 5, 5);
 	
	return 0;
}
