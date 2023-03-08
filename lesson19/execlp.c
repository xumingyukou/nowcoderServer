/*
    #include<unistd.h>
    int execlp(const char *file, const char *arg, ...);
        -会到环境变量中查找指定的可执行文件，找到了就执行，找不到就不成功
        -参数
            -path:需要执行的可执行文件的文件名
                相
            -arg:执行此程序所需的参数列表
                第一个参数一般没有什么作用，为了方便，一般写的是执行的程序名称
                第二个参数完后，就是程序执行需要的参数列表
                参数最后需要以NULL结束
        -返回值：
            只有当调用失败，才会有返回值，返回-1并设置errno
*/

#include<stdio.h>
#include<unistd.h>

int main() {

    // 创建一个子进程，在子进程中执行exec函数组中的函数
    __pid_t pid = fork();

    if(pid > 0) {
        // 父进程
        printf("i am parent process, pid : %d\n", getpid());
    } else if(pid == 0) {
        //子进程
        execlp("ps", "ps", NULL);
        perror("execlp");
        printf("i am child process\n");
    }

    for(int i = 0; i < 3; i++) {
        printf("i = %d\n", i);
    }

    return 0;
}