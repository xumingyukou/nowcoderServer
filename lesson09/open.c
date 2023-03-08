/*
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    // 可变参数，不是重载
    // 打开一个已经存在的文件
    参数：
        pathname：文件路径
        flags：对文件的 操作权限设置和其它设置
            O_RDONLY, O_WRONLY, or O_RDWR，这三个设置是互斥的
    返回值：
        返回一个文件描述符file descriptor，若有错误则返回-1

    errno：属于Linux系统函数库，库里的一个全局变量，记录的是最近的错误号
    #include <stdio.h>
    void perror(const char *s);
    作用：打印errno对应的错误描述
    s参数：用户描述，比如helle，最终的输出内容是hello：xxx
    int open(const char *pathname, int flags);
    
    
    // 创建一个新文件
    int open(const char *pathname, int flags, mode_t mode);

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("a.txt", O_RDONLY);
    if(fd == -1) {
        perror("open");
    }
    close(fd);

    return 0;
}