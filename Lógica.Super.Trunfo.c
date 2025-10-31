#include <stdio.h>

/*
=====================================================
    SUPER TRUNFO - Comparação de Cartas (Nível 2)
-----------------------------------------------------
  Autor: Williams Cardozo (Analista de Rede)
  Descrição:
    Este programa compara duas cartas de cidades do
    jogo Super Trunfo com base em um único atributo
    numérico. Ele calcula e exibe a densidade populacional
    e o PIB per capita de cada carta e determina a
    vencedora conforme as regras do jogo.

  Estruturas usadas:
    - struct (para armazenar os dados das cartas)
    - if / if-else (para comparar os atributos)
=====================================================
*/

// Estrutura representando uma carta do Super Trunfo
typedef struct {
    char estado[30];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// Enum para escolher o atributo de comparação
typedef enum {
    POPULACAO,
    AREA,
    PIB,
    DENSIDADE_POPULACIONAL,
    PIB_PER_CAPITA
} Atributo;

// Função principal
int main() {
    // -----------------------------
    // Cadastro das duas cartas
    // -----------------------------
    Carta carta1 = {"São Paulo", "SP01", "São Paulo", 12300000, 1521.11, 745000.0, 50};
    Carta carta2 = {"Rio de Janeiro", "RJ01", "Rio de Janeiro", 6748000, 1182.30, 300000.0, 40};

    // -----------------------------
    // Cálculos derivados
    // -----------------------------
    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;

    float pib_per_capita1 = carta1.pib / carta1.populacao;
    float pib_per_capita2 = carta2.pib / carta2.populacao;

    // -----------------------------
    // Escolha do atributo para comparação
    // (feito diretamente no código)
    // -----------------------------
    Atributo atributo_escolhido = PIB_PER_CAPITA;

    // -----------------------------
    // Exibição dos dados
    // -----------------------------
    printf("=============== DADOS DAS CARTAS ===============\n\n");

    printf("Carta 1 - %s (%s)\n", carta1.nome_cidade, carta1.codigo);
    printf("Estado: %s\n", carta1.estado);
    printf("População: %d habitantes\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.6f\n\n", pib_per_capita1);

    printf("Carta 2 - %s (%s)\n", carta2.nome_cidade, carta2.codigo);
    printf("Estado: %s\n", carta2.estado);
    printf("População: %d habitantes\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.6f\n", pib_per_capita2);

    // -----------------------------
    // Preparação da comparação
    // -----------------------------
    float valor1, valor2;
    char nome_atributo[30];
    int menor_vence = 0; // regra especial para densidade

    switch (atributo_escolhido) {
        case POPULACAO:
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            sprintf(nome_atributo, "População");
            break;
        case AREA:
            valor1 = carta1.area;
            valor2 = carta2.area;
            sprintf(nome_atributo, "Área");
            break;
        case PIB:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            sprintf(nome_atributo, "PIB");
            break;
        case DENSIDADE_POPULACIONAL:
            valor1 = densidade1;
            valor2 = densidade2;
            menor_vence = 1;
            sprintf(nome_atributo, "Densidade Populacional");
            break;
        case PIB_PER_CAPITA:
            valor1 = pib_per_capita1;
            valor2 = pib_per_capita2;
            sprintf(nome_atributo, "PIB per Capita");
            break;
    }

    // -----------------------------
    // Comparação e resultado
    // -----------------------------
    printf("\n=============== COMPARAÇÃO ===============\n");
    printf("Atributo escolhido: %s\n\n", nome_atributo);

    printf("Carta 1 - %s: %.6f\n", carta1.nome_cidade, valor1);
    printf("Carta 2 - %s: %.6f\n\n", carta2.nome_cidade, valor2);

    if (valor1 == valor2) {
        printf("Resultado: Empate! Ambas têm o mesmo valor.\n");
    } else {
        if (menor_vence) {
            if (valor1 < valor2) {
                printf("Resultado: Carta 1 (%s) venceu! (%.6f < %.6f)\n",
                       carta1.nome_cidade, valor1, valor2);
            } else {
                printf("Resultado: Carta 2 (%s) venceu! (%.6f < %.6f)\n",
                       carta2.nome_cidade, valor2, valor1);
            }
        } else {
            if (valor1 > valor2) {
                printf("Resultado: Carta 1 (%s) venceu! (%.6f > %.6f)\n",
                       carta1.nome_cidade, valor1, valor2);
            } else {
                printf("Resultado: Carta 2 (%s) venceu! (%.6f > %.6f)\n",
                       carta2.nome_cidade, valor2, valor1);
            }
        }
    }

    printf("===========================================\n");
    return 0;
}
