/*------------- By G S Nitesh Narayana CED16 IIITDM----*/

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
	char recm[256];

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
	
	while(1)
	{
	// sending a message to the server
	printf("\nServer:");
    	gets(msg);
	//scanf("%s",msg);
    int s=send(socket_client,msg,sizeof(msg),0);// remember to use socket of client nto server
	//printf("\ns=%d\n",s);

	// attempting to read the msg from the server
	int reader=read(socket_client,&recm,sizeof(recm));
	// if(reader==-1)
	// 	printf("receiving failed");
	printf("\n Client:%s",recm);

	if(strcmp(msg,"bye")==0&& strcmp(msg,recm)==0)
        {
            printf("\n the Chat ends bye bye!1");
            break;
        }

	
	// if(strcmp(msg,recm))
	// printf("Echo Test successfull");
	}
	close(socket_server);
	return (0);
}
