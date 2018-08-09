
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

TEST(PSU,alarm_threshold1)
{
	char cbuf[4096];
	char rbuf[4096];
	sprintf(cbuf,"cat /sys/switch/psu/alarm_threshold");
	FILE *stream = popen(cbuf,"r");
	fread(rbuf,sizeof(rbuf),sizeof(char),stream);
	printf("%s",rbuf);	
	char *p = rbuf;
	char *pEnd = NULL;
	p = strstr(rbuf,"psu alarm temp is");
	if(p == NULL)
		ASSERT_TRUE(2 == 1);
	p += strlen("psu alarm temp is");
	int num = strtol(p,&pEnd,10);
	if(pEnd != NULL)
		ASSERT_TRUE(2 == 1);
	p = strstr(rbuf,"psu input voltage threshold is");
	p += strlen("psu input voltage threshold is");
	num = strtol(p,&pEnd,10);
	if(pEnd != NULL)
		ASSERT_TRUE(2 == 1);
	p = strstr(rbuf,"psu fan speed threshold is");
	p += strlen("psu fan speed threshold is");
	num = strtol(p,&pEnd,10);
	if(pEnd != NULL)
		ASSERT_TRUE(2 == 1);
	p = strstr(rbuf,"psu over-current warning is");
	p += strlen("psu over-current warning is");
	num = strtol(p,&pEnd,10);
	if(pEnd != NULL)
		ASSERT_TRUE(2 == 1); 		
	p = strstr(rbuf,"fault is");
	p += strlen("fault is");
	num = strtol(p,&pEnd,10);
	if(pEnd != NULL)
		ASSERT_TRUE(2 == 1); 		
#if 0
    	ASSERT_TRUE(Abs(1) == 1) << "Abs(1)=1";  //ASSERT_TRUE期待结果是true,operator<<输出一些自定义的信息
    	ASSERT_TRUE(Abs(-1) == 1) << "Abs(-1)=1";
    	ASSERT_FALSE(Abs(-2) == -2);  //期待结果是false
    	ASSERT_EQ(Abs(1),Abs(-1));
    	ASSERT_NE(Abs(-1),0);
    	ASSERT_LT(Abs(-1),2);
#endif
}
