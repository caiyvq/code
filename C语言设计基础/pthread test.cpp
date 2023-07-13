#include <stdio.h>
#include <pthread.h>
#include <windows.h>


void * print_a(void *a){
    int i;
    for(i = 0;i < 10; i++){
        Sleep(1000);
        printf("first\n");
    }
    return NULL;

}//1号进程

void * print_b(void *b){
    int i;
    for(i=0;i<20;i++){
        Sleep(1000);
        printf("second\n");
    }
    return NULL;
}//2号进程


int main()
{
    int aNum=5;
    int bNum=3;
    pthread_t threadPool[aNum+bNum];//创建一个线程池，大小为aNum+bNum

    int i;
    for(i = 0; i < aNum; i++){
        pthread_t temp;
        if(pthread_create(&temp, NULL, print_a, NULL) == -1){
            printf("ERROR");
            exit(1);
        }
        threadPool[i] = temp;
    }//创建1号进程放入线程池


    for(i = 0; i < bNum; i++){
        pthread_t temp;
        if(pthread_create(&temp, NULL, print_b, NULL) == -1){
            printf("ERROR");
            exit(1);
        }
        threadPool[i+aNum] = temp;
    }//创建2号进程放入线程池


    void * result;
    for(i = 0; i < aNum+bNum; i++){
        if(pthread_join(threadPool[i], &result) == -1){
            printf("fail to recollect\n");
            exit(1);
        }
    }//运行线程池
    return 0;
}


