#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "server.h"
#define BUFSIZE 1024

int server(int port,char *IP,char *API_URL,char *API_KEY,char *DEVICE_NUM,char *DEVICE_SENSOR,char *way,char *POST_char,int time,char *bu)
{
        int sockfd, ret, i, h;
        struct sockaddr_in servaddr;
        char str1[4096],*buf;
        fd_set   t_set1;
		buf=bu;
        struct timeval  tv;

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
               //printf("创建网络连接失败,本线程即将终止---socket error!\n");
                exit(0);
        }

        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(port);
        if (inet_pton(AF_INET,IP, &servaddr.sin_addr) <= 0 ){
                //printf("创建网络连接失败,本线程即将终止--inet_pton error!\n");
                exit(0);
        };

        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
                //printf("连接到服务器失败,connect error!\n");
                exit(0);
        }
        //printf("与远端建立了连接\n");
        memset(str1, 0, 4096);
        strcat(str1,way);
        strcat(str1, " /v1.0/device/");
        strcat(str1, DEVICE_NUM);
        strcat(str1,"/sensor/");
        strcat(str1,DEVICE_SENSOR);
        strcat(str1,"/datapoints HTTP/1.1\r\n");
        strcat(str1, "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.7; rv:9.0.1) Gecko/20100101 Firefox/9.0.1\r\n");
        strcat(str1,"Host: ");
        strcat(str1, API_URL);
        strcat(str1,"\r\n");
        strcat(str1, "Accept: */*\r\n");
        strcat(str1, "U-ApiKey: ");
        strcat(str1,API_KEY);
        strcat(str1,"\r\n");
        strcat(str1,POST_char);
        strcat(str1, "\n\n");
        strcat(str1, "\r\n\r\n");
        strcat(str1, "\r\n\r\n");
        //printf("%s\n",str1);

        ret = write(sockfd,str1,strlen(str1));
        if (ret < 0) {
                //printf("发送失败！错误代码是%d，错误信息是'%s'\n",errno, strerror(errno));
                exit(0);
        }else{
                //printf("消息发送成功，共发送了%d个字节！\n\n", ret);
        }

        FD_ZERO(&t_set1);
        FD_SET(sockfd, &t_set1);
        FD_SET(sockfd, &t_set1);

        while(1){
                sleep(time);
                tv.tv_sec= 0;
                tv.tv_usec= 0;
                h= 0;
                //printf("--------------->1");
                h= select(sockfd +1, &t_set1, NULL, NULL, &tv);
                //printf("--------------->2");

                if (h == 0) continue;
                if (h < 0) {
                        close(sockfd);
                        //printf("在读取数据报文时SELECT检测到异常，该异常导致线程终止！\n");
                        exit(0);
                }

                if (h > 0){
                        memset(buf, 0, 4096);
                        i= read(sockfd, buf, 4095);
                        if (i==0){
                                close(sockfd);
                                //printf("读取数据报文时发现远端关闭，该线程终止！\n");
                                exit(0);
                        }


                        return 0;
                }
        }
        close(sockfd);


        return 0;
}
