#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>

int aleat (int min, int max)
{
    return min + rand() % (max - min + 1);
}

int mdc (int a, int b)
{
    /* Variavel temporaria para possibilitar trocas de a com b */
    int temp;

    /* Laço do MDC, metodo de Euclides */
    while (b != 0)
    {
        a %= b;
        temp = a;
        a = b;
        b = temp;
    }

    return a;
}


int mmc (int a, int b)
{
    return a*b/mdc(a,b);
}

struct racional simplifica_r (struct racional r)
{
    /* Variaveis que recebem o MDC e MMC do numerador e denominador de r */
    int MDC = mdc(r.num, r.den);

    /* Simplifica o racional divindo pelo MDC */
    r.num /= MDC;
    r.den /= MDC;

    /* Troca o sinal caso r seja negativo */
    if (r.den < 0)
    {
        r.num = -r.num;
        r.den = -r.den;
    }

    return r;
}

/* Funcao nao utilizada no programa */
struct racional cria_r (int numerador, int denominador)
{
    struct  racional r;

    /* Propriedades do racional */
    r.num = numerador;
    r.den = denominador;
    /* Verifica se o racional eh valido */
    r.valido = valido_r(r);

    return r;
}

struct racional sorteia_r (int n)
{
    struct racional r;

    /* Gera o numerador e denominador aleatorio para o racional e o valida  */
    r.num = aleat(0, n);
    r.den = aleat(0, n);
    r.valido = valido_r(r);

    /* Verifica se o racional eh valido para simplifica-lo */
    if (r.valido)
        return simplifica_r(r);

    return r;
}

void imprime_r (struct racional r)
{
    /* Verificações todos os casos especiais do Racional, antes da impressao */
    if (!r.valido)
        printf("INVALIDO");

    else if (r.num == 0)
        printf("0");
    
    else if (r.den == 1)
        printf("%d", r.num);
        
    else if (r.num == r.den)
        printf("1");
    
    else if (r.num < 0 && r.den < 0)
        printf("%d/%d", -r.num, -r.den);

    else if (r.num < 0 || r.den < 0)
        printf("-%d/%d", abs(r.num), abs(r.den));    
    
    else 
        printf("%d/%d", r.num, r.den);

}

int valido_r (struct racional r)
{
    if (r.den == 0)
        return 0;

    return 1;
}

struct racional soma_r (struct racional r1, struct racional r2)
{
    struct racional resultado;

    /* Propriedades da soma de racionais */
    resultado.den = mmc(r1.den, r2.den);

    int tempNum1 = r1.num * (resultado.den/r1.den);
    int tempNum2 = r2.num * (resultado.den/r2.den);

    resultado.num = tempNum1 + tempNum2;
    resultado.valido = 1;

    /* Devolve o resultado simplificado */
    return simplifica_r(resultado);
}

struct racional subtrai_r (struct racional r1, struct racional r2)
{
    struct racional resultado;

    /* Propriedades da subtracao de racionais */
    resultado.den = mmc(r1.den, r2.den);

    int tempNum1 = r1.num * (resultado.den/r1.den);
    int tempNum2 = r2.num * (resultado.den/r2.den);
    
    resultado.num = tempNum1 - tempNum2;
    resultado.valido = 1;

    return simplifica_r(resultado);
}

struct racional multiplica_r (struct racional r1, struct racional r2)
{
    struct racional resultado;

    /* Propriedades da multiplicacao de racionais */
    resultado.num = r1.num * r2.num;
    resultado.den = r1.den * r2.den;
    resultado.valido = 1;

    return simplifica_r(resultado);
}

struct racional divide_r (struct racional r1, struct racional r2)
{
    struct racional resultado;

    /* Propriedades da divisao de racionais e validacao pela funcao valido_r */
    resultado.num = r1.num * r2.den;
    resultado.den = r1.den * r2.num;
    resultado.valido = valido_r(resultado);
    
    /* Verifica se o resultado eh valido para evitar simplificacao desnecessaria */
    if (resultado.valido == 0)
    	return resultado;

    return simplifica_r(resultado);
}
    
