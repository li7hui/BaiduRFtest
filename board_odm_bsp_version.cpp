
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

TEST(BOARD,odm_bsp_version1)
{
	char cbuf[128];
	char rbuf[128];
	sprintf(cbuf,"cat /sys/switch/board/odm_bsp_version");
	FILE *stream = popen(cbuf,"r");
	fread(rbuf,sizeof(rbuf),sizeof(char),stream);
	printf("%s",rbuf);
	char *p = rbuf;
	while(*p != '\n' || *p != '\0')
		p++;
	*p = '\0';
	sprintf(cbuf,"date -d '%s'",rbuf);
	stream = popen(cbuf,"r");
	fread(rbuf,sizeof(rbuf),sizeof(char),stream);
	p = strstr(rbuf,"invalid");
	if(p!= NULL){
	ASSERT_TRUE(2==1);
	}
#if 0
    	ASSERT_TRUE(Abs(1) == 1) << "Abs(1)=1";  //ASSERT_TRUE期待结果是true,operator<<输出一些自定义的信息
    	ASSERT_TRUE(Abs(-1) == 1) << "Abs(-1)=1";
    	ASSERT_FALSE(Abs(-2) == -2);  //期待结果是false
    	ASSERT_EQ(Abs(1),Abs(-1));
    	ASSERT_NE(Abs(-1),0);
    	ASSERT_LT(Abs(-1),2);
#endif
}
