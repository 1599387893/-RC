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