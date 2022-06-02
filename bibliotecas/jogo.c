//Biblioteca própia com as funções do jogo

#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <ctype.h>
#include <locale.h>

//ESCOPO DAS FUNÇÕES
void animacao_inicio();
char menu();
char sub_menu_iniciar_jogo();
void como_jogar();
void desenvolvedores();


void animacao_inicio(){ //animação quando o usuário entra no jogo
    system("cls");
    Sleep(100);
    printf ("\n                                                                ");
    printf ("\n   ########   ######   #######   ######                         ");
    Sleep(100);
    printf ("\n      ##      ##  ##   ##        ##  ##                         ");
    Sleep(100);
    printf ("\n      ##      ##  ##   ##  ###   ##  ##                         ");
    Sleep(100);
    printf ("\n  ##  ##      ##  ##   ##   ##   ##  ##                         ");
    Sleep(100);
    printf ("\n  ######      ######   #######   ######                         ");
    printf ("\n \n                                                             ");
    Sleep(300);
     printf ("\n       ######      ######                                       ");
    Sleep(100);
    printf ("\n       ##    ##    ##  ##                                        ");
    Sleep(100);
    printf ("\n       ##    ##    ######                                        ");
    Sleep(100);
    printf ("\n       ##    ##    ##  ##                                        ");
    Sleep(100);
    printf ("\n       ######      ##  ##                                        ");

    Sleep(300);
    printf (" \n \n                                                            ");
    printf ("\n \t   ######   ######   ######   ######   ######                ");
    Sleep(100);
    printf ("\n \t   ##       ##  ##   ##  ##   ##       ##  ##                ");
    Sleep(100);
    printf ("\n \t   ######   ##  ##   #####    ##       ######                ");
    Sleep(100);
    printf ("\n \t   ##       ##  ##   ##  ##   ##       ##  ##                ");
    Sleep(100);
    printf ("\n \t   ##       ######   ##  ##   ######   ##  ##                  ");
    printf (" \n \n                                                            ");
    Sleep(1200);
    return; 
}


char menu(){  //menu do jogo
    char op[10]="";
    int novo_op;

    system("cls");
    printf (" \n\t*----------------------------------------------------------------*");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                DIGITE A OPCAO DESEJADA                         |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                    0  -  SAIR                                  |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                    1  -  INICIAR JOGO                          |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                    2  -  COMO JOGAR                            |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                    3  -  DESENVOLVEDORES                       |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                    4  -  HISTORICO DE JOGADAS                  |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                    5  -  VISUALISAR PALAVRAS DO SORTEADOR      |");
    printf (" \n\t|                                                                |");
    printf (" \n\t*-----------------------------------------------------------------*");
    printf (" \n \n \n                                                          ");
    scanf("%s", &op);

    //Tratamento de Erros: Usuário só pode digitar números (sem o programa dar erro)
    while(isdigit(*op)==0){
        system("cls");
        printf("\n\n");
        printf("      \\_(o_o)_/  \n");
        printf("         | |     \n");
        printf("         / \\    ");
        printf("\n\n   VOCE DIGITOU UM CARACTER ");
        printf("\n\n   Por favor, digite um numero: ");
        scanf("%s", &op);
    }
    novo_op=atoi(op); //Converte caracter para inteiro

    return (novo_op);
}



char sub_menu_iniciar_jogo(){  //submenu do jogo
    char op2[10]="";
    int novo_op2;

    system("cls");
    printf (" \n\t*----------------------------------------------------------------*");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                DIGITE A OPCAO DESEJADA                         |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                    0  -  VOLTAR                                |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                    1  -  MODO CONTRA UMA PESSOA                |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                    2  -  MODO CONTRA O COMPUTADOR              |");
    printf (" \n\t|                                                                |");
    printf (" \n\t*-----------------------------------------------------------------*");
    printf (" \n \n \n                                                          ");
    scanf("%s", &op2);

    //Tratamento de Erros: Usuário só pode digitar números (sem o programa dar erro)
    while(isdigit(*op2)==0){
        printf("\n\n");
        printf("      \\_(o_o)_/  \n");
        printf("         | |     \n");
        printf("         / \\    ");
        printf("\n\n   VOCE DIGITOU UM CARACTER ");
        printf("\n\n   Por favor, digite um numero: ");
        scanf("%s", &op2);
    }
    novo_op2=atoi(op2); //Converte caracter para inteiro

    return (novo_op2);
}

//Texto explicando como jogar
void como_jogar(){
    system("cls");
    printf("\n\n\t\t\t\t\t\tCOMO JOGAR");
    printf (" \n\n *--------------------------------------------------------------------------------------------------------*");
    printf ("\n \n   => O objetivo deste jogo e descobrir uma palavra adivinhando as letras que ela possui. ");
    printf (" \n\n   => A cada rodada, o jogador pode escolher uma letra que suspeite fazer parte da palavra. ");
    printf (" \n      Caso a palavra contenha esta letra, sera mostrado em que posicoes ela esta. ");
    printf (" \n      Caso esta letra nao exista na palavra, sera retirada uma parte do corpo do boneco do jogador. ");
    printf (" \n\n   => Em qualquer momento o jogador pode tentar adivinhar a palavra, mas se errar retira-se algo ao desenho");
    printf (" \n\n   => Se todas as partes do corpo do boneco forem retiradas, o jogador perde a partida.");
    printf (" \n\n   => O jogador vence quando descobrir a palavra (antes de retirar todas partes do boneco)");
    printf (" \n\n\n *--------------------------------------------------------------------------------------------------------*\n");
    printf("\n\t\t\t\t\t\t\t\t\tBom Jogo!\n\n\n");
    system("pause");
}

//Mostrando desenvolvedores do jogo
void desenvolvedores(){
    system("cls");
    
    printf("\n\n  ESTE PROGRAMA FOI DESENVOLVIDO POR:");
    printf (" \n\n   -------------------------------------------------------\n");
    printf("  |   BIANCA BEPPLER DULLIUS                              |\n");
    printf("  |    Email para contato: bianca.bd@inf.ufpel.edu.br     |");
    printf (" \n   -------------------------------------------------------");

    printf (" \n\n   -------------------------------------------------------\n");
    printf("  |   CAROLINE SOUZA CAMARGO                              |\n");
    printf("  |    Email para contato: caroline.sc@inf.ufpel.edu.br   |");
    printf (" \n   -------------------------------------------------------");

    printf (" \n\n   -------------------------------------------------------\n");
    printf("  |   MARIA JULIA DUARTE LORENZONI                        |\n");
    printf("  |    Email para contato: maria.jdl@inf.ufpel.edu.br     |");
    printf (" \n   -------------------------------------------------------");

    printf (" \n\n   -------------------------------------------------------\n");
    printf("  |   YASMIN SOUZA CAMARGO                                |\n");
    printf("  |    Email para contato: yasmin.sc@inf.ufpel.edu.br     |");
    printf (" \n   -------------------------------------------------------\n\n\n ");
    system("pause");
}

