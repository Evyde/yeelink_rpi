# yeelink_rpi
### 本程序为树莓派专用，使用前请安装wiringPi库。
### 或修改LED/LED.c来实现平台移植
### 项目使用cmake构建。
### 
# 注意：此版本有错误：
# 无法写入run.log！
# 目前解决方法：注释掉第43行到第49行即可。
# 即不产生log。
### 
### 在树莓派B+测试
###
### 编译、运行方法：
### 进入目录。
### cmake .
### 注意.，通过cmake创建Makefile
### make
### 编译链接
### 可以通过make help查看帮助
### 运行sudo ./Yeelink，程序进入后台，并接收服务器消息，控制led闪烁
###
### 目录结构：
### Yeelink_rpi
### ├── CMakeLists.txt
### ├── LED
### │   ├── CMakeLists.txt
### │   ├── LED.c
### │   └── LED.h
### ├── LICENSE
### ├── main.c
### ├── README.md
### ├── server
### │   ├── CMakeLists.txt
### │   ├── server.c
### │   └── server.h
### └── tools
###     ├── CMakeLists.txt
###     ├── init_d.c
###     ├── str.c
###     └── tools.h
### 
### 3 directories, 14 files
### 
### 作者：韩枫
### [邮箱1](mailto:life.app.hanfeng@hotmail.com)
