#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int main(int argc, char **argv){
int rank, size;
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  long long int Ninside = 0;
  long long int Ntests = 1000000000;
  double estpi = 0;
long long int i;
long long int sum;


srand48(12345);
for(i=0; i<Ntests; ++i){

double x = drand48();
double y = drand48();
if (x*x + y*y <1){
++Ninside;
}
}

MPI_Reduce(&Ninside,&sum,1,MPI_LONG_LONG_INT,MPI_SUM,0,MPI_COMM_WORLD);

 if(rank == 0){
estpi = 4.*(sum/((double)Ntests*size));
printf("estpi = %lf\n sum = %lld\n",estpi,sum);
}
  MPI_Finalize();
  return 0;
}
