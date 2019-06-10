./configure

cd lib
make

cd ../libfree
make

cd ../libroute
make //这一步可能会出错，可忽略，只是表示你的系统不支持 4.4BSD，并不影响对该书的学习

cd ../libgai
make

       将生成的 libunp.a 静态库复制到/usr/lib/ 和 /usr/lib64/ 中。
cd ..   //回到 unpv13e 目录
sudo cp libunp.a /usr/lib
sudo cp libunp.a /usr/lib64

     修改 unp.h 并将其和 config.h 拷贝到 /usr/include 中。
vim lib/unp.h //将 unp.h 中#include "../config.h"修改为#include "config.h"
sudo cp lib/unp.h /usr/include
sudo cp config.h /usr/include

     编译书本例子。注意：编译时必须加上静态链接库：-l 参数加上 libunp.a  去掉lib和后面的.a。最后得到参数-lunp
cd ./intro
gcc daytimetcpcli.c -o daytimetcpcli -lunp

     测试上面生成的可执行文件获取本机当前日期：
./daytimetcpcli 127.0.0.1

     在进行测试时会出现以下错误：
connect error:Connection refused

     该错误表示 daytime 服务程序没开，可通过  xinetd来实现对服务连接请求的控制。以下通过 xinetd 开启 daytime 服务程序。注意：以下的所以执行都是以超级用户权限进行；
cd/etc/xinetd.d/

 vim daytime

      将 daytime 文件中的两个 disable = yes修改成 disable = no，并保存退出，然后重启 xinetd；
service xinetd restart

     再次测试书本上的第一个例子：此时可以正确获取本机的当前日期；
---------------------
作者：逆风微积分
来源：CSDN
原文：https://blog.csdn.net/chenhanzhun/article/details/41827241
版权声明：本文为博主原创文章，转载请附上博文链接！