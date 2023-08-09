#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
int main()
{
  int k,num;
  socklen_t len;
  int sock_desc;
  time_t current_time;
  struct sockaddr_in server,client;
  sock_desc=socket(AF_INET,SOCK_DGRAM,0);
  if(sock_desc==-1)
    printf("Error in socket creation");
   
  server.sin_family=AF_INET;
  server.sin_addr.s_addr=INADDR_ANY;
  server.sin_port=htons(4001);
  
  k=bind(sock_desc,(struct sockaddr*)&server,sizeof(server));
  if(k==-1)
     printf("error in binding");
  len =sizeof(client);
  for(;;)
  {
    recvfrom(sock_desc,&num,sizeof(num),0,(struct sockaddr*)&client,&len);
    current_time=time(NULL);
    printf("\nThe time client request is %s",ctime(&current_time));
    sendto(sock_desc,&current_time,sizeof(current_time),0,(struct sockaddr*)&client,sizeof(client));
  }
  return 0;
}
