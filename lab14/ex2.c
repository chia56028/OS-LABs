#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#define FILE_LENGTH	0x50


int main(int argc, char *argv[])
{
	int fd, start, end;
	char *map_memory;

	fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);
	start = atoi(argv[2]);
	end = atoi(argv[3]);

	map_memory = (char*)mmap(0, FILE_LENGTH, PROT_READ, MAP_SHARED, fd, 0);
	close(fd);

	printf("Substring from [%d] to [%d] is: ", start, end);
	int i;
	for(i= start-1; i<end; i++){
		printf("%c", *(map_memory+i));
	}
	printf("\n");
	munmap((char*)map_memory, FILE_LENGTH);
}