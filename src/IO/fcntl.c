/*
* Author:wxl
* Description: fcntl函数示例
* Date: Create at 2020-11-22 17:39:50
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/***
 * #include <unistd.h>
 * #include <fcntl.h>
 * int fcntl(int fd, int cmd, ...)
 * args
 * cmd 
 * F_DUPFD 复制文件描述符号,返回一个大于当前fd的数字
 * F_GETFD 获取文件描述符状态 取得与文件描述符fd联合close-on-exec标志,
 * F_GETFL
 * F_SETFL（int）
              将文件状态标志设置为arg指定的值。文件
              访问模式（O_RDONLY，O_WRONLY，O_RDWR）和文件创建arg中的
              标志（即O_CREAT，O_EXCL，O_NOCTTY，O_TRUNC）是
              忽略了，即不能修改。在Linux上，此命令只能更改O_APPEND，
               O_ASYNC，O_DIRECT，O_NOATIME和O_NONBLOCK标志。它不是
              可以更改O_DSYNC和O_SYNC标志
 * 
 ***/

int main(int argc,char* argv[])
{
    int fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		perror("open error:");
		return -1;
	}
    int flags=fcntl(fd,F_GETFL);
    if((flags&O_ACCMODE)==O_RDONLY)
        printf("read only\n");
    
    flags|=O_APPEND;
    fcntl(fd,F_SETFL,flags);
    flags=fcntl(fd,F_GETFL);

    if((flags&O_ACCMODE)==O_RDONLY)
        printf("read only\n");
        
    if(flags&O_APPEND)
        printf("append\n");
   return 0;
}
