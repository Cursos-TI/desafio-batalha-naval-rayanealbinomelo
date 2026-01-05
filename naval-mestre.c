#include <stdio.h>

int main() {

    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com agua
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ---------------- NAVIOS ----------------
    int tamanhoNavio = 3;

    // Navio horizontal
    int linhaH = 1, colunaH = 2;
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Navio vertical
    int linhaV = 4, colunaV = 0;
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Navio diagonal \
    int linhaD1 = 6, colunaD1 = 3;
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    // Navio diagonal /
    int linhaD2 = 2, colunaD2 = 7;
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }

    // ---------------- HABILIDADE CONE ----------------
    int cone[5][5];

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i && i <= 2) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    int origemConeLinha = 0;
    int origemConeColuna = 5;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                if (origemConeLinha + i < 10 && origemConeColuna + j < 10) {
                    if (tabuleiro[origemConeLinha + i][origemConeColuna + j] == 0) {
                        tabuleiro[origemConeLinha + i][origemConeColuna + j] = 5;
                    }
                }
            }
        }
    }

    // ---------------- HABILIDADE CRUZ ----------------
    int cruz[5][5];

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    int origemCruzLinha = 5;
    int origemCruzColuna = 5;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                if (origemCruzLinha + i - 2 >= 0 && origemCruzLinha + i - 2 < 10 &&
                    origemCruzColuna + j - 2 >= 0 && origemCruzColuna + j - 2 < 10) {

                    if (tabuleiro[origemCruzLinha + i - 2][origemCruzColuna + j - 2] == 0) {
                        tabuleiro[origemCruzLinha + i - 2][origemCruzColuna + j - 2] = 5;
                    }
                }
            }
        }
    }

    // ---------------- HABILIDADE OCTAEDRO ----------------
    int octaedro[5][5];

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i + j == 2 || i + j == 4 || (i == 2 && j >= 1 && j <= 3)) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    int origemOctLinha = 7;
    int origemOctColuna = 2;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                if (origemOctLinha + i - 2 >= 0 && origemOctLinha + i - 2 < 10 &&
                    origemOctColuna + j - 2 >= 0 && origemOctColuna + j - 2 < 10) {

                    if (tabuleiro[origemOctLinha + i - 2][origemOctColuna + j - 2] == 0) {
                        tabuleiro[origemOctLinha + i - 2][origemOctColuna + j - 2] = 5;
                    }
                }
            }
        }
    }

    // ---------------- MOSTRA TABULEIRO ----------------
    printf("Tabuleiro Batalha Naval - Nivel Mestre\n\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
