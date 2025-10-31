#include <stdio.h>

/*
=====================================================
    DESAFIO: Movimentando as Peças do Xadrez
-----------------------------------------------------
  Autor: Williams (Analista de Rede)
  Nível: Novato
  Objetivo:
    Simular o movimento das peças Torre, Bispo e Rainha
    utilizando estruturas de repetição (for, while, do-while).
-----------------------------------------------------
  Regras:
    - Torre: move-se 5 casas para a direita (usando for)
    - Bispo: move-se 5 casas na diagonal (usando while)
    - Rainha: move-se 8 casas para a esquerda (usando do-while)
=====================================================
*/

int main() {
    // ===============================
    // Movimento da TORRE (com for)
    // ===============================
    int casas_torre = 5;
    printf("=== Movimento da Torre ===\n");
    printf("A Torre se move 5 casas para a direita:\n");

    // Estrutura de repetição FOR
    for (int i = 1; i <= casas_torre; i++) {
        printf("Casa %d: Direita\n", i);
    }

    // Linha separadora
    printf("\n");

    // ===============================
    // Movimento do BISPO (com while)
    // ===============================
    int casas_bispo = 5;
    int i = 1;
    printf("=== Movimento do Bispo ===\n");
    printf("O Bispo se move 5 casas na diagonal (Cima e Direita):\n");

    // Estrutura de repetição WHILE
    while (i <= casas_bispo) {
        printf("Casa %d: Cima, Direita\n", i);
        i++;
    }

    printf("\n");

    // ===============================
    // Movimento da RAINHA (com do-while)
    // ===============================
    int casas_rainha = 8;
    int j = 1;
    printf("=== Movimento da Rainha ===\n");
    printf("A Rainha se move 8 casas para a esquerda:\n");

    // Estrutura de repetição DO-WHILE
    do {
        printf("Casa %d: Esquerda\n", j);
        j++;
    } while (j <= casas_rainha);

    printf("\n=== Fim da Simulação ===\n");

    return 0;
}
