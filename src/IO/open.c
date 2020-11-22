/*
* Author:wxl
* Description: open 函数示例
* Date: Create at 2020-11-22 17:35:26
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char*argv[])
{
	if(argc<2)
	{
		printf("Usage: %s filename\n",argv[0]);
		return -1;
	}
	/***
	 * #include <sys/types.h>
	 * #include <sys/stat.h>
	 * #include <fcntl.h>
	 * int open(const char *pathname, int flags);
     * int open(const char *pathname, int flags, mode_t mode);
	 * args
	 * flags
	 * 	O_RDONLY：只读模式
	 * 	O_WRONLY：只写模式
	 *  O_RDWR：可读可写
	 *  O_APPEND 表示追加，如果原来文件里面有内容，则这次写入会写在文件的最末尾
	 * 	O_CREAT 表示如果指定文件不存在，则创建这个文件
	 * 	O_EXCL 表示如果要创建的文件已存在，则出错，同时返回 -1，并且修改 errno 的值
	 * 	O_TRUNC 表示截断，如果文件存在，并且以只写、读写方式打开，则将其长度截断为0
	 * 	O_NOCTTY 如果路径名指向终端设备，不要把这个设备用作控制终端
	 * 	O_NONBLOCK 如果路径名指向 FIFO/块文件/字符文件，则把文件的打开和后继 I/O设置为非阻塞模式（nonblocking mode）
	 * 	O_DSYNC 等待物理 I/O 结束后再 write。在不影响读取新写入的数据的前提下，不等待文件属性更新
	 * 	O_RSYNC read 等待所有写入同一区域的写操作完成后再进行
	 * 	O_SYNC 等待物理 I/O 结束后再 write，包括更新文件属性的 I/O
	 * mode 
	 * 	在创建文件时使用,采用四位文件掩码 如:0644
	 ***/


	//open打开一个文件,如果不存在则创建
	
	int fd=open(argv[1],O_RDWR);
	if(fd<0)
	{
		if(errno==ENOENT)
		{
			fd=open(argv[1],O_RDWR|O_CREAT,0644);
			if(fd<0)
			{
				perror("open create error:");
				return -1;
			}
		}
		else
		{
			perror("open error:");
			return -1;
		}
		
	}
	close(fd);
	return 0;
}