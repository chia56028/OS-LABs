#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PortNumber 5555

int main(int argc, char *argv[]){
	struct sockaddr_in address, client_address;
	int sock, byte_recv, client_address_length;
	char buffer[100];

	sock = socket(PF_INET, SOCK_DGRAM, 0);
	if(sock<0) printf("Error creating socket\n");

	bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_port = htons(PortNumber);
	address.sin_addr.s_addr = INADDR_ANY;

	if(bind(sock, (struct sockaddr *)&address, sizeof(address))==-1){
		printf("error binding\n");
		close(sock);
	}
	int address_length = sizeof(address);
	
	byte_recv = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_address, &client_address_length);
	if(byte_recv<0) printf("Error recving packet\n");

	printf("data: %s\n",buffer);
}