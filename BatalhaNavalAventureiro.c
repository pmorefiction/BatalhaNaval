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
