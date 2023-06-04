Program:- 
Server:-
#include<sys/socket.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#define MAX 100
      int  main()
      {
     	int sockd,stat;
     	struct sockaddr_in serveraddr;
    	struct sockaddr_in clientaddr;
    	char buf[MAX];
     	socklen_t clientlen;
     	sockd=socket(AF_INET,SOCK_DGRAM,0);
     	 if(sockd==-1)
       	{
        		printf("Error creating socket...\n");
        		exit(0);
       	}
    	 else
        		printf("socket is created....\n");
    	 serveraddr.sin_family=AF_INET;
     	serveraddr.sin_port=htons(7006);
     	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    	stat=bind(sockd,(struct sockaddr *)&serveraddr,sizeof(serveraddr)); 	
if(stat==-1)
      	{
        		printf("Error Naming Socket....\n");
       		 exit(0);
      	}
    	else
   		printf("socket naming sucessful....\n");

   	memset(buf,0,MAX);
   	clientlen=sizeof(serveraddr);

  	while(1)
  	{
    		memset(buf,0,MAX);
    
   		recvfrom(sockd,buf,MAX,0,(struct sockaddr *)&clientaddr,&clientlen);
   		 printf("Data from port number:\t ");
    		printf("%d\n",htons(clientaddr.sin_port));
    		printf("Data from Client:\t");
    		printf("%s\n",buf);
   	 	memset(buf,0,MAX);
   	}
  	close(sockd);
 }
       












              

Client:-
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#define MAX 100
      int main()
      {
    	 int sockd,stat;
     	struct sockaddr_in serveraddr;
     	struct sockaddr_in clientaddr;
     	char buf[MAX];
     	socklen_t serverlen;
     	sockd=socket(AF_INET,SOCK_DGRAM,0);
      if(sockd==-1)
       	{
        		printf("Error creating socket...\n");
        		exit(0);
       	}
     	else
       		printf("socket is created....\n");
          	clientaddr.sin_family=AF_INET;
       	clientaddr.sin_port=htons(0);
       	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
       	clientaddr.sin_addr.s_addr=htons(INADDR_ANY);
       	stat=bind(sockd,(struct sockaddr *)&clientaddr,sizeof(clientaddr));
        	if(stat==-1)
      	{
        		printf("Error Naming Socket....\n");
        		exit(0);
      	}
    	else
   		printf("socket naming sucessful");

    	serveraddr.sin_family=AF_INET;
    	serveraddr.sin_port=htons(7006);
    	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
   	memset(buf,0,MAX);
   	serverlen=sizeof(serveraddr);
  	printf("Enter the data to send\n");
  	printf("'.' on nextline ends the socket\n");
    	while(1)
  	{
    	memset(buf,0,MAX);
    		scanf("\t%s",buf);
    		if(strcmp(buf,".")==0)
      		{
        			break;
      		}
    		sendto(sockd,buf,MAX,0,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
    		memset(buf ,0,MAX);
    	 }
  	close(sockd);
 }


