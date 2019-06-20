#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int page_frame[6][2];
	int i=0, j=0;
	for(i=0; i<6; i++){
		for(j=0; j<2; j++) page_frame[i][j]=-1;
	}
	printf("===================Init===================\n");
	printf("**********Process A page table**********\n");
	printf("\tPage\tFrame\n");
	printf("\t%d\t%d\n",page_frame[0][0],page_frame[0][1]);
	printf("\t%d\t%d\n",page_frame[1][0],page_frame[1][1]);
	printf("\t%d\t%d\n",page_frame[2][0],page_frame[2][1]);
	printf("**********Process A page table**********\n");
	printf("**********Process B page table**********\n");
	printf("\tPage\tFrame\n");
	printf("\t%d\t%d\n",page_frame[3][0],page_frame[3][1]);
	printf("\t%d\t%d\n",page_frame[4][0],page_frame[4][1]);
	printf("\t%d\t%d\n",page_frame[5][0],page_frame[5][1]);
	printf("**********Process B page table**********\n");

	printf("==============Logical memory==============\n");
	printf("**************Process A**************\n");
	printf("\tpage\toffset\tdata\n");
	printf("\t0\t0\t-\n");
	printf("\t0\t1\t-\n");
	printf("\t1\t0\t-\n");
	printf("\t1\t1\t-\n");
	printf("\t2\t0\t-\n");
	printf("\t2\t1\t-\n");
	printf("**************Process B**************\n");
	printf("\tpage\toffset\tdata\n");
	printf("\t0\t0\t-\n");
	printf("\t0\t1\t-\n");
	printf("\t1\t0\t-\n");
	printf("\t1\t1\t-\n");
	printf("\t2\t0\t-\n");
	printf("\t2\t1\t-\n");
	printf("==============Logical memory==============\n");

	printf("==============Physical memory==============\n");
	printf("\tframe\toffset\tdata\n");
	for(i=0; i<16; i++){
		for(j=0; j<2; j++) printf("\t%d\t%d\t-\n",i,j);
	}
	printf("==============Physical memory==============\n");

	int frame_list[16];
	for(i=0; i<16; i++) frame_list[i]=0;
	int x;
	srand(time(NULL));
	for(i=0; i<6; i++){
		x = rand()%16;
		while(frame_list[x]!=0) x = rand()%16;
		frame_list[x]=1;
		page_frame[i][0]=i%3;
		page_frame[i][1]=x;
	}
	printf("=================Paging=================\n");
	for(i=0; i<3; i++) printf("Process A page(%d) -> frame(%d)\n",page_frame[i][0],page_frame[i][1]);
	for(i=3; i<6; i++) printf("Process B page(%d) -> frame(%d)\n",page_frame[i][0],page_frame[i][1]);
	printf("=================Paging=================\n");

	printf("==================Result==================\n");
	printf("**********Process A page table**********\n");
	printf("\tPage\tFrame\n");
	printf("\t%d\t%d\n",page_frame[0][0],page_frame[0][1]);
	printf("\t%d\t%d\n",page_frame[1][0],page_frame[1][1]);
	printf("\t%d\t%d\n",page_frame[2][0],page_frame[2][1]);
	printf("**********Process A page table**********\n");
	printf("**********Process B page table**********\n");
	printf("\tPage\tFrame\n");
	printf("\t%d\t%d\n",page_frame[3][0],page_frame[3][1]);
	printf("\t%d\t%d\n",page_frame[4][0],page_frame[4][1]);
	printf("\t%d\t%d\n",page_frame[5][0],page_frame[5][1]);
	printf("**********Process B page table**********\n");

	printf("==============Logical memory==============\n");
	printf("**************Process A**************\n");
	printf("\tpage\toffset\tdata\n");
	printf("\t0\t0\tA\n");
	printf("\t0\t1\tB\n");
	printf("\t1\t0\tC\n");
	printf("\t1\t1\tD\n");
	printf("\t2\t0\tE\n");
	printf("\t2\t1\tF\n");
	printf("**************Process B**************\n");
	printf("\tpage\toffset\tdata\n");
	printf("\t0\t0\ta\n");
	printf("\t0\t1\tb\n");
	printf("\t1\t0\tc\n");
	printf("\t1\t1\td\n");
	printf("\t2\t0\te\n");
	printf("\t2\t1\tf\n");
	printf("==============Logical memory==============\n");

	char data[12] = {'A','B','C','D','E','F','a','b','c','d','e','f'};

	char physical_memory[32];
	for(i=0; i<32; i++) physical_memory[i]='-';
	for(i=0; i<6; i++){
		x = page_frame[i][1];
		// printf("%d\n", x);
		physical_memory[x*2] = data[i*2];
		physical_memory[x*2+1] = data[i*2+1];
	}
	printf("==============Physical memory==============\n");
	printf("\tframe\toffset\tdata\n");
	for(i=0; i<16; i++){
		for(j=0; j<2; j++) printf("\t%d\t%d\t%c\n",i,j,physical_memory[i*2+j]);
	}
	printf("==============Physical memory==============\n");
	printf("freeframe list:");
	for(i=0; i<16; i++){
		if(frame_list[i]==0) printf("%d ",i);
	}
	printf("\n");
	return 0;
}