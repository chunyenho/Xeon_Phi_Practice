#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000000
int main (void)
{
	int *A, sum = 0, i;
	A = (int *)malloc(sizeof(int)*SIZE);
	//init
	for ( i = 0; i< SIZE; i++)
		A[i] = rand()%2;
	//reduction
	#pragma offload target(mic) in(A:length(SIZE))
	sum = __sec_reduce_add(A[0:SIZE]);
	return 0;
}
