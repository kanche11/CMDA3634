#include <stdio.h>
#include<mpi.h>
/* To compile
mpicc -o mpiHelloWorld miphelloWorld.c
*/

int main(int argc, char **argv){
  int rank,size;
  MPI_Init(&argc, &argv);
 
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);

   int messageN = 1;
 int messageTag = 999;

   if (rank == 0){
 MPI_Status status;
    int messageIn;
    for (int i =1; i <size;++i){
  MPI_Recv(&messageIn,messageN, MPI_INT,i,messageTag,MPI_COMM_WORLD,&status);
printf("Hello World from %d of %d rank\n",i,size);
    }
   }

   
  if (rank != 0){ 
int messageOut = rank;
MPI_Send(&messageOut,messageN, MPI_INT,0,messageTag,MPI_COMM_WORLD);
  }

  
  MPI_Finalize();
  return 0;
  
}
