#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


    //=========== RECURSIVA PARA MOSTRAR O TABULEIRO

void mostrar (int matriz[10][10]) {

    // PÕE AS LETRAS NA PARTE SUPERIOR DA MATRIZ

    printf("  ");
    for (char c = 'A'; c <= 'I'; c++) {
        printf("%c ", c);
    }
    printf("\n");

    //========== PERCORRE E IMPRIME A TABELA

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
//========== MOSTRAR FORMATO DA HABILIDADE
void habilidade (int matriz [3][5]){

    printf ("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void usa_cone(int matriz[10][10]) {
    int linha_topo; 
    int coluna_topo;
    char letra;

    printf("Digite uma posição (ex: C5): ");
    scanf(" %c%d", &letra, &linha_topo);

    coluna_topo = (letra - 'A') + 1;

    for (int i = 0; i < 3; i++) {
        int lin = linha_topo + i;
        if (lin >= 9) break;  // Evita ultrapassar os limites da matriz

        for (int j = coluna_topo - i; j <= coluna_topo + i; j++) {
            if (j >= 0 && j < 10)  // Garante que está dentro dos limites da matriz
                matriz[lin][j] = 1;
            else {
                printf("posição inválida \n");
                break;
            }
        }
    }
}

int main() {

    //========== TABULEIRO
    int tabuleiro [10][10];
    //========== HABILIDADES
    int cone [3][5], cruz [3][5], octaedro [3][5];
    
    int i, j;

    //========== LÊ A MATRIZ
    for ( i = 0; i < 10; i++) {
        for ( j = 0; j < 10; j++) {
    //========== DECLARA AS CONDIÇÕES DAS POSIÇÕES VERTICAIS E HORIZONTAIS DOS NAVIOS
            if ((i == 9 && j >= 2 && j <= 4) || 
            (i == 7 && j >= 5 && j <= 7) || 
            (j == 9 && i >= 2 && i <= 4) ||
    //========== POSICIONA NAVIOS NAS DIAGONAIS PRINCIPAIS DIREITA E ESQUERDA        
            (i == j && j >= 1 && j <= 3) ||
            (i + j == 9 && j >= 1 && j <= 3)) {
    //========== DEFINE 3 NAS POSIÇÕES DOS NAVIOS
                tabuleiro[i][j] = 3;
            } else {
    //========== DEFINE O RESTANTE COM 0
                tabuleiro[i][j] = 0;
            }
        }
    //========== LISTA PRIMEIRA COLUNA COM NUMERAÇÃO 0 A 9
        tabuleiro[i][0] = i;
    }

    usa_cone (tabuleiro);

    // ========== MOSTRA A TABELA PÓS CÓDIGO
    mostrar (tabuleiro);

    printf("\nHABILIDADE CONE\n");  
    habilidade (cone);

    printf("\nHABILIDADE CRUZ\n");
    habilidade (cruz);

    printf("\nHABILIDADE OCTAEDRO\n");
    habilidade (octaedro);
    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
