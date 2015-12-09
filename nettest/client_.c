
    #include <stdio.h>   
    #include <stdlib.h>   
    #include <unistd.h>   
    #include <sys/types.h>   
    #include <sys/socket.h>   
    #include <netinet/in.h>   
    #include <arpa/inet.h>   
    #include <string.h>   
      
    #define SIZE 256   
    #define PORT 6000   
      
    int main()  
    {  
        int socketfd;  
        int ret;  
        char buffer[SIZE];  
        struct sockaddr_in address;  
      
        socketfd = socket(AF_INET, SOCK_STREAM, 0);//创建一个套接字   
      
        address.sin_family = AF_INET;//设置为因特网协议   
        address.sin_port = htons(PORT);//设置端口号   
        inet_pton(AF_INET, "192.168.159.152", &address.sin_addr.s_addr);//设置ip地址   
      
        ret = connect(socketfd, (struct sockaddr*) &address, sizeof(address));//连接服务器   
      
        if (ret == -1)  
        {  
            printf("can't connect!\n");  
            exit(0);  
        }  
              
        printf("send:");  
        fgets(buffer,sizeof(buffer),stdin);  
        write(socketfd,buffer,sizeof(buffer));//把数据传给服务器   
      
        close(socketfd);//关闭套接字   
        return 0;  
    }  
