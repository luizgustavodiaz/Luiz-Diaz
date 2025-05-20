#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da estrutura da carta do país
typedef struct {
    char estado[2];
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
    float pib_per_capita;
} Carta;

// Função para calcular a densidade demográfica
float calcular_densidade(int populacao, float area) {
    if (area > 0) {
        return (float)populacao / area;
    } else {
        return 0;
    }
}

float calcular_pib_per_capita(float pib, int populacao) {
    if (populacao > 0) { // Correção: Dividir pela população
        return (float)pib * 1000000000.0 / populacao; // Multiplicando o PIB por 1 bilhão
    } else {
        return 0;
    }
}


int main() {
    // cadastramento das cartas
    Carta carta1 = {"SP", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    Carta carta2 = {"RJ", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    // Cálculo da densidade demográfica
    carta1.densidade_demografica = calcular_densidade(carta1.populacao, carta1.area);
    carta2.densidade_demografica = calcular_densidade(carta2.populacao, carta2.area);

    // Cálculo do PIB per capita
    carta1.pib_per_capita = calcular_pib_per_capita(carta1.pib, carta1.populacao);
    carta2.pib_per_capita = calcular_pib_per_capita(carta2.pib, carta2.populacao);


    int escolha;

    printf("\n=== Super Trunfo de Países ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("6 - Pib per capita \n");
    printf("0 - Sair\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    printf("\n--- Comparando: %s vs %s ---\n", carta1.nome, carta2.nome);

    switch (escolha) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %d\n", carta1.nome, carta1.populacao);
            printf("%s: %d\n", carta2.nome, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("%s venceu!\n", carta1.nome);
            } else if (carta2.populacao > carta1.populacao) {
                printf("%s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f\n", carta1.nome, carta1.area);
            printf("%s: %.2f\n", carta2.nome, carta2.area);
            if (carta1.area > carta2.area) {
                printf("%s venceu!\n", carta1.nome);
            } else if (carta2.area > carta1.area) {
                printf("%s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f\n", carta1.nome, carta1.pib);
            printf("%s: %.2f\n", carta2.nome, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("%s venceu!\n", carta1.nome);
            } else if (carta2.pib > carta1.pib) {
                printf("%s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 4: // Número de pontos turísticos
            printf("Atributo: Número de pontos turísticos\n");
            printf("%s: %d\n", carta1.nome, carta1.pontos_turisticos);
            printf("%s: %d\n", carta2.nome, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("%s venceu!\n", carta1.nome);
            } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                printf("%s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 5: // Densidade demográfica
            printf("Atributo: Densidade demográfica\n");
            printf("%s: %.2f\n", carta1.nome, carta1.densidade_demografica);
            printf("%s: %.2f\n", carta2.nome, carta2.densidade_demografica);
            if (carta1.densidade_demografica < carta2.densidade_demografica) {
                printf("%s venceu!\n", carta1.nome);
            } else if (carta2.densidade_demografica < carta1.densidade_demografica) {
                printf("%s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
            case 6: // PIB per capita
            printf("Atributo: PIB per capita (em R$)\n");
            printf("%s: %.2f\n", carta1.nome, carta1.pib_per_capita);
            printf("%s: %.2f\n", carta2.nome, carta2.pib_per_capita);
            if (carta1.pib_per_capita > carta2.pib_per_capita) {
                printf("%s venceu!\n", carta1.nome);
            } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
                printf("%s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 0:
            printf("Saindo do Super Trunfo.\n");
            break;
        default:
            printf("Opção inválida.\n");
    }

    return 0;
}