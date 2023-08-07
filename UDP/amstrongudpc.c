#include<netdb.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
  
   int k;
   char buf[100];
   int sock_desc;
   socklen_t len;
   struct sockaddr_in client,server;
   
   sock_desc = socket(AF_INET,SOCK_DGRAM,0);
   
   if(sock_desc==-1)
   {
     printf("error in socket creation...");
     return 1;
   }
   
   server.sin_family= AF_INET;
   server.sin_addr.s_addr= INADDR_ANY;
   server.sin_port = htons(4004);
   len=sizeof(server);
   while(1)
   {
     printf("\nenter the number for armstrong ");
     fgets(buf,100,stdin);
     if(atoi(buf)==1111)
     {
          k=sendto(sock_desc,buf,100,0,(struct sockaddr*)&server,sizeof(server));
          if(k<0)
          {
            printf("error in sending...");
            return 1;
          }
          printf("\n Exiting......");
          break;
      }
      k=sendto(sock_desc,buf,100,0,(struct sockaddr*)&server,sizeof(server));
          if(k<0)
          {
            printf("error in sending...");
            return 1;
          }
      k=recvfrom(sock_desc,buf,100,0,(struct sockaddr*)&server,&len); 
        if(k<0)
          {
            printf("error in sending...");
            return 1;
          }
        
       if(atoi(buf)==1)
       {
         printf("\namstrong number..........");
       }
       else
       {
          printf("\nnot amstrong number..........");
       }
       
     }
     
     return 0;
  }  
