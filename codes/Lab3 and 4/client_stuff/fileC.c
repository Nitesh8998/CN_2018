/*------------- By G S Nitesh Narayana CED16I044 IIITDM----*/

#include<unistd.h>
#include<stdlib.h>
#include<string.h>
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

	FILE * fp=fopen("got.txt","w");
	if(NULL == fp)
    {
        printf("Error opening file");
        // return 1;
    }

    int reader;
    printf("\n going to write whats sent by the server" );
	while(reader=recv(socket_client,&recm,sizeof(recm),0)>0)
	{
		
	
		
		fwrite(recm,1,reader,fp);
		//bzero(recm,256);
	}
	

	close(socket_client);
	fclose(fp);
	return (0);
}
