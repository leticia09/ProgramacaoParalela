// 2)Este teste é para você praticar o recurso fundamental do MPI:
// envie uma mensagem. A aplicação que você desenvolve é composta por
// 2 processos MPI, o primeiro envia uma mensagem e o segundo a recebe.
// A mensagem a enviar é apenas um inteiro com o valor 12345.
// O destinatário deve imprimir o valor recebido. Você é livre para escolher
// o valor da tag que deseja.Saída:
// Sou processo 0, envio valor 12345
// Sou processo 1, recebi valor 12345

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
        x = 12345;
        if(id_processo == 0)
        {
            printf("\nI am process %d, I send value %d", id_processo, x);
            MPI_Send(&x,1,MPI_INT,1,1,MPI_COMM_WORLD);
        }
        else if (id_processo == 1)
        {
            MPI_Recv(&retorno,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
            printf("\nI am process %d, I received value %d",id_processo,retorno);
        }
    MPI_Finalize();
    printf("\n");
    return 0;
}