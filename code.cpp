#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 500000
#define NTHREADS 4
int main()
{

    int prime_count = 1;

#pragma omp parallel for schedule(chunk,100) reduction(+:prime_count) num_threads(NTHREADS)
    for ( int i = 3; i <= N ; i+=2)
{
        bool isPrime = true;
        for (int j = 2 ; j <i ; j++)
        {
            if( i % j == 0)
            {
            isPrime = false;
            break;
            }
        }
        if(isPrime)
        {
        prime_count ++;
        }
}
printf("%d",prime_count);
}

