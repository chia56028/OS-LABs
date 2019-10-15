#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
// #include <unistd.h>

void * da_mmap(int d) {
  return mmap(0, 4096, PROT_READ, MAP_SHARED, d, 0);
}

int main(){

	while(1){
		const int SIZE = 4096;
		const char *name = "OS";
		int shm_fd;
		void *ptr;

		shm_fd = shm_open(name, O_RDONLY, 0666);
		// ftruncate(shm_fd, SIZE);

		void * pvtmp = da_mmap(shm_fd); // map first file
  		if (MAP_FAILED == pvtmp){
  			continue;
  		}

		ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
		
		printf("%s", (char *)ptr);
		printf("\n");

		shm_unlink(name);
	}
	return 0;
}

// gcc csu.c -lrt -o csu