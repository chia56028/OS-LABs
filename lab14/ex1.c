#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#define FILE_LENGTH	0x50

int main(int argc, char *argv[]){
	int fd, count;
	char str[80];
	void *file_memory;

	/* 
	O_RDONLY: read only
	O_WRONLY: write only
	O_RDWR: both read and write
	*/ 
	/* 
	S_IRUSR: read permission bit for the owner of the file
	S_WUSR: write permission bit for the owner of the file
	*/ 
	fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);

	// lseek() 控制讀寫位置
	// 疆域讀寫位置移到文件開頭
	lseek(fd, 0, SEEK_SET);
	write(fd, "", FILE_LENGTH);

	file_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);

	close(fd);


	printf("enter any character:\n");
	while(1 && count<=FILE_LENGTH){
		fgets(str, sizeof(str), stdin);
		count = strlen(file_memory);
		sprintf((char*)file_memory+count, "%s", str);
	}

	munmap((char*)file_memory, FILE_LENGTH);
	return 0;

}