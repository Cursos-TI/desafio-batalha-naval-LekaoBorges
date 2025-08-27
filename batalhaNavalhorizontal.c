#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

#define AGUA 0
#define NAVIO 3
#define AREA_AFETADA 5

// Função própria para calcular o valor absoluto, substituindo a abs() da stdlib.h
int valor_absoluto(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

void inicializar_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;
    tabuleiro[5][5] = NAVIO;
    tabuleiro[5][6] = NAVIO;
    tabuleiro[8][3] = NAVIO;
    tabuleiro[8][4] = NAVIO;
}

void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
    }
    printf("\n  +---------------------\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d | ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            switch (tabuleiro[i][j]) {
                case AGUA:         printf("~ "); break;
                case NAVIO:        printf("N "); break;
                case AREA_AFETADA: printf("* "); break;
                default:           printf("? "); break;
            }
        }
        printf("|\n");
    }
     printf("  +---------------------\n\n");
}

void criar_matriz_cone(int matriz_habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (valor_absoluto(j - centro) <= i && i <= centro) {
                matriz_habilidade[i][j] = 1;
            } else {
                matriz_habilidade[i][j] = 0;
            }
        }
    }
}

void criar_matriz_cruz(int matriz_habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                matriz_habilidade[i][j] = 1;
            } else {
                matriz_habilidade[i][j] = 0;
            }
        }
    }
}

void criar_matriz_octaedro(int matriz_habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (valor_absoluto(i - centro) + valor_absoluto(j - centro) <= centro) {
                matriz_habilidade[i][j] = 1;
            } else {
                matriz_habilidade[i][j] = 0;
            }
        }
    }
}

void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int matriz_habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origem_linha, int origem_coluna) {
    int offset = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (matriz_habilidade[i][j] == 1) {
                int alvo_linha = origem_linha - offset + i;
                int alvo_coluna = origem_coluna - offset + j;

                if (alvo_linha >= 0 && alvo_linha < TAMANHO_TABULEIRO && alvo_coluna >= 0 && alvo_coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[alvo_linha][alvo_coluna] = AREA_AFETADA;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int matriz_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matriz_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matriz_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criar_matriz_cone(matriz_cone);
    criar_matriz_cruz(matriz_cruz);
    criar_matriz_octaedro(matriz_octaedro);

    printf("--- HABILIDADE CONE EM (3, 5) ---\n");
    inicializar_tabuleiro(tabuleiro);
    aplicar_habilidade(tabuleiro, matriz_cone, 3, 5);
    exibir_tabuleiro(tabuleiro);

    printf("--- HABILIDADE CRUZ EM (5, 5) ---\n");
    inicializar_tabuleiro(tabuleiro);
    aplicar_habilidade(tabuleiro, matriz_cruz, 5, 5);
    exibir_tabuleiro(tabuleiro);

    printf("--- HABILIDADE OCTAEDRO EM (8, 4) ---\n");
    inicializar_tabuleiro(tabuleiro);
    aplicar_habilidade(tabuleiro, matriz_octaedro, 8, 4);
    exibir_tabuleiro(tabuleiro);

    return 0;
}