/*
    #include <sys/types.h>
    #include <unistd.h>

    pid_t fork(void);
        函数作用：创建一个子进程
        返回值：
            fork()的返回值会返回两次，一次在父进程中，一次在子进程中
            在父进程中，返回被创建子进程的PID
            在子进程中，返回0
            如何区分父进程和子进程：通过fork()的返回值
            在父进程中返回-1，表示创建子进程失败，并且设置errno

        失败的两个主要原因：
            1.当前系统的进程数已经达到了系统规定的上限，此时errno的值被设置为EAGAIN
            2.系统内存不足，这是errno的值被设置为ENOMEM
*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    int num = 10;
    // 创建子进程
    pid_t pid = fork();

    // 判断是父进程还是子进程
    if(pid > 0) {
        // 如果大于0，返回的是创建子进程的进程号，当前是父进程
        printf("i am parent process, pid: %d, ppid: %d\n", getpid(),getppid());

        printf("parent num = %d\n", num);
        num += 10;
        printf("parent num = %d\n", num);    
    } else if(pid == 0) {
        // 当前是子进程
        printf("i am child process, pid: %d, ppid: %d\n", getpid(), getppid());

        printf("child num = %d\n", num);
        num += 100;
        printf("child num = %d\n", num); 
    }

    //for
    // for(int i = 0; i < 100; i++) {
    //     printf("i: %d, pid: %d\n", i, getpid());
    // }

}
