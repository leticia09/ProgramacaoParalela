#include "mpi.h"
#include <stdio.h>

int main()
{
    MPI_Init(NULL, NULL);
    int qtd_processos;
    int id_processo;

    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
    MPI_Status status;

    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo);

    //printf("Processo: %d", id_processo);

    if (id_processo == 0)
    {
        printf("\nTotal de Processos: %d", qtd_processos);

        int x,retorno;

        x = 10;
        printf("\nProcesso %d mandando %d no processo 1", id_processo, x);
        MPI_Send(&x,1,MPI_INT,1,1,MPI_COMM_WORLD);

        printf("\nAguardando retorno do processo 1");
        MPI_Recv(&retorno,1,MPI_INT,1,1,MPI_COMM_WORLD,&status);
        printf("\nValor retornado pelo processo 1: %d",retorno);

    }
    else
    {
        if (id_processo == 1)
        {
            int y;
            printf("\nIniciando recebimento processo %d", id_processo);
            MPI_Recv(&y,1,MPI_INT,0,1,MPI_COMM_WORLD, &status);
            printf("\nValor recebido pelo processo %d: %d",id_processo, y);
            y = 15;
            MPI_Send(&y,1,MPI_INT,0,1,MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    printf("\n");
    return 0;
}