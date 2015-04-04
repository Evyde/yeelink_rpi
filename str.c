#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char is_sensor(char *SERVERRETURN)
        {
                char *str,value[9];
                str=strstr(SERVERRETURN,"value\":");
                strncpy(value,str,8);
                //re=&value[7];
                return value[7];
        }
