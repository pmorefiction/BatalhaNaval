#include <stdio.h>

#define TAM 10
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    //Horizontal
    int linhaH = 1;
    int colunaH = 2;
    int sobreposicao = 0;
    for (int j = 0; j < NAVIO; j++) {
        if (tabuleiro[linhaH][colunaH + j] != 0) {
            sobreposicao = 1;
        }
    }
    if (!sobreposicao && colunaH + NAVIO <= TAM) {
        for (int j = 0; j < NAVIO; j++) {
            tabuleiro[linhaH][colunaH + j] = 3;
        }
    }
    //Vertical
    int linhaV = 4;
    int colunaV = 6;
    sobreposicao = 0;
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            sobreposicao = 1;
        }
    }
    if (!sobreposicao && linhaV + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaV + i][colunaV] = 3;
        }
    }
    //Diagonal
    int linhaD1 = 0;
    int colunaD1 = 0;
    sobreposicao = 0;
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
            sobreposicao = 1;
        }
    }
    if (!sobreposicao && linhaD1 + NAVIO <= TAM && colunaD1 + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
        }
    }
    //Diagonal secundária
    int linhaD2 = 2;
    int colunaD2 = 8;
    sobreposicao = 0;
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
            sobreposicao = 1;
        }
    }
    if (!sobreposicao && linhaD2 + NAVIO <= TAM && colunaD2 - (NAVIO - 1) >= 0) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
        }
    }

    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("%2d ", j + 1);
    }
    printf("\n");


    for (int i = 0; i < TAM; i++) {
        printf(" %c ", 'A' + i);
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
