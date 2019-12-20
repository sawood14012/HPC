#include <stdio.h>
#include <string.h>
#include "mpi.h"
int main (int argc, char *argv[])
{ 
int rank;
char msg[20];
MPI_Init (&argc, &argv);
MPI_Comm_rank (MPI_COMM_WORLD, &rank);

   if (rank == 0) strcpy(msg,"HELLO MSRIT");
   MPI_Bcast (msg, 20, MPI_CHAR, 0, MPI_COMM_WORLD);
   printf ("[%d] msg = %s\n", rank, msg);
   // Wait for every process to reach this code
   MPI_Barrier (MPI_COMM_WORLD);
   MPI_Finalize();
   return 0;
}
