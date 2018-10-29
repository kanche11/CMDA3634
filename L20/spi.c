#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv){
double stime = omp_get_wtime();
  long long int Ninside = 0; // number of random points inside 1/4 circle
  long long int Ntests = 1000000000;
  long long n;
double x;
double y;
struct drand48_data buff;
double estpi = 0;


int nthreads = atoi(argv[1]);

  omp_set_num_threads(nthreads);

#pragma omp parallel num_threads(nthreads)
{
    int rank = omp_get_thread_num();
    int size = omp_get_num_threads();

  srand48_r(12345*rank,&buff);

  #pragma omp for reduction(+:Ninside)
  for(n=0;n<Ntests;++n){
    drand48_r(&buff,&x);
    drand48_r(&buff,&y);
    
    if(x*x+y*y<1){
      ++Ninside;
    }
  }
}

  estpi = 4.*(Ninside/(double)Ntests);
double time = omp_get_wtime() - stime;
  printf("estPi = %lf\n", estpi);
printf("time = %lf\n", time);

  return 0;
}
