
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

TEST(PSU,data1)
{
	char cbuf[4096];
	char rbuf[4096];
	sprintf(cbuf,"cat /sys/switch/psu/1/data");
	FILE *stream = popen(cbuf,"r");
	fread(rbuf,sizeof(rbuf),sizeof(char),stream);
	printf("%s",rbuf);	
	char *p = NULL;
	p = strstr(rbuf,"Temperature");
	if(p == NULL)
		ASSERT_TRUE(2 == 1);
	p = strstr(rbuf,"Fan speed");
	if(p == NULL)
		ASSERT_TRUE(2 == 1);
	p = strstr(rbuf,"IIN");
	if(p == NULL)
		ASSERT_TRUE(2 == 1);
	p = strstr(rbuf,"VIN");
	if(p == NULL)
		ASSERT_TRUE(2 == 1);
	p = strstr(rbuf,"PIN");
	if(p == NULL)
        	ASSERT_TRUE(2 == 1);
	p = strstr(rbuf,"IOUT");
	if(p == NULL)
		ASSERT_TRUE(2 == 1);
	p = strstr(rbuf,"VOUT");
	if(p == NULL)
		ASSERT_TRUE(2 == 1); 	
	p = strstr(rbuf,"POUT");
	if(p == NULL)
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
