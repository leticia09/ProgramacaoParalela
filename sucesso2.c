#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    MPI_Init(NULL, NULL);
    int qtd_processos;
    int id_processo;

    typedef struct aluno
    {
        int matricula;
        int nota[3];
    }aluno;
    
    aluno *alunos;

    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
    MPI_Status status;

    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo);

    //printf("Processo: %d", id_processo);
    int n;
    scanf("%d", &n);
    alunos = calloc (n, sizeof(alunos));
    
    switch (id_processo)
    {
    case 0:
        {
            printf("\nTotal de Processos: %d", qtd_processos);

            int i;
            for (i = 0; i < n/3; i++)
            {
                alunos[i].matricula = i+1;
                MPI_Send(&alunos[i].nota[1],1,MPI_INT,1,1,MPI_COMM_WORLD);
                MPI_Recv(&alunos[i].nota[1],1,MPI_INT,1,1,MPI_COMM_WORLD,&status);
            }

            for (i = n/3; i < (n*2)/3; i++)
            {
                alunos[i].matricula = i+1;
                MPI_Send(&alunos[i].nota[2],1,MPI_INT,2,1,MPI_COMM_WORLD);
                MPI_Recv(&alunos[i].nota[2],1,MPI_INT,2,1,MPI_COMM_WORLD,&status);
            }

            for (i = (n*2)/3; i < (n*3)/3; i++)
            {
                alunos[i].matricula = i+1;
                MPI_Send(&alunos[i].nota[3],1,MPI_INT,3,1,MPI_COMM_WORLD);
                MPI_Recv(&alunos[i].nota[3],1,MPI_INT,3,1,MPI_COMM_WORLD,&status);
            }
            

            for (i = 0; i < n; i++)
            {
                printf("\nValor retornado pelo aluno %d: %d", i, alunos[i].nota[0]);
                printf("\nValor retornado pelo aluno %d: %d", i, alunos[i].nota[1]);
                printf("\nValor retornado pelo aluno %d: %d", i, alunos[i].nota[2]);
                printf("\nValor retornado pelo aluno %d: %d", i, alunos[i].nota[3]);
            }
        }
        break;
    case 1:
        while (1)
        {
            int x;
            MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD, &status);
            x = 1;
            MPI_Send(&x,1,MPI_INT,0,1,MPI_COMM_WORLD);
        }
        break;
    case 2:
        while (1)
        {
            int x;
            MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD, &status);
            x = 2;
            MPI_Send(&x,1,MPI_INT,0,1,MPI_COMM_WORLD);
        }
        break;
    case 3:
        while (1)
        {
            int x;
            MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD, &status);
            x = 3;
            MPI_Send(&x,1,MPI_INT,0,1,MPI_COMM_WORLD);
        }
        break;
    }

    MPI_Finalize();
    printf("\n");
    return 0;
}