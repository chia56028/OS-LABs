#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// set effective uid to 0
	// seteuid(0);
	// set effective uid to 300
	seteuid(300);
	
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
