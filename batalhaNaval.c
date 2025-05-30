#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


//=========== RECURSIVA PARA MOSTRAR O TABULEIRO

void mostrar (int matriz[10][10]) {

    //========== PÕE AS LETRAS NA PARTE SUPERIOR DA MATRIZ
    printf ("\n");
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

//=========== MOSTRAR FORMATO DA HABILIDADE

void habilidade (int matriz [3][5]){

    printf ("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

//============ USO DAS HABILIDADES

void usa_cone(int matriz[10][10]) {
    int linha_topo; 
    int coluna_topo;
    char letra;

    printf("Digite uma posição para lançar-mos a habilidade! (ex: C5): ");
    scanf(" %c%d", &letra, &linha_topo);

    coluna_topo = (letra - 'A') + 1;

     if (linha_topo < 0 || linha_topo + 2 >= 10 || coluna_topo - 2 < 0 || coluna_topo + 2 >= 10) {
        printf("Posição inválida para lançar o cone.\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        int lin = linha_topo + i;
        //==========EVITA SAIR DA MATRIZ
        if (lin >= 9) break; 

        for (int j = coluna_topo - i; j <= coluna_topo + i; j++) {
            if (j >= 0 && j < 10)
                matriz[lin][j] = 1;
        }
    }
}

void usa_octaedro(int matriz[10][10]) {
    int linha_topo;
    int coluna_topo;
    char letra;

    printf("Digite uma posição para lançar a habilidade OCTAEDRO! (ex: C5): ");
    scanf(" %c%d", &letra, &linha_topo);

    coluna_topo = (letra - 'A') + 1;

    if (linha_topo < 0 || linha_topo + 2 >= 10 || coluna_topo - 2 < 0 || coluna_topo + 2 >= 10) {
        printf("Posição inválida para lançar a cruz.\n");
        return;
    }

    // Desenha o octaedro na matriz (início = 1 do topo central)
    int padrao[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < 3; i++) {
        int lin = linha_topo + i;

        for (int j = 0; j < 5; j++) {
            int col = coluna_topo - 2 + j;

            if (padrao[i][j] == 1) {
                matriz[lin][col] = 1;
        }
    }
}
}

void usa_cruz(int matriz[10][10]) {
    int linha_topo;
    int coluna_topo;
    char letra;

    printf("Digite uma posição para lançar a habilidade em Cruz! (ex: C5): ");
    scanf(" %c%d", &letra, &linha_topo);

    coluna_topo = letra - 'A' + 1;

    if (linha_topo < 0 || linha_topo + 2 >= 10 || coluna_topo - 2 < 0 || coluna_topo + 2 >= 10) {
        printf("Posição inválida para lançar a Cruz.\n");
        return;
    }

    // Padrão da estrela
    int padrao[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };

    printf("Posições atingidas:\n");

    for (int i = 0; i < 3; i++) {
        int lin = linha_topo + i;

        for (int j = 0; j < 5; j++) {
            int col = coluna_topo - 2 + j;

            if (padrao[i][j] == 1) {
                matriz[lin][col] = 1;
            }
        }
    }
}

int main() {

    //========== MONTAGEM DO TABULEIRO
    int tabuleiro [10][10];
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

    printf ("Seja bem vindo ao jogo de Batalha naval!\n");
    printf ("Logo a baixo você verá o nosso tabuleiro, já com 5 navios poisicionados!\n");
    printf ("Os navios são representados pelo número 3 e a água pelo 0. \n");
    // ========== MOSTRA O TABULEIRO
    mostrar (tabuleiro);

    printf ("\nEntão, que tal usarmos algumas habilidades para começarmos a jogar?\n");

    printf("\nHABILIDADE CONE\n");
    printf ("A habilidade CONE, tem como padrão a seguinte formação:\n");
    printf ("     1     \n");
    printf ("   1 1 1   \n");
    printf (" 1 1 1 1 1\n");

    usa_cone (tabuleiro);
    mostrar (tabuleiro);

    printf("\nHABILIDADE OCTAEDRO\n");
    printf ("A habilidade OCTAEDRO, tem como padrão a seguinte formação:\n");
    printf ("     1     \n");
    printf ("   1 1 1   \n");
    printf ("     1    \n");
    usa_octaedro (tabuleiro);
    mostrar (tabuleiro);
    

    printf("\nHABILIDADE CRUZ\n");
    printf ("A habilidade CRUZ, tem como padrão a seguinte formação:\n");
    printf ("     1     \n");
    printf (" 1 1 1 1 1 \n");
    printf ("     1    \n");
    usa_cruz (tabuleiro);
    mostrar (tabuleiro);

    printf("\nChegamos ao fim do nosso jogo após termos utilizado todas as habilidades!");

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
