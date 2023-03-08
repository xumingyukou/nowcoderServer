/*
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>

    int stat(const char *pathname, struct stat *statbuf);\
        作用：获取一个文件相关的信息
        参数：
            -pathname：操作的文件路径
            -statbuf：结构体变量传出参数，用于保存获取到的文件信息
        返回值：
            成功：返回0
            失败：返回-1 设置errno

    int lstat(const char *pathname, struct stat *statbuf);

    struct stat {
               dev_t     st_dev;         ID of device containing file
               ino_t     st_ino;         /* Inode number
               mode_t    st_mode;        /* File type and mode 
               nlink_t   st_nlink;       /* Number of hard links 
               uid_t     st_uid;         /* User ID of owner 
               gid_t     st_gid;         /* Group ID of owner 
               dev_t     st_rdev;        /* Device ID (if special file) 
               off_t     st_size;        /* Total size, in bytes 
               blksize_t st_blksize;     /* Block size for filesystem I/O 
               blkcnt_t  st_blocks;      /* Number of 512B blocks allocated 

               /* Since Linux 2.6, the kernel supports nanosecond
                  precision for the following timestamp fields.
                  For the details before Linux 2.6, see NOTES. */

               struct timespec st_atim;  /* Time of last access */
               struct timespec st_mtim;  /* Time of last modification */
               struct timespec st_ctim;  /* Time of last status change */

           #define st_atime st_atim.tv_sec      /* Backward compatibility 
           #define st_mtime st_mtim.tv_sec
           #define st_ctime st_ctim.tv_sec
           };
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    struct stat statbuf;
    
}