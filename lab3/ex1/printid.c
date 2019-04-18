#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// real uid: which user is running the process
	// effective uid: the temporary privileges of ID obtained by user
	printf(
		"Real		UID = %d\n"
		"Effective 	UID = %d\n",
		getuid(),
		geteuid()
	);
	return 0;
}
