#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3

int main() {
    // Declaração da matriz 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // --- 1. Inicialização do Tabuleiro ---
    // Preenche todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // --- 2. Posicionamento dos Navios ---


    // Navio 1: 
    int navioH_linha = 1;
    int navioH_coluna = 1;
    for (int i = 0; i < 4; i++) {
        tabuleiro[navioH_linha][navioH_coluna + i] = NAVIO;
    }

    // Navio 2:
    int navioV_linha = 3;
    int navioV_coluna = 8;
    for (int i = 0; i < 3; i++) {
        tabuleiro[navioV_linha + i][navioV_coluna] = NAVIO;
    }

    // Navio 3: 
    int navioD1_linha = 3;
    int navioD1_coluna = 2;
    for (int i = 0; i < 5; i++) {
        tabuleiro[navioD1_linha + i][navioD1_coluna + i] = NAVIO;
    }

    // Navio 4: 
    int navioD2_linha = 0;
    int navioD2_coluna = 8;
    for (int i = 0; i < 2; i++) {
        // linha aumenta enquanto a coluna diminui
        tabuleiro[navioD2_linha + i][navioD2_coluna - i] = NAVIO;
    }


    // --- 3. Exibição Completa ---
    printf("===== BATALHA NAVAL - NIVEL AVENTUREIRO =====\n\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n"); // Guia de colunas
    printf("-------------------------\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i); // Guia de linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Imprime o valor da posição (0 para água, 3 para navio)
            printf("%d ", tabuleiro[i][j]);
        }
        // Pula para a próxima linha
        printf("\n");
    }
    
    printf("\nLegenda: %d = Agua, %d = Navio\n", AGUA, NAVIO);
    printf("=============================================\n");

    return 0;
}