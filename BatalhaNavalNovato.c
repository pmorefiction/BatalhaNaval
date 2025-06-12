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

    int linhaH = 1;
    int colunaH = 2;
    for (int j = 0; j < NAVIO; j++) {
        tabuleiro[linhaH][colunaH + j] = 3;
    }

    int linhaV = 4;
    int colunaV = 6;
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }
