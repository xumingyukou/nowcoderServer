/*
    #include<stdlib.h>
    void exit(int status);

    #include<unistd.h>
    void _exit(int status);

    status: 进程退出时的状态信息，父进程回收子进程的时候可以获取

*/
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("hello\n");
    printf("world");

    // exit(0);  // 调用退出处理函数，刷新IO缓冲区，关闭文件描述符后再调用_exit()结束进程
    _exit(0);  // 只输出hello，没有world。因为\n后将IO缓冲区进行了刷新，world进入缓冲区后还未输出就结束了进程

    return 0;
}