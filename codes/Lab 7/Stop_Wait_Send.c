/*------------- By G S Nitesh Narayana CED16I044 IIITDM----*/

// INCOMPLETE



#include<stdio.h>
#include<fnctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MAXLINE 80

int main()
{
	int socket_fd,;

	struct sockaddr_in serv_addr;

	int counter;

	socket_fd=socket(AF_INTER,SOCK_STREAM,0);
	
	if ( socket_fd < 0 ) 
  	{
   	 	error ( "error in socket opening " ) ;
  	}

  	bzero ( ( char * ) &serv_addr , sizeof ( serv_addr ) ) ;


	serv_addr.sin_family = AF_INET ;
  	serv_addr.sin_addr.s_addr = INADDR_ANY ;
  	serv_addr.sin_port = htons ( 6000 ) ;
	
	 if ( bind ( socket_fd , ( struct sockaddr * ) &serv_addr , sizeof ( serv_addr ) ) < 0 )
	    error ( "error in binding" ) ;

  	listen ( socket_fd , 5 ) ;
	
	
	return 0;
}
