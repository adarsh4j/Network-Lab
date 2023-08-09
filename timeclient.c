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
  int k;
  socklen_t len;
  int sock_desc;
  int num=1;
  double rtt1;
  clock_t start_t,end_t;
  time_t current_time,start_time,rtt;
  struct sockaddr_in server,client;
  sock_desc=socket(AF_INET,SOCK_DGRAM,0);
  if(sock_desc==-1)
    printf("Error in socket creation");
   
  server.sin_family=AF_INET;
  server.sin_addr.s_addr=INADDR_ANY;
  server.sin_port=htons(4001);
  
  start_time=time(NULL);
  start_t=clock();
  sendto(sock_desc,&num,sizeof(num),0,(struct sockaddr*)&server,sizeof(server));
  len=sizeof(server);
   recvfrom(sock_desc,&current_time,sizeof(current_time),0,(struct sockaddr*)&server,&len);
   end_t=clock();
   rtt1=end_t-start_t;
   rtt1=rtt1/2;
   rtt=time(NULL)-start_time;
   current_time+=rtt/2;
   printf("Server time %s is delayed by %f millisecond\n",ctime(&current_time),rtt1);
   return 0;
}
