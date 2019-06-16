#if 0  
#include<iostream>
#include<cmath>
using namespace std;

int l[20];//皇后所在列数
int n;//皇后个数

void output(int n) 
{//输出n皇后的某个解
	int i;
	for (i = 1; i <= n; i++) {
		cout << l[i];
	}
	cout << endl;
}

int place(int t, int r) 
{//判断第r行皇后能否放在第t列
	int i = 1;
	while (i<r){//皇后的行数r一定要大于i
		if (t == l[i] || abs(r - i) == abs(t - l[i])) {
			return 0;
		}
		++i;
	}
	return 1;
}

void nqueen(int m) {//递归求解
	int i;
	for (i = 1; i <= n; i++) {
		l[m] = i;
		if (place(i, m)) {
			if (m == n) {
				output(n);//如果最后一个皇后也放置完毕，则输出结果
			}
			else {
				nqueen(m + 1);//否则，进行下一个皇后的放置
			}
		}
	}
}

int main() 
{
	cout << "请输入1~20以内的数作为皇后个数：";
	cin >> n;
	if (n > 20) {
		cout << "输入值偏大，请重新输入：";
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

//最优装载-回溯法

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

typedef int Status;
typedef int Type;

int n = 0;    //集装箱数
Type *x = (Type*)malloc((50)*sizeof(Type));//当前解
Type *bestx = (Type*)malloc((50)*sizeof(Type));//当前最优解
Type c = 0,   //第一艘轮船的载重量
	 cw = 0,       //当前载重量
	 bestw = 0,    //当前最优载重量
	 r = 0,
	 *w = (Type*)malloc((50)*sizeof(Type));    //集装箱重量数组

int Backtrack(int i)//搜索第i层节点
{
	int j_index;
	/*如果到达叶结点，则判断当前的cw，如果比前面得到的最优解bestw 好，则替换原最优解。*/
	if (i>n)
	{
		if (cw>bestw)
			for (j_index = 1; j_index <= n; j_index++)
				bestx[j_index] = x[j_index]; bestw = cw;
		return 1;
	}
	//搜索子树
	r -= w[i];
	if (cw + w[i] <= c)//搜索左子树,如果当前剩余空间可以放下当前物品也就是，cw + w[ i ] <= c
	{
		x[i] = 1;
		cw += w[i];//把当前载重 cw += w[ i ]
		Backtrack(i + 1);//递归访问其左子树，Backtrack( i + 1 )
		cw -= w[i];//访问结束，回到调用点， cw - = w[ i ]
	}
	if (cw + r>bestw)//搜索x[i]的右子树，试下不装x[i]是否可行
	{
		x[i] = 0;
		Backtrack(i + 1);
	}
	r += w[i];//走到这里,x[i]不装的路径已经试完，应该试下x[i]节点上面，x[i-1]不装的路径
}
Type* Initiate()
{
	int index = 1;
	printf("输入集装箱个数：");
	scanf("%d", &n);
	printf("输入轮船载重量：");
	scanf("%d", &c);

	while (index <= n)//数组从1号单元开始存储
	{
		printf("输入集装箱%d 的重量：", index);
		scanf("%d", &w[index]);
		index++;
	}
	bestw = 0;
	cw = 0;
	r = 0;
	for (index = 1; index <= n; index++)
		r += w[index]; //初始时r 为全体物品的重量和
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
	//计算最优载重量
	Backtrack(1);
	for (i = 1; i <= n; i++)
	{
		printf("%d        ", w[i]);
		printf("%d\n", bestx[i]);
	}

	system("pause");
	return bestw;
}



//01背包——动态规划
#include<iostream>
#include<algorithm>

using namespace std;
const int n = 5;//表示物品的数量 
const int m = 10;//表示背包所能承受的重量，从1-10 
int weight[n + 1] = { 0, 2, 2, 6, 5, 4 };//物品的重量，前面0下标为0只是为了让下标对齐 
int value[n + 1] = { 0, 6, 3, 5, 4, 6 };//物品的价值 
int f[n + 1][m + 1];//表示能承受重量为j的背包放入1-i物品的最大价值 

void package01(){
	int i = n, j;
	//首先对最底下的进行填充 
	for (j = 1; j <= m; j++){
		if (j < weight[i]){
			f[i][j] = 0;
		}
		else{
			f[i][j] = value[i];
		}
	}

	//然后对剩下的n-1个物品填充
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

	cout << "承重为10的背包最大价值是：" << f[1][10];
}

int main(){
	package01();
}