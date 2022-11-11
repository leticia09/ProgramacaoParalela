// 3)Este teste é uma maneira fácil de usar uma operação coletiva.
// Esta aplicação é composta por 4 processos MPI e consiste no
// processo MPI 1 enviando o valor 12345 para todos os outros processos MPI.
// Para conseguir isso, você não tem permissão para usar envios individuais,
// em vez disso, você deve usar uma operação coletiva.
// Saída:
// Eu sou o processo 1 e transmito o valor 12345
// (como linhas próximas podem aparecer em qualquer ordem)
// Sou o processo 0 e recebi o valor 12345 via broadcast
// Sou o processo 2 e recebi o valor 12345 via broadcast
// Sou o processo 3 e recebi o valor 12345 via broadcast

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


        int x,retorno;
        if(id_processo == 1)
        {
            x = 12345;
            printf("\nI am process %d and I broadcast value %d\n", id_processo, x);
        }
            MPI_Bcast(&x,1,MPI_INT,1,MPI_COMM_WORLD);

            printf("I am process %d and I received value %d via broadcast",id_processo,x);

    MPI_Finalize();
    printf("\n");
    return 0;
}