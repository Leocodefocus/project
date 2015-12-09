#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#define DEST_IP "192.168.159.128"
#define DEST_PORT 8003
main(){
	int sockfd;
	int connflag;
	struct sockaddr_in dest_addr;
	//创建一个流式套结字
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0){
		//socket函数调用错误
		fprintf(stderr,"socket error!\n");
		exit(1);
	}
	//填充服务器的IP地址和服务端口号
	//注意字节顺序的转换
	dest_addr.sin_family=AF_INET;
	dest_addr.sin_port=htons(DEST_PORT);
	dest_addr.sin_addr.s_addr=inet_addr(DEST_IP);
	bzero(&(dest_addr.sin_zero),8);
	//调用connect函数，建立与服务器的链接
	connflag=connect(sockfd,(struct sockaddr * )&dest_addr,sizeof(struct sockaddr));
	if(connflag==-1){
		fprintf(stderr,"connect error!\n");
		exit(1);
	}	
} 
