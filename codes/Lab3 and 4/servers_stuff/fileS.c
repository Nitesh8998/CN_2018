/*------------- By G S Nitesh Narayana CED16I044 IIITDM----*/


#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<netdb.h>

int main()
{

	int socket_server;
	socket_server=socket(AF_INET,SOCK_STREAM,0);
	char msg[256];
	char recm[512];

	// for the serrver structure
	struct sockaddr_in serv_addr;
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(9002);
	serv_addr.sin_addr.s_addr=INADDR_ANY;

	// attemoting to bind to the client
	int b=	bind(socket_server,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

	if(b==-1)
	printf("binding not succesfull");
	
	listen(socket_server,5);

	// attemptin to accept the connection
	int socket_client=accept(socket_server,NULL,NULL);
	
	// file pointer opening
	FILE* fp=fopen("anim.py","r");
	if(!fp)
	printf("\n File not opening");	

	int fbufSize;

	while((fbufSize=fread(msg,sizeof(msg),256,fp))>0)
	{
    int s=send(socket_client,msg,sizeof(msg),0);// remember to use socket of client nto server
	if(s<0)
	{
		printf("sending failed");
		break;
	}
        }


	 close(socket_server);
	 fclose(fp);
	return (0);
}
