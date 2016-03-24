//Example comes from  https://kheresy.wordpress.com/2006/06/09/%E7%B0%A1%E6%98%93%E7%9A%84%E7%A8%8B%E5%BC%8F%E5%B9%B3%E8%A1%8C%E5%8C%96%E6%96%B9%E6%B3%95%EF%BC%8Dopenmp%EF%BC%88%E4%B8%80%EF%BC%89%E7%B0%A1%E4%BB%8B/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>



void Test( int n )
{
	int i;
	for( i = 0; i < 100000; ++ i )
	{
		//do nothing, just waste time
	}
	printf( "%d, ", n );
}

int main(int argc, char* argv[])
{
	int i;
	#pragma omp parallel for
	for( i = 0; i < 500; ++ i )
		Test( i );
	//system( "pause" );
}
