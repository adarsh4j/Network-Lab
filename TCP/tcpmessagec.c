#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
   char buf[100];
   int k;
   socklen_t len;
   int sock_desc;
   struct sockaddr_in server,client;
   sock_desc=socket(AF_INET,SOCK_STREAM,0);
   if(sock_desc==-1)
     printf("Error in socket creation");
   client.sin_family=AF_INET;
   client.sin_addr.s_addr=INADDR_ANY;
   client.sin_port=3003;
   k=connect(sock_desc,(struct sockaddr*)&client,sizeof(client));
   if(k==-1)
     printf("Error in socket connection");
   for(;;)
   {  
     printf("[To SERVER]:");
     fgets(buf,100,stdin);
     if(strncmp("exit",buf,4)==0 || strncmp("Exit",buf,4)==0)
     {
        k=send(sock_desc,buf,100,0);
        printf("Exiting!!");
        exit(0);
     }
     k=send(sock_desc,buf,100,0);
     if(k==-1)
       printf("Error in sending");
     k=recv(sock_desc,buf,100,0);
     if(k==-1)
       printf("Error in receving");
     printf("[FROM SERVER]:%s",buf);
   }
   return 0;
}
     

