#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<signal.h>
#include<arpa/inet.h>
#include<string.h>
#define PORT 6000
#define SIZE 256
static void handler(){
	wait(NULL);
}
int main(int argc,char**argv){
	int server_socketfd;
	int client_socketfd;
	int ret;
	pid_t pid;
	size_t address_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	server_socketfd=socket(AF_INET,SOCK_STREAM,0);
	memset(&server_address,0,sizeof(struct sockaddr_in));  
      
    server_address.sin_family = AF_INET;//协议族设置为ARPA因特网协议   
    server_address.sin_port = htons(PORT);//端口号设为PORT（6000）   
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);//允许任何客户端可以连接   
    address_len = sizeof(struct sockaddr_in);  
  
    ret = bind(server_socketfd, (struct sockaddr*)&server_address, address_len);//将创建的套接字和address中的地址绑定在一起   
    if( ret == -1 )  
    {  
        printf("bind failed!\n");  
        exit(0);  
    }  
      
    ret = listen(server_socketfd, 5);//创建一个监听5个请求的队列，也就是说这个服务器允许5个人同时登入   
    if ( ret == -1 )  
    {  
        printf("listen failed!\n");  
        exit(0);  
    }  
      
    while (1)  
    {  
        client_socketfd = accept(server_socketfd, (struct sockaddr*)&client_address, &address_len);//客户连接服务器时建立客户套接字   
  
        signal(SIGCHLD,handler);//为了避免子进程结束时造成僵尸进程，需要对结束子进程作处理，handler函数负责回收子进程   
  
        pid = fork();  
        if (pid == 0)//为客户分配的子进程   
        {  
            char buffer[256];  
            int nread;  
            nread = read(client_socketfd,buffer,sizeof(buffer));  
            printf("%s",buffer);  
                  
        }  
        else if (pid > 0)//父进程把分配的客户套接字关闭，用来供给下个客户   
        {  
            close(client_socketfd);//关闭客户套接字   
        }  
        else  
        {  
            printf("fork faild!\n");  
            exit(0);  
        }  
    }  
    return 0;  
}
