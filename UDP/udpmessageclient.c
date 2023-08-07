#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<netdb.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  char buf[100];
  int k;
  socklen_t len;
  int sock_desc;
  struct sockaddr_in server,client;
  sock_desc=socket(AF_INET,SOCK_DGRAM,0);
  if(sock_desc == -1)
    printf("Error in socket creation\n");
  server.sin_family=AF_INET;
  server.sin_addr.s_addr=INADDR_ANY;
  server.sin_port=htons(3001);
  for(;;)
  {
    printf("[TO SERVER]:");
    fgets(buf,100,stdin);
    if(strncmp("exit",buf,4)==0 || strncmp("Exit",buf,4)==0)
    {
      k=sendto(sock_desc,buf,100,0,(struct sockaddr*)&server,sizeof(server));
      printf("Exiting");
    }
    k=sendto(sock_desc,buf,100,0,(struct sockaddr*)&server,sizeof(server));
    if(k==-1)
      printf("Error in sending");
    len=sizeof(server);
    k=recvfrom(sock_desc,buf,100,0,(struct sockaddr*)&server,&len);
    if(k==-1)
      printf("Error in receving");
    printf("[FROM SERVER]:%s",buf);
  }
  return 0;
}
    
