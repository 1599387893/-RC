//#include <iostream>
//#include <time.h>
//#include<math.h>
//#define Bsize 3
//#define Psize 12
//#include<string>
//using namespace std;
//int QString[Psize];
//int Num = 0;
//struct pageInfor
//{
//	int content;
//	int timer;
//};
//
//class YZ_replace
//{
//public:
//	YZ_replace();
//	~YZ_replace();
//	int findSpace();
//	int findExist(int curpage);
//	int findReplace();
//	void FIFO();
//	void OPT();
//	void BlockClear();
//	void initia1(int string[]);
//	pageInfor *block;
//	pageInfor *page;
//	int memory_state[Bsize][Psize];
//	int s;
//private:
//};
//void P_String(int QString[])
//{
//	int i;
//	srand((unsigned)time(NULL));
//	for (i = 0; i<Psize; i++)
//	{
//		QString[i] = rand() * 9 / RAND_MAX + 1;
//	}
//	cout << "ҳ������";
//	for (i = 0; i<Psize; i++)
//	{
//		cout << QString[i] << " ";
//	}
//	cout << endl;
//}
//YZ_replace::YZ_replace()
//{
//	s = 0;
//	block = new pageInfor[Bsize];
//	for (int i = 0; i<Bsize; i++)
//	{
//		block[i].content = -1;
//		block[i].timer = 0;
//	}
//}
//void YZ_replace::initia1(int QString[])
//{
//	int j;
//	page = new pageInfor[Psize];
//	for (int i = 0; i<Psize; i++)
//	{
//		page[i].content = QString[i];
//		page[i].timer = 0;
//	}
//	for (int i = 0; i<Psize; i++)
//		for (j = 0; j<Bsize; j++)
//			memory_state[j][i] = 0;
//}
//YZ_replace::~YZ_replace()
//{
//	s = 0;
//}
//
//int YZ_replace::findSpace()
//{
//	for (int i = 0; i<Bsize; i++)
//		if (block[i].content == -1)
//			return i;
//	return -1;
//}
//int YZ_replace::findExist(int curpage)
//{
//	for (int i = 0; i<Bsize; i++)
//		if (block[i].content == page[curpage].content)
//			return i;
//	return -1;
//}
//
//int YZ_replace::findReplace()
//{
//	int pos = 0;
//	for (int i = 0; i<Bsize; i++)
//		if (block[i].timer >= block[pos].timer)
//			pos = i;
//	return pos;
//}
//
//void YZ_replace::FIFO()
//{
//	int exist, space, position;
//	for (int i = 0; i<Psize; i++)
//	{
//		exist = findExist(i);
//		if (exist != -1)
//		{
//			for (int b = 0; b<Bsize; b++)
//			{
//				memory_state[b][i] = memory_state[b][i - 1];
//			}
//			s++;
//		}
//		else
//		{
//			space = findSpace();
//			if (space != -1)
//			{
//				for (int b = 0; b<Bsize; b++)
//				{
//					memory_state[b][i] = memory_state[b][i - 1];
//				}
//				block[space] = page[i];
//				memory_state[space][i] = block[space].content;
//			}
//			else
//			{
//				for (int b = 0; b<Bsize; b++)
//				{
//					memory_state[b][i] = memory_state[b][i - 1];
//				}
//				position = findReplace();
//				block[position] = page[i];
//				memory_state[position][i] = block[position].content;
//			}
//		}
//		for (int j = 0; j<Bsize; j++)
//			block[j].timer++;
//	}
//}
//
//void YZ_replace::BlockClear()
//{
//	for (int i = 0; i<Bsize; i++)
//	{
//		block[i].content = -1;
//		block[i].timer = 0;
//	}
//}
//
//typedef struct page
//{
//	int num;
//	int time;
//}Page;
//
//Page b[Bsize];
//Page call[Bsize];
//int c[Bsize][Psize];
//int queue[100];
//int K;
//
//void InitL(Page *b, int c[Bsize][Psize])
//{
//	int i, j;
//	for (i = 0; i<Bsize; i++)
//	{
//		b[i].num = -1;
//		b[i].time = Psize - i - 1;
//	}
//	for (i = 0; i<Bsize; i++)
//		for (j = 0; j<Psize; j++)
//			c[i][j] = -1;
//}
//int GetMax(Page *b)
//{
//	int i;
//	int max = -1;
//	int tag = 0;
//	for (i = 0; i<Bsize; i++)
//	{
//		if (b[i].time>max)
//		{
//			max = b[i].time;
//			tag = i;
//		}
//	}
//	return tag;
//}
//int Equation(int fold, Page *b)
//{
//	int i;
//	for (i = 0; i<Bsize; i++)
//	{
//		if (fold == b[i].num)
//			return i;
//	}
//	return -1;
//}
//void Lru(int fold, Page *b)
//{
//	int i;
//	int val;
//	val = Equation(fold, b);
//	if (val >= 0)
//	{
//		b[val].time = 0;
//		for (i = 0; i<Bsize; i++)
//			if (i != val)
//				b[i].time++;
//	}
//	else
//	{
//		queue[++K] = fold;
//		val = GetMax(b);
//		b[val].num = fold;
//		b[val].time = 0;
//		for (i = 0; i<Bsize; i++)
//			if (i != val)
//				b[i].time++;
//	}
//}
//
//void YZ_replace::OPT()
//{
//	int exist, space, position;
//	for (int i = 0; i<Psize; i++)
//	{
//		exist = findExist(i);
//		if (exist != -1)
//		{
//			for (int b = 0; b<Bsize; b++)
//			{
//				memory_state[b][i] = memory_state[b][i - 1];
//			}
//			s++;
//		}
//		else
//		{
//			space = findSpace();
//			if (space != -1)
//			{
//				for (int b = 0; b<Bsize; b++)
//				{
//					memory_state[b][i] = memory_state[b][i - 1];
//				}
//				block[space] = page[i];
//				memory_state[space][i] = block[space].content;
//			}
//			else
//			{
//				for (int k = 0; k<Bsize; k++)
//				{
//					memory_state[k][i] = memory_state[k][i - 1];
//					for (int j = i; j<Psize; j++)
//					{
//						if (block[k].content != page[j].content)
//						{
//							block[k].timer = 1000;
//						}
//						else
//						{
//							block[k].timer = j; break;
//						}
//					}
//				}
//				position = findReplace();
//				block[position] = page[i];
//				memory_state[position][i] = block[position].content;
//			}
//		}
//	}
//}
//
//int decide(string str)
//{
//	int i = 0;
//	for (i = 0; i<str.size(); i++)
//	{
//		if (str[i]<'0' || str[i]>'9')
//		{
//			return 0;
//			break;
//		}
//	}
//	return i;
//}
//int trans(string str)
//{
//	int sum = 0;
//	for (int i = 0; i<str.size(); i++)
//		sum = sum + (str[i] - '0')*pow(10, str.size() - i - 1);
//	return sum;
//}
//
//int put()
//{
//	int a, d;
//	string str;
//	cin >> str;
//	a = decide(str);
//	while (a == 0)
//	{
//		cout << "�������,���������룡" << endl;
//		cin >> str;
//		a = decide(str);
//	}
//	d = trans(str);
//	return d;
//}
//void Put()
//{
//	cout << "��ѡ�����ҳ��ķ��� a:�������  b:�������" << endl;
//	cout << "��ѡ��Ĳ˵���:";
//	char F;
//	cin >> F;
//	while (F != 'a'&&F != 'b')
//	{
//		cout << "�����������������:";
//		cin >> F;
//	}
//	if (F == 'a')
//		P_String(QString);
//	if (F == 'b')
//	{
//		cout << "�������ҳ���:" << endl;
//		for (int i = 0; i<Psize; i++)
//		{
//			QString[i] = put();
//		}
//	}
//	cout << endl;
//	cout << "|---------------------------------------------------------------|" << endl;
//}
//int main()
//{
//	cout << "|-----------------------ҳ �� �� �� �� ��-----------------------|" << endl;
//	cout << "|---------------------------------------------------------------|" << endl;
//	int t = 1;
//	while (t)
//	{
//		Put();
//		YZ_replace test1;
//		YZ_replace test3;
//		char select;
//		do{
//			cout << "��ѡ��ҪӦ�õ��㷨:<1>FIFO�㷨  <2>LRU�㷨  <3>OPT�㷨  <0>�˳�" << endl;
//			int p, q;
//			cout << "��������˵���:";
//			cin >> select;
//			while (select != '0'&&select != '1'&&select != '2'&&select != '3')
//			{
//				cout << "����������Ч,����������:" << endl;
//				cin >> select;
//			}
//			if (select == '0')
//			{
//				cout << "��ѡ����ǲ˵�<0>" << endl;
//				cout << "����˳�." << endl;
//				t = 0;
//			}
//
//			if (select == '1')
//			{
//				cout << "��ѡ����ǲ˵�<1>" << endl;
//				cout << "FIFO�㷨״̬:" << endl;
//				test1.initia1(QString);
//				test1.FIFO();
//				test1.BlockClear();
//				cout << "-------------------------------------------" << endl;
//				for (p = 0; p<Bsize; p++)
//				{
//					for (q = 0; q<Psize; q++)
//						cout << test1.memory_state[p][q] << " ";
//					cout << endl;
//				}
//				cout << "-------------------------------------------" << endl;
//				cout << "������:" << test1.s << "/" << Psize << endl;
//				test1.~YZ_replace();
//				cout << endl;
//			}
//			if (select == '2')
//			{
//				int i, j;
//				K = -1;
//				InitL(b, c);
//				for (i = 0; i<Psize; i++)
//				{
//					Lru(QString[i], b);
//					c[0][i] = QString[i];
//					for (j = 0; j<Bsize; j++)
//						c[j][i] = b[j].num;
//				}
//				cout << "��ѡ����ǲ˵�<2>" << endl;
//				cout << "LRU�㷨״̬:" << endl;
//				cout << "------------------------------------------" << endl;
//				for (i = 0; i<Bsize; i++)
//				{
//					for (j = 0; j<Psize; j++)
//					{
//						if (c[i][j] == -1)
//							cout << " 0";
//						else
//							cout << " " << c[i][j];
//					}
//					cout << " " << endl;
//				}
//				cout << "------------------------------------------" << endl;
//				cout << "������:" << (Psize - (K + 1)) << "/" << Psize;
//				cout << '\t';
//				cout << endl;
//			}
//			if (select == '3')
//			{
//				cout << "��ѡ����ǲ˵�<3>" << endl;
//				cout << "OPT�㷨״̬:" << endl;
//				test3.initia1(QString);
//				test3.OPT();
//				test3.BlockClear();
//				cout << "------------------------------------------" << endl;
//				for (p = 0; p<Bsize; p++)
//				{
//					for (q = 0; q<Psize; q++)
//						cout << test3.memory_state[p][q] << " ";
//					cout << endl;
//				}
//				cout << "------------------------------------------" << endl;
//				cout << "������:" << test3.s << "/" << Psize << endl;
//				test3.~YZ_replace();
//				cout << endl;
//			}
//		} while (select == '1' || select == '2' || select == '3');
//	}
//	system("pause");
//	return 0;
//}











