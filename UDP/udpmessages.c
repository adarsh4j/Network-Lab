#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main()
{
   char buf[100];
   int k;
   socklen_t len;
   int sock_desc;
   struct sockaddr_in server,client;
   sock_desc=socket(AF_INET,SOCK_DGRAM,0);
   if(sock_desc==-1)
     printf("Error on socket()\n");
   server.sin_family=AF_INET;
   server.sin_addr.s_addr=INADDR_ANY;
   server.sin_port=htons(3001);
   k=bind(sock_desc,(struct sockaddr*)&server,sizeof(server));
   if(k==-1)
     printf("Error in binding\n");
   len=sizeof(client);
   printf("Server is waiting\n");
   for(;;)
   {
     k=recvfrom(sock_desc,buf,100,0,(struct sockaddr*)&client,&len);
     printf("[FROM CLIENT]:%s\n",buf);
     if(k==-1)
       printf("Error in receiving");
     if(strncmp("exit",buf,4)==0 || strncmp("Exit",buf,4)==0)
     {
           printf("Exiting\n");
           exit(0);
     }
     printf("\n[TO CLIENT]:");
     fgets(buf,100,stdin);
     k=sendto(sock_desc,buf,100,0,(struct sockaddr*)&client,sizeof(client));
     if(k==-1)
       printf("Error in sending");
   }
   return 0;
}
