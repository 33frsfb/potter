#include<stdio.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>

int main()
{
   int usocket,nbytes,i;
   char buffer[1024];
   struct sockaddr_in serverAddr,clientAddr;
   struct sockaddr_storage  serverStorage;
   socklen_t addr_size,client_size_addr;
   
   
   usocket=socket(PF_INET,SOCK_DGRAM,0);
   
   serverAddr.sin_family=AF_INET;
   serverAddr.sin_port=htons(8890);
   serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
   
   memset(serverAddr.sin_zero,'\0',sizeof serverAddr.sin_zero);
   
   bind(usocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
   
    addr_size=sizeof serverStorage;
    
   
   while(1)
   {
      nbytes=recvfrom(usocket,buffer,1024,0,(struct sockaddr *)&serverStorage,&addr_size);
      
      for(i=0;i<nbytes-1;i++)
      {
         buffer[i]=toupper(buffer[i]);
         
         sendto(usocket,buffer,nbytes,0,(struct sockaddr*)&serverStorage,addr_size);
      }
      
    }
    
    return 0;
    }
         
