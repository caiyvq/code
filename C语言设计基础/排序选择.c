#include <stdio.h>
#define MAXN 10

void sort( int a[], int n );
void ptr(int* a,int n)
{
    for( int i = 0; i < n; i++ )
        printf(" %d", a[i]);
    printf("\n");
}
int main()
{
    int i, n;
    int a[MAXN];
    
    scanf("%d", &n);
    for( i=0; i<n; i++ )
        scanf("%d", &a[i]);

    sort(a, n);
    ptr(a,n);
    return 0;
}

/* 你的代码将被嵌在这里 */
void sort( int a[], int n )
{
    int i,j,temp,index;
    for(i=0;i<n-1;i++)
    {
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(a[index]>a[j])index=j;
        }
        temp=a[index];
        a[index]=a[i];
        a[i]=temp;
    }
}