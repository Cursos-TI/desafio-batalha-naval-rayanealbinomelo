#include <stdio.h>

int main() {

    int tabuleiro[10][10];
    int i, j;

    // Preenche o tabuleiro com agua (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanhoNavio = 3;

    // -------- NAVIO HORIZONTAL --------
    int linhaH = 1;
    int colunaH = 2;

    for (i = 0; i < tamanhoNavio; i++) {
        if (colunaH + i < 10 && tabuleiro[linhaH][colunaH + i] == 0) {
            tabuleiro[linhaH][colunaH + i] = 3;
        }
    }

    // -------- NAVIO VERTICAL --------
    int linhaV = 4;
    int colunaV = 0;

    for (i = 0; i < tamanhoNavio; i++) {
        if (linhaV + i < 10 && tabuleiro[linhaV + i][colunaV] == 0) {
            tabuleiro[linhaV + i][colunaV] = 3;
        }
    }

    // -------- NAVIO DIAGONAL (\) --------
    int linhaD1 = 6;
    int colunaD1 = 3;

    for (i = 0; i < tamanhoNavio; i++) {
        if (linhaD1 + i < 10 && colunaD1 + i < 10) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == 0) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        }
    }

    // -------- NAVIO DIAGONAL (/) --------
    int linhaD2 = 2;
    int colunaD2 = 7;

    for (i = 0; i < tamanhoNavio; i++) {
        if (linhaD2 + i < 10 && colunaD2 - i >= 0) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] == 0) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        }
    }

    // Mostra o tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
