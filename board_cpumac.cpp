
#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

using namespace std; 
#include<gtest/gtest.h>

TEST(BOARD,cpu_mac1)
{
	char cbuf[4096];
	char rbuf[4096];
	sprintf(cbuf,"cat /sys/switch/board/cpu_mac");
	FILE *stream = popen(cbuf,"r");
	fread(rbuf,sizeof(rbuf),sizeof(char),stream);
	printf("%s",rbuf);	
	ASSERT_EQ(strlen(rbuf),strlen("58:69:6C:FB:21:F7\n"));
#if 0
    	ASSERT_TRUE(Abs(1) == 1) << "Abs(1)=1";  //ASSERT_TRUE期待结果是true,operator<<输出一些自定义的信息
    	ASSERT_TRUE(Abs(-1) == 1) << "Abs(-1)=1";
    	ASSERT_FALSE(Abs(-2) == -2);  //期待结果是false
    	ASSERT_EQ(Abs(1),Abs(-1));
    	ASSERT_NE(Abs(-1),0);
    	ASSERT_LT(Abs(-1),2);
#endif
}
