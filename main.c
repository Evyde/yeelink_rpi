#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include "server/server.h"
#include "LED/LED.h"
#include "tools/tools.h"

#define USERAPIKEY "31054cd8bd56c3f756544c3daed9793e"
#define DEVICE_NUMBER "14565"
#define DEVICE_SENSOR "25008"

int main(int arrgc,char *argv[])
        {
                char str1[2048],a[5],str[100];
				int i;
				time_t timep;
				FILE *logfp=NULL;
				logfp=fopen("run.log","at+");
				if(logfp==NULL) {
		printf("Can't open log file.");
		exit(1);
	}else 
				printf("Program will run silently.\nAnd the log is in ./run.log.\n");	
				init_d();	
				
				while(1){
                if(server(80,"42.96.164.52","api.yeelink.net",USERAPIKEY,DEVICE_NUMBER,DEVICE_SENSOR,"GET","",1,str1)!=0) return -1;
                else a[0]=is_sensor(str1);
                (int) a;
                a[1]=a[0]-48;
                if(a[1]==0) LED(0,1,1,0);
                else LED(0,1,1,1);
				time(&timep);	
				sprintf(str,">>%s[RE]:%d",ctime(&timep),a[1]);
				for( i=0;i<sizeof(str);i++) {
				if(str[i]=='\n') str[i]=' ';
				else ;
		}
				printf("%s\n",str);
				if(fprintf(logfp,"%s",str)<0) {
		fclose(logfp);
		logfp=fopen("error.log","wt+");
		fprintf(logfp,"ERROR! %s",ctime(&timep));
		fclose(logfp);
		exit(1);
}
                //return 0;

                }

			fclose(logfp);

			return 0;
        }
