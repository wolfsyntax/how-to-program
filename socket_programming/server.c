#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

typedef struct sockaddr* socks;

int main(int argc, char * argv[]){

	int server_sock, client_sock, port, client_size, n;

	char buffer[256];

	struct sockaddr_in server_addr, client_addr;

	if(argc < 2){
		printf("Usage: %s port_no\n",argv[0]);
		exit(1);
	}

//	printf("Server starting...\n");

	server_sock = socket(AF_INET, SOCK_STREAM, 0);

	if(server_sock < 0){
		printf("Error: socket() Failed.\n");
		exit(-1);
	}

	strcpy((char *)&server_addr,"");
	port = atoi(argv[1]);

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(port);

	if(bind(server_sock, (socks) &server_addr,sizeof(server_addr)) < 0){
		printf("Error: bind() Failed.\n");
		exit(-1);
	}

	listen(server_sock,5);
	printf("Server listening to port %d...\n", port);
	printf("Waiting for conection(s)...\n");

	
		client_size = sizeof(client_addr);
		client_sock = accept(server_sock, (socks)&client_addr, &client_size);

		if(client_sock < 0){
			printf("Error: accept() Failed.\n");
			exit(-1);
		}
		printf("Client succesfully connected...\n");
	while(1){	
		bzero(buffer,256);
		
		n = recv(client_sock,buffer, 255,0);

		if(n < 0){
			printf("Error: recv() Failed.\n");
			exit(-1);
		}

		printf("[client] > %s",buffer);
		bzero(buffer,256);
		printf("< ");
		fgets(buffer,255,stdin);
		n = send(client_sock,buffer,strlen(buffer),0);

		if(n < 0){
			printf("Error: send() Failed.\n");
			exit(-1);

		}
	}
	printf("Closing connection...\n");
	//closing connection to client
	close(client_sock);

	//closing connection to server
	close(server_sock);

	return 0;
}