//
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <list>
//using namespace std;
//
//struct Node
//{
//	int key;
//	int value;
//};
//
//
//class LRUCache{
//private:
//	int maxSize;
//	list<Node> cacheList;
//	map<int, list<Node>::iterator > mp;
//public:
//	LRUCache(int capacity) {
//		maxSize = capacity;
//	}
//
//	int get(int key) {
//		map<int, list<Node>::iterator >::iterator it = mp.find(key);
//		if (it == mp.end())      //û������
//		{
//			return -1;
//		}
//		else  //��cache��������
//		{
//			list<Node>::iterator listIt = mp[key];
//			Node newNode;
//			newNode.key = key;
//			newNode.value = listIt->value;
//			cacheList.erase(listIt);               //��ɾ�����еĽڵ�      
//			cacheList.push_front(newNode);   //�����еĽڵ�ŵ�����ͷ��
//			mp[key] = cacheList.begin();
//		}
//		return cacheList.begin()->value;
//	}
//
//	void set(int key, int value) {
//		map<int, list<Node>::iterator >::iterator it = mp.find(key);
//		if (it == mp.end())   //û������
//		{
//			if (cacheList.size() == maxSize)  //cache����
//			{
//				mp.erase(cacheList.back().key);
//				cacheList.pop_back();
//			}
//			Node newNode;
//			newNode.key = key;
//			newNode.value = value;
//			cacheList.push_front(newNode);
//			mp[key] = cacheList.begin();
//		}
//		else  //����
//		{
//			list<Node>::iterator listIt = mp[key];
//			cacheList.erase(listIt);               //��ɾ�����еĽڵ�          
//			Node newNode;
//			newNode.key = key;
//			newNode.value = value;
//			cacheList.push_front(newNode);   //�����еĽڵ�ŵ�����ͷ��
//			mp[key] = cacheList.begin();
//		}
//	}
//};
//
//
//int main(void)
//{
//	LRUCache cache(3);
//	cache.set(1, 1);
//
//	cache.set(2, 2);
//
//	cache.set(3, 3);
//
//	cache.set(4, 4);
//
//	cout << cache.get(4) << endl;
//
//	cout << cache.get(3) << endl;
//	cout << cache.get(2) << endl;
//	cout << cache.get(1) << endl;
//
//	cache.set(5, 5);
//
//	cout << cache.get(1) << endl;
//	cout << cache.get(2) << endl;
//	cout << cache.get(3) << endl;
//	cout << cache.get(4) << endl;
//	cout << cache.get(5) << endl;
//	system("pause");
//	return 0;
//}





