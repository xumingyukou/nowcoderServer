#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/*
    // 创建一个新文件
    int open(const char *pathname, int flags, mode_t mode);
    参数：
        pathname：要创建的文件路径
        flags：对文件的操作权限和其他设置
            必选项：O_RDONLY, O_WRONLY, or O_RDWR 这三个之间互斥
            可选项：O_CREAT 文件不存在会创建新文件
        mode：八进制数，表示用户对创建出的新文件的操作权限，比如0775
        最终的权限是：mode & ~umask
        0777是最高权限
        0777 -> 111111111
    &   0775 -> 111111101
    ---------------------------
                111111101
        按位与：0和任何数都为0

        umask的作用就是抹去某些权限，如0775可以避免其它组用户对文件进行写

        flags参数是一个int类型的数据，占4个字节，32位
        flags 32个位，每一个位就是一个标志位代表一种情况
        所以用按位或("|")标识符可以拼接多个flag
*/


int main() {

    // 创建一个新文件
    int fd = open("create.txt", O_RDWR | O_CREAT, 0777);
    if(fd == -1) {
        perror("open");
    }

    // 关闭文件描述符
    close(fd);

    return 0;
}