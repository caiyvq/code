#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <Windows.h>

#pragma comment(lib,"pthreadVC2.lib")

void *msrp_recv_thread(void *data)
{
    int i = 0;
    for(i = 1; i <= 3; i++)
    {
        printf("+++++++++this is thread method: %d \n", i);
    }
    return NULL;
}
int main()
{
    int i = 0;

    pthread_t recv_thread;
    pthread_attr_t attr;


    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if(pthread_create(&(recv_thread), &attr, msrp_recv_thread, NULL) < 0)
        return -1;
    for (i = 1; i <= 3; i++)
    {
        printf("----------this is main method: %d \n", i);
        Sleep(1);
    }

    pthread_attr_destroy(&attr);

    getchar();
    return 0;
}
