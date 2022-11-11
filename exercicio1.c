#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc , char**argv){

    int sendbuf[7];
    int recvcount = 7;
    int sendCounts[4] = {2,1,3,1};
    int displs[4]={5,4,1,0};
    int recBuf[7];
    int rank , size , tamNome ;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

    if(rank == 0){
        for(int i = 0; i<7;i++){
            sendbuf[i] = i+1;
        }
    }

    MPI_Scatterv(sendbuf, sendCounts , displs, MPI_INT , recBuf, recvcount, MPI_INT , 0 , MPI_COMM_WORLD);

    for(int i=0; i< sendCounts[rank] ; i++){
        printf("rank: %d : index: %d recBuf: %d \n" , rank , i, recBuf[i]);
    }
    MPI_Finalize();

    return 0;
}