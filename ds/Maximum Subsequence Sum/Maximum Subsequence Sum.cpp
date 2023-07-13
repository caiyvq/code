#include<stdio.h>
#include<stdlib.h>
int main()
{
	int K;
	scanf("%d", &K);
	int N[10001]={0};
	//int* N = (int*)malloc(sizeof(int) * (K+1));
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &N[i]);
	}
	
	int max = -1, sum = 0, I=0, J=0;
	for (int i = 0; i < K; i++)
	{
		sum = 0;
		for (int j = i; j < K; j++)
		{
			sum += N[j];
			if (sum > max)
			{
				max = sum;
				I = i;
				J = j;
			}
			else if (sum == max)
			{
				I = I > i ? i : I;
				J = J > j ? j : J;
			}
		}
	}
	
	if (max < 0)
	{
		printf("0 %d %d", N[0], N[K-1]);
	}
	else
	{
		printf("%d %d %d", max, N[I], N[J]);
	}
}