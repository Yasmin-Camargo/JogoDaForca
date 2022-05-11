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
int menu();


//CÓDIGO
int main()
{
    int op_menu=1;

    system("color FC"); //CORES Fundo: Branco; Letra: Vermelho claro
    system("title JOGO DA FORCA"); //Altera o nome da janela

    animacao_inicio();

    while(op_menu!=0){
        op_menu = menu();
        switch (op_menu) {
            case 0:
            break;

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

            default:
                system("cls");
                printf("\n\n  OPCAO INVALIDA, POR FAVOR TENTE NOVAMENTE \n\n\n");
                system("pause");
            break;
        }    
    }

    system("cls");
    printf("\n\n\t*------------------------------------------------------------*    \n\n");
    printf ("\n   \t\t\t       Obrigado por jogar  :)                                   ");
    printf("\n\n\t*------------------------------------------------------------*\n\n\n\n");
    system("pause");

    
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


int menu(){  //menu do jogo
    int op;

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
    scanf("%d", &op);

    return (op);
}