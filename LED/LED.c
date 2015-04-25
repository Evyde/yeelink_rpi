#include <wiringPi.h>
int LED(int times,int pinNum,int jiange,int mod)
        {
                int i=0;
                if(times<0||pinNum<=0||jiange<=0) return 1;
                else if(times==0)
                        {
                                wiringPiSetup();
                                pinMode(pinNum,OUTPUT);
                                digitalWrite(pinNum,mod);
                                return 0;
                        }
                wiringPiSetup();
                pinMode(pinNum,OUTPUT);
                for(i=0;i<times;i++)
                        {
                                digitalWrite(pinNum,1);
                                delay(jiange);
                                digitalWrite(pinNum,0);
                                delay(jiange);
                        }
                return 0;
        }
