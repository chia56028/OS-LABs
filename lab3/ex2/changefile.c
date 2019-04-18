#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	FILE* cptr;

	printf("My real user id = %d\n",getuid());
	printf("My effective user id = %d\n",geteuid());

	cptr = fopen("datafile","a");
	if(cptr == NULL){
		printf("Can't open file!\n");
		return 0;
	}
	fprintf(cptr,"My real id = %d\n",getuid());
	fprintf(cptr,"My effective id = %d\n",geteuid());
	fclose(cptr);
	return 0;
}
