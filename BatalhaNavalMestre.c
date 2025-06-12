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

    //Cone, Cruz e Octaedro
    int habilidade[H][H];

    //Cone (expande para baixo)
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (j >= H/2 - i && j <= H/2 + i)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }

    //Aplica cone
    int origem_l = 2, origem_c = 2;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            int lin = origem_l + i - H/2;
            int col = origem_c + j - H/2;
            if (lin >= 0 && lin < TAM && col >= 0 && col < TAM && habilidade[i][j] == 1 && tabuleiro[lin][col] == 0)
                tabuleiro[lin][col] = 5;
        }
    }

    //Cruz (formato de +)
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == H/2 || j == H/2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }

    //Aplica cruz
    origem_l = 5;
    origem_c = 5;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            int lin = origem_l + i - H/2;
            int col = origem_c + j - H/2;
            if (lin >= 0 && lin < TAM && col >= 0 && col < TAM && habilidade[i][j] == 1 && tabuleiro[lin][col] == 0)
                tabuleiro[lin][col] = 5;
        }
    }

    //Octaedro (losango)
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
        int dist_i = (i - H/2 >= 0) ? (i - H/2) : -(i - H/2);
        int dist_j = (j - H/2 >= 0) ? (j - H/2) : -(j - H/2);
            if (dist_i + dist_j <= H/2)
            habilidade[i][j] = 1;
            else
            habilidade[i][j] = 0;
    }
}

    //Aplica octaedro
    origem_l = 7;
    origem_c = 7;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            int lin = origem_l + i - H/2;
            int col = origem_c + j - H/2;
            if (lin >= 0 && lin < TAM && col >= 0 && col < TAM && habilidade[i][j] == 1 && tabuleiro[lin][col] == 0)
                tabuleiro[lin][col] = 5;
        }
    }
