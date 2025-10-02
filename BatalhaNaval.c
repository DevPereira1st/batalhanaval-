#include <stdio.h>

#define NAVIO 3 // Condicional para NAVIO;
#define LINHA 10 // Criando definição para linhas;
#define COLUNA 10 // Criando definição para colunas;
#define AGUA 0 // Valor da água;

#define TABULEIRO 5 // Tabuleiro;
#define HAB 1 // Habilidade usada;

void cone() {
    int tabuleiro[TABULEIRO][TABULEIRO]; //Cria matriz tabuleiro[5][5];
    printf("\n---- CONE ----\n\n");  //Saida no terminal;
    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++){
            if (i == 2 || (i == 1 && j >= 1 && j <= 3) || (i == 0 && j == 2)) {  //Define as linhas do cone;
                tabuleiro[i][j] = HAB;  //Troca linha definida do tabuleiro por 1, valor da definição HAB;
            } else {
                tabuleiro[i][j] = AGUA; //Se não foi definido linha, o valor continua como 0, valor da AGUA;
            }
            printf("%d ", tabuleiro[i][j]); //Imprime tabuleiro no terminal;
        }
        printf("\n"); //Deixa o código organizado;
    }
}

void cruz() {
    int tabuleiro[TABULEIRO][TABULEIRO]; //Cria matriz tabuleiro[5][5];
    printf("\n-- CRUZ --\n\n"); //Saida no terminal;
    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i == 1 || i == 3) && j == 2 || (i == 1 || i == 4) && j == 2 || (i == 1 || i == 0) && j == 2) { //Define as linhas da cruz;
                tabuleiro[i][j] = HAB; //Troca linha definida do tabuleiro por 1, valor da definição HAB;
            } else if (i == 2 && j >= 0 && j <= 5) { //Define as linhas da cruz;
                tabuleiro[i][j] = HAB; //Troca linha definida do tabuleiro por 1, valor da definição HAB;
            } else {
                tabuleiro[i][j] = AGUA; //Se não foi definido linha, o valor continua como 0, valor da AGUA;
            }
            printf("%d ", tabuleiro[i][j]); //Imprime tabuleiro no terminal;
        }
        printf("\n"); //Deixa o código organizado;
    }
}

void octaedro() {
    int tabuleiro[TABULEIRO][TABULEIRO]; //Cria matriz tabuleiro[5][5];
    printf("\n---- OCTAEDRO ----\n\n"); //Saida no terminal;
    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i == 1 || i == 3) && j == 2) { //Define as linhas do octaedro;
                tabuleiro[i][j] = HAB; //Troca linha definida do tabuleiro por 1, valor da definição HAB;
            } else if (i == 2 && j >= 1 && j <= 3) { //Define as linhas do octaedro;
                tabuleiro[i][j] = HAB; //Troca linha definida do tabuleiro por 1, valor da definição HAB;
            } else {
                tabuleiro[i][j] = AGUA; //Se não foi definido linha, o valor continua como 0, valor da AGUA;
            }
            printf("%d ", tabuleiro[i][j]); //Imprime tabuleiro no terminal;
        }
        printf("\n"); //Deixa o código organizado;
    }
}

int main() {

    char letras[10] = { // Variavel letra;
        'A', 'B', 'C', 
        'D', 'E', 'F', 
        'G', 'H', 'I', 
        'J'}; 

    int tabuleiro[LINHA][COLUNA]; //Variavel do tabuleiro;

    int linha_v = 1, coluna_v = 1; //Começa B2;
    int linha_h = 4, coluna_h = 5; //Começa E6;

    int linha_d = 6, coluna_d = 3; //Começa na F4;
    int linha_d2 = 0, coluna_d2 = 6; //Começa na A7;

    int TABULEIRO_cone[LINHA][COLUNA];

    int NAVIO_horizontal[NAVIO] = {NAVIO, NAVIO, NAVIO}; // Variavel do NAVIO na horizontal;
    int NAVIO_vertical[NAVIO] = {NAVIO, NAVIO, NAVIO}; // Variavel do NAVIO na vertical;

    int NAVIO_diagonal[NAVIO] = {NAVIO, NAVIO, NAVIO}; // Variavel do NAVIO na diagonal;
    int NAVIO_diagonal2[NAVIO] = {NAVIO, NAVIO, NAVIO};// Variavel do NAVIO na diagonal;


    for(int i = 0; i < LINHA; i++) 
    {
        for(int j = 0; j < COLUNA; j++) {
            tabuleiro[i][j] = AGUA; // preenche o tabuleiro com 0 = água;
        }
    }

    for(int i = AGUA; i < NAVIO; i++) { //Loop aninhado para diagonal;
        tabuleiro[linha_d + i][coluna_d + i] = NAVIO_diagonal[i]; // NAVIOs na diagonal um;
        for(int j = AGUA; j < NAVIO; j++) {
            tabuleiro[linha_d2 + j][coluna_d2 - j] = NAVIO_diagonal2[j]; //  NAVIOs na diagonal dois;
    }

    }

    for(int i = AGUA; i < NAVIO; i++){ //Loop aninhado para vertical e horizontal;
        tabuleiro[linha_h][coluna_h + i] = NAVIO_horizontal[i]; // NAVIOs na horizontal;
        for(int j = AGUA; j < NAVIO; j++) {
            tabuleiro[linha_v + j][coluna_v] = NAVIO_vertical[j]; //NAVIOs na vertical;
    }

    }

    printf("ＢＡＴＡＬＨＡ ＮＡＶＡＬ\n\n"); // Inicio do jogo;
    printf("  "); 

    for(int j = 1; j < 11; j++) {
        printf("%d ", j); //Imprime número de 1 a 10;
    }

    printf("\n");

    for( int i = 0; i < LINHA; i++) {
        printf("%c ", letras[i]); // Imprime alfabeto de A - J;

        for(int j = AGUA; j < COLUNA; j++){
            printf("%d ", tabuleiro[i][j]); // Completa o tabuleiro com 0s;
        }
        printf("\n");
    }
    printf("\n");

    cone(); //Puxa void cone;
    octaedro(); //Puxa void octaedro;
    cruz(); //Puxa void cruz;

    return 0;
}