#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Protótipos
void tela(char tabuleiro[3][3]);

int main (){
    char tabuleiro[3][3], jogador;
    int a, b, ganhou = 0, jogadas, linha, coluna;

    for(a=0;a<3;a++){
        for(b=0;b<3;b++){
            tabuleiro[a][b] = ' ';
        }
    }
    tela(tabuleiro);

    for (jogadas = 1; jogadas < 10 && ganhou == 0; jogadas++){
        if (jogadas % 2 == 0){
            jogador = 'O';
        }else{
            jogador = 'X';
        }

        printf("Vez do jogador '%c'!\n",jogador);
        do{
            printf("Digite a linha que deseja (1 a 3): ");
            scanf("%d",&linha);
            if (linha < 1 || linha > 3){
                printf("Posicao indisponivel! Insira uma posicao possivel.\n");
            }
        }while (linha < 1 || linha > 3);
        do{
            printf("Digite a coluna que deseja (1 a 3): ");
            scanf("%d",&coluna);
            if (coluna < 1 || coluna > 3){
                printf("Posicao indisponivel! Insira uma posicao possivel.\n");
            }
        }while (coluna < 1 || coluna > 3);


        if (tabuleiro[linha-1][coluna-1] == ' '){
            tabuleiro[linha-1][coluna-1] = jogador;
            tela(tabuleiro);
        }else{
            tela(tabuleiro);
            printf("O espaco esta ocupado, tente outra casa.\n");
            jogadas--;
        }

        if (tabuleiro[linha-1][0] == tabuleiro[linha-1][1] && tabuleiro[linha-1][1] == tabuleiro[linha-1][2]){
            ganhou = 1;
        }else{
            if (tabuleiro[0][coluna-1] == tabuleiro[1][coluna-1] && tabuleiro[1][coluna-1] == tabuleiro[2][coluna-1]){
                ganhou = 1;
            }else{
                if (linha == coluna && tabuleiro[0][0] == tabuleiro [1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
                    ganhou = 1;
                }else{
                    if (linha + coluna == 4 && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
                        ganhou = 1;
                    }
                }
            }
        }
    }
    if (ganhou == 0){
        printf("Deu velha, tente novamente!\n");
    }else{
        printf("Parabens! O jogador '%c' ganhou.\n",jogador);
    }
}

void tela(char tabuleiro[3][3]){
    system("cls");
    printf("-=-=-=- JOGO DA VELHA -=-=-=-\n\n");
    printf("\t %c | %c | %c\n", tabuleiro[0][0],tabuleiro[0][1],tabuleiro[0][2]);
    printf("\t---+---+---\n");
    printf("\t %c | %c | %c\n", tabuleiro[1][0],tabuleiro[1][1],tabuleiro[1][2]);
    printf("\t---+---+---\n");
    printf("\t %c | %c | %c\n\n", tabuleiro[2][0],tabuleiro[2][1],tabuleiro[2][2]);
    return;
}