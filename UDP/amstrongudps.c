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
   int temp,count=0,d,flag;
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
   
   k= bind(sock_desc,(struct sockaddr*)&server,sizeof(server));
   if(k<0)
   {
     printf("error in bind creation...");
     return 1;
   }
   len = sizeof(client);
   
   printf("\nserver is waiting......");
   
   while(1)
   {
      k= recvfrom(sock_desc,buf,100,0,(struct sockaddr*)&client,&len);
      if(k<0)
      {
        printf("error in recv...");
        return 1;
      }
         printf("\ngiven number is %s",buf);
      int c= atoi(buf);
     temp=c;
      
      if(c==1111)
      {
         printf("\nExiting....");
         break;
      }
      count=0;
      while(temp!=0)
      {
        temp=temp/10;
        count++;
      }
      temp=c;
      int sum=0,p;
      while(temp!=0)
      {
        d=temp%10;
        p=1;
        for(int i=0;i<count;i++)
        {
          p=p*d;
        }
        temp=temp/10;
        sum=sum+p;
       }
       
      
     
      if(sum==c)
      {
        flag=1;
      }      
      else
      {
        flag=0;
      }
      sprintf(buf,"%d",flag);
        k=sendto(sock_desc,buf,100,0,(struct sockaddr*) &client,sizeof(client));
         if(k<0)
         {
           printf("error in send...");
           return 1;
         }
    
    
    }
    
    return 0;
 }
