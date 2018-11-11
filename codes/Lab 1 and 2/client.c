/*------------- By G S Nitesh Narayana CED16 IIITDM----*/

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<netdb.h>

int main()
{

	int socket_client;
	socket_client=socket(AF_INET,SOCK_STREAM,0);
	char msg[256];
	char recm[256];

	// for the serrver structure
	struct sockaddr_in serv_addr;
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(9002);
	serv_addr.sin_addr.s_addr=INADDR_ANY;


	// attempting to conenc to the server
	int con=	connect(socket_client,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

	if(con==-1)
	printf("\n Connection failed");

	// attempting to read what the server is sending
	int reader=recv(socket_client,&msg,sizeof(msg),0);
	
	if(reader==-1)
		printf("receiving failed");


	printf("\nThe message recived from server is :%s",msg);
	
	
	printf("\nSending the echo back to the server %s ",msg);
	
	// attempting to send the rescieved msg back to server
	int sent=send(socket_client,msg,sizeof(msg),0);

	if(sent==-1)
	printf("\n Sending failed");

	close(socket_client);
	return (0);
}
