
/* Sample UDP client */

#include <sys/socket.h>
#include <netinet/in.h>
//#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

int main(int argc, char**argv)
{
   int sockfd,n;
   struct sockaddr_in servaddr,cliaddr;
   char sendline[1000];
   char recvline[1000];

   if (argc != 3)
   {
      printf("usage:  udpcli <IP address> <port>\n");
      exit(1);
   }

   sockfd=socket(AF_INET,SOCK_DGRAM,0);

   bzero(&servaddr,sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr=inet_addr(argv[1]);
   //servaddr.sin_port=htons(32000);
   servaddr.sin_port=htons(atoi(argv[2]));

   while (fgets(sendline, 10000,stdin) != NULL)
   {
      //fputs(sendline,stdout);
		sendto(sockfd,sendline,strlen(sendline),0,
             (struct sockaddr *)&servaddr,sizeof(servaddr));
      //n=recvfrom(sockfd,recvline,10000,0,NULL,NULL);
      //recvline[n]=0;

   }
}


//lsof -i -P
//netstat -tulpn
//sudo nmap -sT -O localhost