#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdlib>
#include<conio.h> 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bsize 4 //������С
#define psize 16 //���̴�С
typedef struct page
{
	int num; /*��¼ҳ���*/
	int time; /*��¼�����ڴ�ʱ��*/
}Page; /* ҳ���߼��ṹ���ṹΪ�����㷨ʵ�����*/
Page b[bsize]; /*�ڴ浥Ԫ��*/
int c[bsize][psize]; /*�ݱ����ڴ浱ǰ��״̬��������*/
int queue[100]; /*��¼�������*/
int K; /*������м�������*/
int phb[bsize] = { 0 }; //�������
int pro[psize] = { 0 }; //�������к�
int flag[bsize] = { 0 }; //���̵ȴ�����(������δ��ʹ�õĽ��̱�־)
int i = 0, j = 0, k = 0; //i��ʾ�������к�,j��ʾ������
int m = -1, n = -1; //�������кͽ����Ƿ���ͬ�жϱ�־
int max = -1, maxflag = 0; //����滻���������±�
int count = 0; //ͳ��ҳ��ȱҳ����
//����������кź���
int* build()
{
	printf("�������һ���������к�Ϊ��\n");
	int i = 0;
	for (i = 0; i<psize; i++)
	{
		pro[i] = 10 * rand() / (RAND_MAX + 1) + 1;
		printf("%d ", pro[i]);
	}
	printf("\n");
	return(pro);
}
//���ҿ��������

