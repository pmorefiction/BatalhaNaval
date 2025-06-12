#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define H 5

int main() {
    int tabuleiro[TAM][TAM];

    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    //Horizontal
    int linhaH = 1, colunaH = 2;
    for (int j = 0; j < NAVIO; j++)
        tabuleiro[linhaH][colunaH + j] = 3;

    //Vertical
    int linhaV = 4, colunaV = 6;
    for (int i = 0; i < NAVIO; i++)
        tabuleiro[linhaV + i][colunaV] = 3;

    //Diagonal
    int linhaD1 = 0, colunaD1 = 0;
    for (int i = 0; i < NAVIO; i++)
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;

    //Diagonal secundário
    int linhaD2 = 2, colunaD2 = 8;
    for (int i = 0; i < NAVIO; i++)
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
