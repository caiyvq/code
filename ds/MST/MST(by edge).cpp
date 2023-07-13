#include<stdio.h>
#define INF 9999999
#define MAX 100
int graph[MAX][MAX];
struct EDGE
{
	int v1, v2;
	int val;
}edge[MAX];
bool known[MAX];
int setN[MAX];
void MST(int N,int M);
void Union(int n, int m);
int find(int n);
int main()
{
	int V, E;
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= E; i++)
	{
		int v1, v2, e;
		scanf("%d %d %d", &v1, &v2, &e);
		graph[v1][v2] = e;
		graph[v2][v1] = e;
	}
	MST(V, E);
	return 0;
}
void MST(int N,int M)
{
	int e=1;
	for (int i = 1; i <= N; i++)//�����bug�����Ű�N�ĳ�MAX����������Ϊ���1��ʼ���µġ�
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (graph[i][j] != 0)
			{
				edge[e].v1 = i;
				edge[e].v2 = j;
				edge[e].val = graph[i][j];
				e++;
			}
		}
	}
	for (int i = 0; i <= N; i++)
	{
		setN[i] = -1;
	}//��ʼ��
	int sum = 0, min=INF, minID=-1;
	for (int i = 1; i <= N; i++)
	{
		min = INF;
		minID = -1;
		for (int j = 1; j <= M; j++)
		{
			if (edge[j].val < min && /*(find(edge[j].v1) == find(edge[j].v2) ||*/ (known[edge[j].v1] == false && known[edge[j].v2] == false))//�������ѡ��
			{
				min = edge[j].val;
				minID = j;
			}
		}
		known[edge[minID].v1] = true;
		known[edge[minID].v2] = true;
		sum += edge[minID].val;
		//printf("%d\n", sum);
		if (find(edge[minID].v1) != find(edge[minID].v2))
		{
			Union(find(edge[minID].v1), find(edge[minID].v2));
		}
	}
	
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (setN[i] <= 0)
		{
			cnt++;
		}
	}
	if (cnt == 1)
	{
		printf("%d", sum);
	}
	else
	{
		printf("No MST\n%d\n%d",cnt,sum);
	}
}
void Union(int n, int m)
{
	if (setN[n] <= setN[m])
	{
		setN[n] += setN[m];
		setN[m] = n;
	}
	else
	{
		setN[m] += setN[n];
		setN[n] = m;
	}
}
int find(int n)
{
	if (setN[n] <= 0)return n;
	else return setN[n] = find(n);
}