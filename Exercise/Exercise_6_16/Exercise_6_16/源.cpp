#if 0  
#include<iostream>
#include<cmath>
using namespace std;

int l[20];//�ʺ���������
int n;//�ʺ����

void output(int n) 
{//���n�ʺ��ĳ����
	int i;
	for (i = 1; i <= n; i++) {
		cout << l[i];
	}
	cout << endl;
}

int place(int t, int r) 
{//�жϵ�r�лʺ��ܷ���ڵ�t��
	int i = 1;
	while (i<r){//�ʺ������rһ��Ҫ����i
		if (t == l[i] || abs(r - i) == abs(t - l[i])) {
			return 0;
		}
		++i;
	}
	return 1;
}

void nqueen(int m) {//�ݹ����
	int i;
	for (i = 1; i <= n; i++) {
		l[m] = i;
		if (place(i, m)) {
			if (m == n) {
				output(n);//������һ���ʺ�Ҳ������ϣ���������
			}
			else {
				nqueen(m + 1);//���򣬽�����һ���ʺ�ķ���
			}
		}
	}
}

int main() 
{
	cout << "������1~20���ڵ�����Ϊ�ʺ������";
	cin >> n;
	if (n > 20) {
		cout << "����ֵƫ�����������룺";
		cin >> n;
	}
	nqueen(1);
	system("pause");
	return 0;
}


#include<iostream>
#include<cmath>
using namespace std;
int n;

bool judgeQueen(int line, int* cb)
{
	for (int i = 1; i < line; ++i)
	{
		if (cb[i] == line || abs(cb[i]) == )
	}
}
void n_queen(int line, int* cb)
{
	for (int i = 1; i <= n; ++i)
	{
		cb[line] = i;
		if (judgeQueen(line, cb))
			n_queen(line + 1, cb);
	}
}
int main()
{
	cin >> n;
	int* checkerboard = new int[n + 1];
	n_queen(1, checkerboard);
	system("puase");
	return 0;
}
#endif

//����װ��-���ݷ�

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

typedef int Status;
typedef int Type;

int n = 0;    //��װ����
Type *x = (Type*)malloc((50)*sizeof(Type));//��ǰ��
Type *bestx = (Type*)malloc((50)*sizeof(Type));//��ǰ���Ž�
Type c = 0,   //��һ���ִ���������
	 cw = 0,       //��ǰ������
	 bestw = 0,    //��ǰ����������
	 r = 0,
	 *w = (Type*)malloc((50)*sizeof(Type));    //��װ����������

int Backtrack(int i)//������i��ڵ�
{
	int j_index;
	/*�������Ҷ��㣬���жϵ�ǰ��cw�������ǰ��õ������Ž�bestw �ã����滻ԭ���Ž⡣*/
	if (i>n)
	{
		if (cw>bestw)
			for (j_index = 1; j_index <= n; j_index++)
				bestx[j_index] = x[j_index]; bestw = cw;
		return 1;
	}
	//��������
	r -= w[i];
	if (cw + w[i] <= c)//����������,�����ǰʣ��ռ���Է��µ�ǰ��ƷҲ���ǣ�cw + w[ i ] <= c
	{
		x[i] = 1;
		cw += w[i];//�ѵ�ǰ���� cw += w[ i ]
		Backtrack(i + 1);//�ݹ��������������Backtrack( i + 1 )
		cw -= w[i];//���ʽ������ص����õ㣬 cw - = w[ i ]
	}
	if (cw + r>bestw)//����x[i]�������������²�װx[i]�Ƿ����
	{
		x[i] = 0;
		Backtrack(i + 1);
	}
	r += w[i];//�ߵ�����,x[i]��װ��·���Ѿ����꣬Ӧ������x[i]�ڵ����棬x[i-1]��װ��·��
}
Type* Initiate()
{
	int index = 1;
	printf("���뼯װ�������");
	scanf("%d", &n);
	printf("�����ִ���������");
	scanf("%d", &c);

	while (index <= n)//�����1�ŵ�Ԫ��ʼ�洢
	{
		printf("���뼯װ��%d ��������", index);
		scanf("%d", &w[index]);
		index++;
	}
	bestw = 0;
	cw = 0;
	r = 0;
	for (index = 1; index <= n; index++)
		r += w[index]; //��ʼʱr Ϊȫ����Ʒ��������
	printf("n=%d c=%d cw=%d bestw=%d r=%d\n", n, c, cw, bestw, r);

	for (index = 1; index <= n; index++)
	{
		printf("w[%d]=%d          ", index, w[index]);
	}
	printf("\n");
	return w;
}
int main()
{
	int i;
	Initiate();
	//��������������
	Backtrack(1);
	for (i = 1; i <= n; i++)
	{
		printf("%d        ", w[i]);
		printf("%d\n", bestx[i]);
	}

	system("pause");
	return bestw;
}



//01����������̬�滮
#include<iostream>
#include<algorithm>

using namespace std;
const int n = 5;//��ʾ��Ʒ������ 
const int m = 10;//��ʾ�������ܳ��ܵ���������1-10 
int weight[n + 1] = { 0, 2, 2, 6, 5, 4 };//��Ʒ��������ǰ��0�±�Ϊ0ֻ��Ϊ�����±���� 
int value[n + 1] = { 0, 6, 3, 5, 4, 6 };//��Ʒ�ļ�ֵ 
int f[n + 1][m + 1];//��ʾ�ܳ�������Ϊj�ı�������1-i��Ʒ������ֵ 

void package01(){
	int i = n, j;
	//���ȶ�����µĽ������ 
	for (j = 1; j <= m; j++){
		if (j < weight[i]){
			f[i][j] = 0;
		}
		else{
			f[i][j] = value[i];
		}
	}

	//Ȼ���ʣ�µ�n-1����Ʒ���
	for (i = n - 1; i > 0; i--){
		for (j = 1; j <= m; j++){
			if (j < weight[i]){
				f[i][j] = f[i + 1][j];
			}
			else{
				f[i][j] = max(f[i + 1][j - weight[i]] + value[i], f[i + 1][j]);
			}
		}
	}

	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			cout << f[i][j] << " ";
		}
		cout << endl;
	}

	cout << "����Ϊ10�ı�������ֵ�ǣ�" << f[1][10];
}

int main(){
	package01();
}