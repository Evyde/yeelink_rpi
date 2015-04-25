# yeelink_rpi
#本程序为树莓派专用，使用前请安装wiringPi库。
#或修改LED/LED.c来实现平台移植
#项目使用cmake构建。
#
#####Pay attention:IT IS A ERROR VERSION!#####
#
#在树莓派B+测试
#main.c:
#	主程序
#str.c:
#	处理服务器返回数据
#server.c:
#	创建socket与服务器交互
#init_d.c:
#	创建守护进程
#LED.c:
#	控制LED闪烁
#Makefile:
#	make命令配置文件

#使用make进行编译链接，使用make clean清除中间文件
#运行sudo ./Yeelink，程序进入后台，并接收服务器消息，控制led闪烁
#作者：ForeverOpp
#hanfeng@isyzx.com
