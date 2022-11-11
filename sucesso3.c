#include <stdio.h>
#include <stdlib.h>

void main()
{
  FILE *arq;
  char Linha[10000];
  char *result;
  int i;

  arq = fopen("teste.txt", "r");
  if (arq == NULL)
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }

  int x;
  i = 1;
  // while (!feof(arq))
  // {
      fseek(arq,0, SEEK_SET);
      result = fgets(Linha, 10000, arq);
      x = ftell(arq);
      // printf("%d",x);
      if (result) 
	      printf("Linha %d : %s",i,Linha);
      i++;
  // }
  fclose(arq);
}