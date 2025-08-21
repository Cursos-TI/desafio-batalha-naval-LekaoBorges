#include <stdio.h>

int main() {
    // Definimos o tamanho do tabuleiro
    int linhas = 10;
    int colunas = 10;
    
    // O tabuleiro é uma matriz (array 2D) de 10x10
    int tabuleiro[10][10];
    
    // As posições do navio na horizontal
    int linha_navio = 4;
    int coluna_navio = 3;
    
    int i, j;
    
    // Preenchemos o tabuleiro com 0s para representar a água
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Colocamos o navio na horizontal, com 3 posições, usando o número 3
    // O loop avança nas colunas, mantendo a mesma linha
    for (j = 0; j < 3; j++) {
        tabuleiro[linha_navio][coluna_navio + j] = 3;
    }
    
    // Agora, exibimos o tabuleiro para ver o navio
    printf("Tabuleiro (0 = agua, 3 = navio):\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Quebra de linha para a próxima linha do tabuleiro
    }
    
    return 0;
}