#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 3

void popularR(int matriz[TAM][TAM], int lin, int col, int backup) {
    if (col > 0) {
        popularR(matriz, lin, col - 1, backup);        
        matriz[lin - 1][col - 1] = rand() % 20;
        if(matriz[lin - 1][col - 1] % 2 == 0){
        printf("[%d][%d]: %d\n", lin-1, col-1, matriz[lin - 1][col - 1]);
        }
    } else if (lin - 1 > 0) {
        popularR(matriz, lin - 1, backup, backup);
    }
}

void exibirR(int matriz[TAM][TAM], int lin, int col, int backup, int qtd) {
    qtd = 0;
    if (col > 0) {        
        exibirR(matriz, lin, col - 1, backup, qtd);  
        if(matriz[lin - 1][col - 1] % 2 == 0){
            qtd++;
            printf("%d\t", matriz[lin - 1][col - 1]);
            printf("%d", qtd);
        }      
    } else if (lin - 1 > 0) {
        exibirR(matriz, lin - 1, backup, backup, qtd);
        printf("\n");
    }
}

int main() {    
    int qtd;
    int n = TAM;
    int matriz[TAM][TAM];

    srand(time(NULL));
    popularR(matriz, n, n, n);
    exibirR(matriz, n, n, n, qtd);

    return 1;
}