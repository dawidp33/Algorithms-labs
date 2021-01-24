#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char* argv[])
{
    int *tablica;
    int n=atoi(argv[1]);
    tablica=(int*)malloc(n*sizeof(int));

    int i;
    for(i=0;i<n;i++){
		scanf("%d",&tablica[i]);
    }
	clock_t start = clock();
	qsort(tablica, n, sizeof(int), cmpfunc);
	clock_t end = clock();
	double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("for loop took %f seconds to execute \n", cpu_time_used);

   return(0);
}