int searchpb()
{
	for (j = 0; j<bsize; j++)
	{
		if (phb[j] == 0)
		{
			m = j;
			return m;
			break;
		}
	}
	return -1;
}
//������ͬ����

int searchpro()
{
	for (j = 0; j < bsize; j++)
	{
		if (phb[j] == pro[i])
		{
			n = j;
			return j;
		}
	}
	return -1;
}
//��ʼ���ڴ�
void empty()
{
	for (i = 0; i<bsize; i++)
		phb[i] = 0;
	count = 0; //����������
}
//�Ƚ��ȳ�ҳ���û��㷨
void FIFO()
{
	for (i = 0; i<psize; i++)
	{
		m = searchpb();
		n = searchpro();
		//��flagֵ����
		for (j = 0; j < bsize; j++)
		{
			if (flag[j]>maxflag)
			{
				maxflag = flag[j];
				max = j;
			}
		}
		if (n == -1) //��������ͬ����
		{
			if (m != -1) //���ڿ��������
			{
				phb[m] = pro[i]; //���̺�����ÿ��������
				count++;
				flag[m] = 0;
				for (j = 0; j <= m; j++)
				{
					flag[j]++;
				}
				m = -1;
			}
			else //�����ڿ��������
			{
				phb[max] = pro[i];
				flag[max] = 0;
				for (j = 0; j < bsize; j++)
				{
					flag[j]++;
				}
				max = -1;
				maxflag = 0;
				count++;
			}
		}
		else //������ͬ�Ľ���
		{
			phb[n] = pro[i];
			for (j = 0; j < bsize; j++)
			{
				flag[j]++;
			}
			n = -1;
		}
		for (j = 0; j < bsize; j++)
		{
			printf("%d ", phb[j]);
		}
		printf("\n");
	}
	printf("ȱҳ����Ϊ��%d\n", count);
	printf("ȱҳ��Ϊ:%16.6f", (float)count / 16);
	printf("\n");
}
/*��ʼ���ڴ浥Ԫ��������*/
void Init(Page *b, int c[bsize][psize])
{
	int i, j;
	for (i = 0; i<psize; i++)
	{
		b[i].num = -1;
		b[i].time = psize - i - 1;
	}
	for (i = 0; i<bsize; i++)
		for (j = 0; j<psize; j++)
			c[i][j] = -1;
}
/*ȡ�����ڴ���ͣ����õ�ҳ��,Ĭ��״̬��Ϊ��������ҳ��*/
int GetMax(Page *b)
{
	int i;
	int max = -1;
	int tag = 0;
	for (i = 0; i<bsize; i++)
	{
		if (b[i].time>max)
		{
			max = b[i].time;
			tag = i;
		}
	}
	return tag;
}
/*�ж�ҳ���Ƿ������ڴ���*/
int Equation(int fold, Page *b)
{
	int i;
	for (i = 0; i<bsize; i++)
	{
		if (fold == b[i].num)
			return i;
	}
	return -1;
}
/*LRU���Ĳ���*/
void Lruu(int fold, Page *b)
{
	int i;
	int val;
	val = Equation(fold, b);
	if (val >= 0)
	{
		b[val].time = 0;
		for (i = 0; i<bsize; i++)
			if (i != val)
				b[i].time++;
	}
	else
	{
		queue[++K] = fold;/*��¼����ҳ��*/
		val = GetMax(b);
		b[val].num = fold;
		b[val].time = 0;
		for (i = 0; i<bsize; i++)
			if (i != val)
				b[i].time++;
	}
}
void LRU()
{
	int i, j;
	K = -1;
	Init(b, c);
	for (i = 0; i<psize; i++)
	{
		Lruu(pro[i], b);
		c[0][i] = pro[i];
		/*��¼��ǰ���ڴ浥Ԫ�е�ҳ��*/
		for (j = 0; j<bsize; j++)
			c[j][i] = b[j].num;
	}
	/*������*/
	printf("�ڴ�״̬Ϊ��\n");
	for (j = 0; j<psize; j++)
		printf("|%2d ", pro[j]);
	printf("|\n");
	for (i = 0; i<bsize; i++)
	{
		for (j = 0; j<psize; j++)
		{
			if (c[i][j] == -1)
				printf("|%2c ", 32);
			else
				printf("|%2d ", c[i][j]);
		}
		printf("|\n");
	}
	printf("\n�������Ϊ:");
	for (i = 0; i<K + 1; i++)
		printf("%3d", queue[i]);
	printf("\nȱҳ����Ϊ��%6d\nȱҳ�ʣ�%16.6f", K + 1, (float)(K + 1) / psize);
}
//������
int main()
{
	int sel;
	printf("------------------------ҳ���û��㷨-----------------\n");
	do{
		printf("-----------------------------------------------------\n");
		printf(" \t1������������� \n ");
		printf(" \t2�����δʹ��(LRU) \n ");
		printf(" \t3���Ƚ��ȳ�(FIFO) \n ");
		printf(" \t4�������㷨�ıȽ�() \n ");
		printf(" \t0���˳�(Exit) \n ");
		printf("��ѡ����Ҫִ�еĲ���(0/1/2/3/4):");
		scanf("%d", &sel);
		printf("\n------------------------------------------------------\n");

		switch (sel)
		{
		case 0:printf("\t\t\t^-^�ټ���^-^ \t\t\t\n"); system("pause"); break;
		case 1:printf("\n"); build(); printf("\n"); break;
		case 2:printf("���δʹ���㷨\n"); LRU(); empty(); printf("\n"); break;
		case 3:printf("�Ƚ��ȳ��㷨\n"); FIFO(); empty(); printf("\n"); break;
		case 4:printf("�Ƚ��ȳ��㷨\n"); FIFO(); empty();
			printf("\t");
			printf("���δʹ���㷨\n"); LRU();
			empty(); break;
		default: printf("��������ȷ��ѡ��ţ�"); printf("\n\n"); break;
		}
	} while (sel != 0);
	system("pause");
	return 0;
}