#include <omp.h>
#include <iostream>

int main(int argc, const char * argv[]) {
	int k=5;

	omp_set_num_threads(4);
	#pragma omp parallel private(k)
	{
	    #pragma omp for private(k)
	    for(int i=0;i<10;i++)
	    {
	        printf("k=%d ",k);
	        k++;
	    }
	    printf("inner k=%d",k);
	}
	printf("out k=%d",k);

	return 0;
}
