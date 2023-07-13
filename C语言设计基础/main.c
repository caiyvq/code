#include"a.h"

int main()
{
    srand(0);
    clock_t start, end;
 
    int n = 50000, m = 100000;
    //scanf("%d %d",&n,&m);
    int a[200000], b[200000];
    //time_t then;
    //快速排序 50000数
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10000;
    }

    //then=time(0);
    //printf("%llu\n",then);
    start = clock();
    quicksort(a, 0, n - 1); //随机
    end = clock();
    printf("quicksort50000 suiji:\n%d\n", (end - start)/CLK_TCK);
    //printf("%llu\n",time(0));
    //printf("quicksort50000 suiji:\n%llu\n", time(0)-then);
    //ptr(a, n);

    //then=time(0);
    start = clock();
    quicksort(a, 0, n - 1); //顺序
    end = clock();
    printf("quicksort50000 shun:\n%d\n", (end - start)/CLK_TCK);
    //printf("quicksort50000 shun:\n%llu\n", time(0)-then);
    //ptr(a, n);

    for (int j = 0, i = n - 1; i >= 0; i--, j++)
    {
        b[j] = a[i];
    }

    //then=time(0);
    start = clock();
    quicksort(b, 0, n - 1); //逆序
    end = clock();
    printf("quicksort50000 ni:\n%d\n", (end - start)/CLK_TCK);
    //printf("quicksort50000 ni:\n%llu\n", time(0)-then);
    //ptr(b, n);

    //快速排序 100000数
    for (int i = 0; i < m; i++)
    {
        a[i] = rand() % 10000;
    }

    start = clock();
    //ptr(a,m);
    quicksort(a, 0, m - 1); //随机
    end = clock();
    printf("quicksort100000 suiji:\n%d\n", (end - start)/CLK_TCK);
    //printf("quicksort100000 suiji:\n%llu\n", time(0)-then);
    //ptr(a, m);

    start = clock();
    quicksort(a, 0, m - 1); //顺序
    end = clock();
    printf("quicksort100000 shun:\n%d\n", (end - start)/CLK_TCK);
    //printf("quicksort100000 shun:\n%llu\n", time(0)-then);
    // ptr(a, m);

    for (int i = 0, j = m - 1; j >= 0; j--, i++)
    {
        b[i] = a[j];
    }

    start = clock();
    //ptr(b, m);
    quicksort(b, 0, m - 1); //逆序
    end = clock();
    printf("quicksort100000 ni:\n%d\n", (end - start)/CLK_TCK);
    //printf("quicksort100000 ni:\n%llu\n", time(0)-then);
    //ptr(b, m);

    //归并排序 50000数
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10000;
    }

    start = clock();
    mergesort(a, 0, n - 1); //随机
    end = clock();
    printf("mergesort50000 suiji:\n%d\n", (end - start)/CLK_TCK);
    //printf("mergesort50000 suiji:\n%llu\n", time(0)-then);
    //ptr(a, n);

    start = clock();
    mergesort(a, 0, n - 1); //顺序
    end = clock();
    printf("mergesort50000 shun:\n%d\n", (end - start)/CLK_TCK);
    //printf("mergesort50000 shun:\n%llu\n", time(0)-then);
    //ptr(a, n);

    for (int j = 0, i = n - 1; i >= 0; i--, j++)
    {
        b[j] = a[i];
    }

    start = clock();
    mergesort(b, 0, n - 1); //逆序
    end = clock();
    printf("mergesort50000 ni:\n%d\n", (end - start)/CLK_TCK);
    //printf("mergesort50000 ni:\n%llu\n", time(0)-then);
    //ptr(b, n);

    //归并排序 100000数
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10000;
    }

    start = clock();
    mergesort(a, 0, m - 1); //随机
    end = clock();
    printf("mergesort100000 suiji:\n%d\n", (end - start)/CLK_TCK);
    //printf("mergesort100000 suiji:\n%llu\n", time(0)-then);
    //ptr(a, m);

    start = clock();
    mergesort(a, 0, m - 1); //顺序
    end = clock();
    printf("mergesort100000 shun:\n%d\n", (end - start)/CLK_TCK);
    //printf("mergesort100000 shun:\n%llu\n", time(0)-then);
    //ptr(a, m);

    for (int j = 0, i = n - 1; i >= 0; i--, j++)
    {
        b[j] = a[i];
    }

    start = clock();
    mergesort(b, 0, m - 1); //逆序
    end = clock();
    printf("mergesort100000 ni:\n%d\n", (end - start)/CLK_TCK);
    //printf("mergesort100000 ni:\n%llu\n", time(0)-then);
    //ptr(b, m);

    return 0;
}