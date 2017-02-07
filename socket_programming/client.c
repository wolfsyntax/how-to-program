#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char * argv[]){
	
	int client_sock, port, n;

	struct sockaddr_in server_addr;
	struct hostent *server;

	char buffer[256];

	if(argc < 3){
		printf("Usage: %s hostname port_no\n",argv[0]);
		exit(1);
	}

//	printf("Client starting...\n");

	client_sock = socket(AF_INET, SOCK_STREAM, 0);

	if(client_sock < 0){
		printf("Error: socket() Failed.\n");
		exit(-1);
	}

//	printf("Looking for host '%s'...\n", argv[1]);
	server = gethostbyname(argv[1]);

	if(server == NULL){
		printf("Error: No such host.\n");
		exit(-1);
	}

//	printf("Host found!\n");

	port = atoi(argv[2]);

	memset((char *)&server_addr,0,sizeof(server_addr));

	server_addr.sin_family = AF_INET;

	bcopy((char *) server->h_addr, (char *)&server_addr.sin_addr.s_addr,server->h_length);

	server_addr.sin_port = htons(port);

//	printf("Connecting to server at port %d...\n",port);
	int connect_f = connect(client_sock,(struct sockaddr *)&server_addr,sizeof(server_addr));

	if(connect_f < 0){
		printf("Error: connect() Failed.\n");
		exit(-1);
	}

//	printf("Connection successful\n");
	while(1){
		printf("< ");
		bzero(buffer,256);
		fgets(buffer,255,stdin);

	//	printf("Sending message to server...\n");

		n = send(client_sock,buffer,strlen(buffer),0);
		
		if(n < 0){
			printf("Error: send() Failed.\n");
			exit(-1);
		}
		
	//	printf("Message sent\n");

		bzero(buffer,256);
		n = recv(client_sock,buffer,255,0);
		
		if(n < 0){
			printf("Error: recv() Failed.\n");
			exit(-1);
		}

		printf("[server] > %s",buffer);
	}
	close(client_sock);


	return 0;

}
