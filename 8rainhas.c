#include <stdio.h>

void InicializaTabuleiro(char matriz[8][8])
{
 int i, j;
 for (i = 0; i <= 7; i++)
     for (j = 0; j <= 7; j++)
         matriz[i][j] = '-';
}

void MostraTabuleiro(char matriz[8][8])
{
 int i, j;
 printf("_________________\n");
 for (i = 0; i < 8; i++)
     {
      printf("|");
      for (j = 0; j <= 7; j++)
          printf("%c|", matriz[i][j]);
      printf("\n");
     }
     printf("-----------------\n");          
}

int PosicaoValida(char matriz[8][8], int i, int j)
 {
  int x, y;
  if (matriz[i][j] != '-') return 0;
  for (x = 0; x <= 7; x++)
      {
       if (matriz[i][x] != '-') return 0;         //Checa linhas*
      }
  for (y = 0; y <= 7; y++)
      {
       if (matriz[y][j] != '-') return 0;         //checa colunas
      }
  for (x = 0; x <= 7; x++)                        //Checa diagonais
      for (y = 0; y <= 7; y++)
         if ((x - y) == (i - j) || (x + y) == (i + j))
            if (matriz[x][y] != '-') return 0;
 return 1;
 }

main()
{
 char matriz[8][8];
 int cont = 1;
 int i, j;
 
 InicializaTabuleiro(matriz);

 while (cont <= 8)
    {
     MostraTabuleiro(matriz);
     printf("Insira as coordendas de onde deseja colocar a rainha %d.\n", cont);
     printf("(Para reiniciar, insira ""0,0""): ");
     scanf("%d,%d", &i, &j);
     if (i == 0 && j == 0)
	{
	 InicializaTabuleiro(matriz);
	 cont = 1;
         continue;
	}
     i--; j--;
     if (PosicaoValida(matriz, i, j)) matriz[i][j] = (cont + 48);
	else
	   {
	    printf("Posicao invalida! tente novamente!\n");
	    continue;
	   }
     cont++;
    }
 MostraTabuleiro(matriz);
 printf("Parabens! Voce conseguiu!\n");
 getchar();
}
