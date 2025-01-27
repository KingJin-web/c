// #include <stdio.h>
// #include <iostream>
// using namespace std;
// #define M 3
// #define N 20
// #define Myprintf printf("\n") /*表格控制*/
// typedef struct page
// {
// 	int num;  /*记录页面号*/
// 	int time; /*记录调入内存时间*/
// } Page;		  /* 页面逻辑结构，结构为方便算法实现设计*/

// Page b[M];		/*内存单元数*/
// int c[M][N];	/*暂保存内存当前的状态：缓冲区*/
// int queue[100]; /*记录调入队列*/
// int K;			/*调入队列计数变量*/

// /*初始化内存单元、缓冲区*/
// void Init(Page *b, int c[M][N])
// {
// 	int i, j;
// 	for (i = 0; i < N; i++)
// 	{
// 		b[i].num = -1;
// 		b[i].time = N - i - 1;
// 	}
// 	for (i = 0; i < M; i++)
// 		for (j = 0; j < N; j++)
// 			c[i][j] = -1;
// }

// /*取得在内存中停留最久的页面,默认状态下为最早调入的页面*/
// int GetMax(Page *b)
// {
// 	int i;
// 	int max = -1;
// 	int tag = 0;
// 	for (i = 0; i < M; i++)
// 	{
// 		if (b[i].time > max)
// 		{
// 			max = b[i].time;
// 			tag = i;
// 		}
// 	}
// 	return tag;
// }

// /*判断页面是否已在内存中*/
// int Equation(int fold, Page *b)
// {
// 	int i;
// 	for (i = 0; i < M; i++)
// 	{
// 		if (fold == b[i].num)
// 			return i;
// 	}
// 	return -1;
// }
// /*LRU核心部分*/
// void Lru(int fold, Page *b)
// {
// 	int i;
// 	int val;
// 	val = Equation(fold, b);
// 	if (val >= 0) //传入已在内存中的 下标更新为0
// 	{
// 		b[val].time = 0;
// 		for (i = 0; i < M; i++)
// 			if (i != val)
// 				b[i].time++;
// 	}
// 	else
// 	{
// 		queue[++K] = fold; /*记录调入页面*/
// 		val = GetMax(b);
// 		b[val].num = fold;
// 		b[val].time = 0;
// 		for (i = 0; i < M; i++)
// 			if (i != val)
// 				b[i].time++;
// 	}
// }

// /*主程序*/
// int main()
// {
// 	int a[N] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
// 	int i, j;
// 	K = -1;
// 	Init(b, c);
// 	for (i = 0; i < N; i++)
// 	{
// 		Lru(a[i], b);
// 		c[0][i] = a[i];
// 		/*记录当前的内存单元中的页面*/
// 		for (j = 0; j < M; j++)
// 			c[j][i] = b[j].num;
// 	}
// 	/*结果输出*/
// 	printf("内存状态为：\n");
// 	Myprintf;
// 	for (j = 0; j < N; j++)
// 		printf("|%2d ", a[j]);
// 	printf("|\n");
// 	Myprintf;
// 	for (i = 0; i < M; i++)
// 	{
// 		for (j = 0; j < N; j++)
// 		{
// 			if (c[i][j] == -1)
// 				printf("|%2c ", 32);
// 			else
// 				printf("|%2d ", c[i][j]);
// 		}
// 		printf("|\n");
// 	}
// 	int queue[100];
// 	Myprintf;
// 	printf("\n调入队列为:");
// 	for (i = 0; i < K + 1; i++)
// 		printf("%3d", queue[i]);
// 	printf("\n缺页次数为：%2d\n缺页率：%2.2f", K + 1, (float)(K + 1) / N);
// }

#include<stdio.h>
#include<stdlib.h>
#define MAXInt 0
#define MVNum 20         //最大顶点数 
typedef char VerTexType;
typedef int ArcType;

//无向网的存储结构
typedef struct
{
	VerTexType vexs[MVNum];//顶点表
	ArcType arcs[MVNum][MVNum];//邻接矩阵 
	int vexnum,arcnum;
 }AMGraph;
 
 int Locate(AMGraph G,VerTexType V)
 {
 	for(int i=0;i<G.vexnum;i++)
 	{
 		if(V==G.vexs[i])
 		return i ;
	 }
	 
   return -1;
 }
 void print(AMGraph G)
 {
 	int i,j;
 	for(i=0;i<G.vexnum;i++)
 	{
 		for(j=0;j<G.vexnum;j++)
 		{
 			printf("%d ",G.arcs[i][j]);
		 }
		 printf("\n");
	 }
	 
 }
 void Creat(AMGraph *G)
 {
 	int i,j,k;
 	int w;
 	char v1,v2;
 	printf("请输入顶点数和边数(中间用空格间隔)：\n");
 	scanf("%d %d",&G->vexnum,&G->arcnum);
 	fflush(stdin);
 	printf("请输入顶点信息：\n");
 	for(i=0;i<G->vexnum;i++)
 	{
 		scanf("%c",&G->vexs[i]);
 		fflush(stdin);
	 }
	 //初始化矩阵 
	 for(i=0;i<G->vexnum;i++)
	 {
	 	for(j=0;j<G->vexnum;i++)
	 	{
	 		G->arcs[i][j]=MAXInt;
		}
	 }
	for(k=0;k<G->arcnum;k++)
	{
		printf("请输入边依附的顶点：\n");
		scanf("%c %c",&v1,&v2);
		printf("请输入这条边的权值：\n");
		scanf("%d",&w);
		fflush(stdin);
		i=Locate(*G,v1);
		j=Locate(*G,v2);
		printf("%d %d\n",i,j); 
		G->arcs[i][j]=w;
		G->arcs[j][i]=w;
	}
 }
 
 int main()
 {
 	AMGraph G; 
 	Creat(&G);
 	print(G);
 }
