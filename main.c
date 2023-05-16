#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    struct stat stat;
    int fd=open("name",O_RDWR|O_NONBLOCK|O_APPEND|O_CREAT,0777);
    //以下三个常数中必须指定一个,且仅允许指定一个。
    //O_RDONLY 只读打开
    //O_WRONLY 只写打开
    //O_RDWR  可读可写打开

    //O_APPEND   表示追加。如果文件已有内容,这次打开文件所写的数据附加到文件的末尾而不                  覆盖原来的内容。
    //O_CREAT 若此文件不存在则创建它。使用此选项时需要提供第三个参数mode ,表示该文件的访问权限。
    //O_EXCL 如果同时指定了O_CREAT,并且文件已存在,则出错返回。
    //O_TRUNC  如果文件已存在,并且以只写或可读可写方式打开,则将其长度截断(Truncate)为0字节。
    //O_NOCTTY：使用本参数时，如文件为终端，那么终端不可以作为调用open()系统调用的那个进程的控制终端。
    //O_NONBLOCK 对于设备文件,以O_NONBLOCK 方式打开可以做非阻塞I/O(Nonblock I/O),非
    //O_DIRECT:直接IO模式
    //O_SYNC:同步模式


    int cnt =write(fd,"123\n",4);
    printf("cnt=%d\r\n",cnt);
    int st=fstat(fd,&stat);
    printf("%ld %ld %ld %d\r\n",stat.st_dev,stat.st_size,stat.st_blksize,getpid());


    close(fd);
    return 0;
}
