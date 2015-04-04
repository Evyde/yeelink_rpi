#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#define USERAPIKEY "youapikey"
#define DEVICE_NUMBER "yourdevicenumber"
#define DEVICE_SENSOR "yousebsornumber "

int main(int arrgc,char *argv[])
        {
                char str1[9999],a[5];
				time_t timep;	
				init_d();	
				while(1){
                if(server(80,"42.96.164.52","api.yeelink.net",USERAPIKEY,DEVICE_NUMBER,DEVICE_SENSOR,"GET","",1,str1)!=0) return -1;
                else a[0]=is_sensor(str1);
                (int) a;
                a[1]=a[0]-48;
                if(a[1]==0) LED(0,1,1,0);
                else LED(0,1,1,1);
				time(&timep);	
				printf("Recived message from server : %d\nOn %s .\n",a[1],ctime(&timep));
                //return 0;
                }
			return 0;
        }
