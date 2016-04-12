#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define _POSIX_C_SOURCE >= 199309L
#include <sys/time.h>
#include <time.h>



#define SIZE 50000000
int main ()
{
	long long i,j;
	int* a = (int *)malloc( SIZE * sizeof(int));
	int* b = (int *)malloc( SIZE * sizeof(int));
	int* c = (int *)malloc( SIZE * sizeof(int));
	
	 struct timespec tt1, tt2;

	//init 
	#pragma omp parallel for
	for ( i=0 ; i<SIZE; i++)
	{
		a[i] = rand()%50+1;
		b[i] = rand()%50+1;
	}
	
	clock_gettime(CLOCK_REALTIME, &tt1);
		
	#pragma omp parallel 
	{
		printf("Thread %d start... \n", omp_get_thread_num());
		#pragma omp for
		for ( i=0 ; i<SIZE; i++)
		{
			c[i] = a[i] + b[i];
		}
	}

	clock_gettime(CLOCK_REALTIME, &tt2);
	
	
	//random print result 
	printf("The result(should between 200~10000):%d %d %d %d %d  \n",c[1],c[144],c[1234],c[5234],c[52212]); 
	if(tt2.tv_nsec < tt1.tv_nsec)
		printf("%ldsec %ldnanosec\n\n",tt2.tv_sec - tt1.tv_sec - 1, tt2.tv_nsec - tt1.tv_nsec + 1000000000);
	else
		printf("%ldsec %ldnanosec\n\n",tt2.tv_sec - tt1.tv_sec, tt2.tv_nsec - tt1.tv_nsec);
	return 0;
}
