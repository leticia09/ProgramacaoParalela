#include <stdio.h>
#include <stdlib.h>

// 1)Faça um programa em MPI que gere a seguinte saída:
// "Olá Mundo!" do processo MPI 0. Somos 4 processos MPI.
// "Olá Mundo!" do processo MPI 1. Somos 4 processos MPI.
// "Olá Mundo!" do processo MPI 2. Somos 4 processos MPI.
// "Olá Mundo!" do processo MPI 3. Somos 4 processos MPI.

// A ordem não importa

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

    printf("\"Hello World\" from MPI process %d. We are %d MPI processes", id_processo, qtd_processos);
    
    MPI_Finalize();
    return 0;
}