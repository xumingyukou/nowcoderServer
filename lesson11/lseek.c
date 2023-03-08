/*
    标准C库函数
    #include <stdio.h>
    int fseek(FILE *stream, long offset, int whence);

    linux系统函数
    #include <sys/types.h>
    #include <unistd.h>
    off_t lseek(int fd, off_t offset, int whence);
        参数：
            - fd：文件描述符，通过open得到的，通过这个fd操作文件
            - offset：便宜量
            - whence：
                SEEK_SET
                    设置文件指针的偏移量
                SEEK_CUR
                    设置偏移量：当前位置+第二个参数offset的值
                SEEK_END
                    设置偏移量：文件大小+第二个参数offset的值
        返回值：返回文件指针的位置
    作用：
        1.移动文件指针到文件头
            lseek(fd, 0, SEEK_SET)
        2.获取当前文件指针的位置
            lseek(fd, 0, SEEK_CUR)
        3.获取文件长度
            lseek(fd, 0, SEEK_END)
        4.拓展文件的长度，当前文件10b，拓展为110b
            lseek(fd, 100, SEEK_END)
            不能立即生效，需要写一次数据
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    
    int fd = open("hello.txt", O_RDWR);
    if(fd == -1) {
        perror("open");
        return -1;
    }

    int ret = lseek(fd, 100, SEEK_END);
    if(ret == -1) {
        perror("lseek");
        return -1;
    }

    // 写入一个空数据
    write(fd, " ", 1);

    close(fd);
    return 0;
}