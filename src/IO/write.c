/*
* Author:wxl
* Description: write函数示例
* Date: Create at 2020-11-22 17:41:24
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


int main(int argc,char* argv[])
{
   if(argc<2)
	{
		printf("Usage: %s filename\n",argv[0]);
		return -1;
	}
   int fd=open(argv[1],O_RDWR);
   char buf[64]="test the write";
   int n=write(fd,buf,strlen(buf));
   /***
    *retuen values and errno
    *n>0 已经写入的字节数
    *errno
    *  EAGAIN或EWOULDBLOCK 非阻塞文件描述符号,可以重写
    *  EINTR 信号中断
    ***/

   printf("write size %d\n",n);
   return 0;
}
