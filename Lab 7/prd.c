#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main(){
	const int SIZE = 4096;
	const char *name = "OS";
	int shm_fd;
	void *ptr;

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd, SIZE);
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	
	char str[256];
	if(fgets(str,sizeof(str), stdin) != NULL){
		sprintf(ptr, "%s", str);
		ptr += strlen(str);
	}
	return 0;
}

// gcc prd.c -lrt -o prd