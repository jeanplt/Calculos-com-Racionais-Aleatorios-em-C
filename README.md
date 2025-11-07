# Calculos-com-Racionais-Aleatorios-em-C

Este repositório contém um programa modular em C que realiza cálculos matemáticos com números racionais, sendo estes compostos por inteiros. Como este programa é solução de um trabalho proposto em uma disciplina de programação, ofertada pelo curso de Ciência da Computação da Universidade Federal do Paraná, abaixo teremos o enunciado deste trabalho.

Este trabalho tem como objetivo a implementação de um Tipo Abstrato de Dados (TAD) para números racionais, além de praticar o desenvolvimento de programas na linguagem C. Desenvolva um programa que manipule números racionais, que são números da forma A/B , onde A e B são números inteiros. Os arquivos base contidos neste trabalho são:
- racionais.h: Arquivo (read only) de header com todos os protótipos das funções para manipular a agenda;
- makefile: Ferramenta de compilação do programa a partir do comando make.

No arquivo racionais.h foi definida uma struct para o tipo abstrato de dados racional. Deve ser implementado o arquivo racionais.c conforme especificado no racionais.h fornecido. A função main deve incluir o header racionais.h e deve ter um laço principal que implemente corretamente em C o seguinte pseudo-código:

```
inicialize a semente randomica, uma unica vez em todo o codigo
- sugestao: use "srand (0)" para facilitar os testes
leia um n tal que 0 < n < 100
leia um max tal que 0 < max < 30
para todo i de 1 ate n faca
/* use um unico espaco em branco separando numeros na mesma linha */
imprima o valor de i seguido de um : e um espaco em branco
sortear dois racionais r1 e r2
- os numeradores e denominadores devem estar entre 0 e max
imprima r1 e r2, na mesma linha e nao mude de linha
se r1 ou r2 forem um dos dois invalidos, entao:
imprima "NUMERO INVALIDO" e retorne 1
calcule r1 + r2
calcule r1 - r2
calcule r1 * r2
calcule r1 / r2
se a divisao for invalida, entao:
imprima "NUMERO INVALIDO" e retorne 1
imprima na mesma linha r1 + r2
imprima na mesma linha r1 - r2
imprima na mesma linha r1 * r2
imprima na mesma linha r1 / r2
mude de linha
fim_para
retorne 0
```

Sendo assim, a composição final do programa será a seguinte:
- racionais.h: Arquivo fornecido;
- racionais.c: Implementação do racionais.h;
- resolveRacionais.c: contém a função main que usa os racionais;
- makefile
