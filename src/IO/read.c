/*
* Author:wxl
* Description: read函数示例
* Date: Create at 2020-11-22 17:35:12
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
  
   //对终端进行操作
   char buf[64]={0};
   int n=read(0,buf,sizeof(buf));
   //不设置阻塞时会一直等待用户输入
   printf("%s%d\n",buf,n);

   int status=fcntl(0,F_GETFL,0);
   status|=O_NONBLOCK;
   int ret=fcntl(0,F_SETFL,status);
   status=fcntl(0,F_GETFL,0);
   if(status&O_NONBLOCK)
      printf("no");
   memset(buf,0,sizeof(buf));
   n=read(0,buf,sizeof(buf));
   /***
    *retuen values and errno
    *n>0 读到的字节数
    *errno
    *  EAGAIN或EWOULDBLOCK 非阻塞文件描述符号,可以重读
    *  EINTR 信号中断
    ***/
   //非阻塞时会直接返回
   printf("%s%d\n",buf,n);

   return 0;
}
