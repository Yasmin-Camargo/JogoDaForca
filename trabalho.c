/*
Trabalho Final - Programação de computadores

Desenvolvido por:
    BIANCA BEPPLER DULLIUS
    CAROLINE SOUZA CAMARGO
    MARIA JULIA DUARTE LORENZONI
    YASMIN SOUZA CAMARGO
*/

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//ESCOPO DAS FUNÇÕES
void animacao_inicio();
char menu();
int teste_inteiro(char num);


//CÓDIGO
int main()
{
    int op_menu;

    system("color FC"); //CORES Fundo: Branco; Letra: Vermelho claro
    system("title JOGO DA FORCA"); //Altera o nome da janela

    animacao_inicio();

    do{
        op_menu = menu(); //Opção menu
        switch (op_menu) {
            case 1:
                /* code */
            break;

            case 2:
                /* code */
            break;

            case 3:
                /* code */
            break;

            case 4:
                /* code */
            break;

            case 0:
                system("cls");
                printf("\n\n\t*------------------------------------------------------------*    \n\n");
                printf ("\n   \t\t\t       Obrigado por jogar  :)                                   ");
                printf("\n\n\t*------------------------------------------------------------*\n\n\n\n");
                system("pause");
            break;

            default:
                system("cls");
                printf("\n\n");
                printf("      \\_(o_o)_/  \n");
                printf("         | |     \n");
                printf("         / \\    ");
                printf("\n\n  OPCAO INVALIDA, POR FAVOR TENTE NOVAMENTE \n\n\n");
                system("pause");
            break;
        }
    }while(op_menu!=0);

    return 0;
    
}

//FUNÇÕES:
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
}


char menu(){  //menu do jogo
    char op[10]="";
    int novo_op;

    system("cls");
    printf (" \n\t*------------------------------------------------------------*");
    printf (" \n\t|                                                            |");
    printf (" \n\t|                DIGITE A OPCAO DESEJADA                     |");
    printf (" \n\t|                                                            |");
    printf (" \n\t|                                                            |");
    printf (" \n\t|                    0  -  SAIR                              |");
    printf (" \n\t|                                                            |");
    printf (" \n\t|                    1  -  INICIAR JOGO                      |");
    printf (" \n\t|                                                            |");
    printf (" \n\t|                    2  -  MODO CONTRA O COMPUTADOR          |");
    printf (" \n\t|                                                            |");
    printf (" \n\t|                    3  -  COMO JOGAR                        |");
    printf (" \n\t|                                                            |");
    printf (" \n\t|                    4  -  DESENVOLVEDORES                   |");
    printf (" \n\t|                                                            |");
    printf (" \n\t*------------------------------------------------------------*");
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
    novo_op=atoi(op); //converte caracter para inteiro

    return (novo_op);
}

