#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "racionais.h"

int main ()
{
    /* Variaveis para leitura e structs para racionais */
    int N, MaX, i;
    struct racional R1, R2, Resultado;
    
    /* Inicializador de valores aleatorios com base no tempo e leitura de dados */
    srand (time(NULL));
    scanf("%d %d", &N, &MaX);

    for (i = 1; i <= N; i++)
    {
        /* Impressao de i e sorteio dos racionais */
        printf("%d: ", i);
        R1 = sorteia_r(MaX);
        R2 = sorteia_r(MaX);

		/* Impressao dos racionais com espacamento */
        imprime_r(R1);
        printf(" ");
        imprime_r(R2);
        printf(" ");

        /* Verifica se ambos os racionais sao invalidos */
        if (!valido_r(R1) || !valido_r(R2))
        {
            printf("NUMERO INVALIDO\n");
            return 1;
        }

        /* Verifca se a divisao sera invalida */
        Resultado = divide_r(R1, R2);
        if (!valido_r(Resultado))
        {
            printf("NUMERO INVALIDO\n");
            return 1;
        }

        /* Realiza as operacoes e imprime os racionais resultantes com espacamento */
        imprime_r(soma_r(R1, R2));
        printf(" ");
        imprime_r(subtrai_r(R1, R2));
        printf(" ");
        imprime_r(multiplica_r(R1, R2));
        printf(" ");
        imprime_r(Resultado);
        printf("\n");
    }

    return 0;
}
