//  ATENÇÃO: para executar o código não esquecer de compilar pelo terminal: 
//  gcc main.c ./bibliotecas/boneco_forca.c -o main


/*
Trabalho Final - Programação de computadores

Desenvolvido por:
    BIANCA BEPPLER DULLIUS
    CAROLINE SOUZA CAMARGO
    MARIA JULIA DUARTE LORENZONI
    YASMIN SOUZA CAMARGO
*/

//BIBLIOTECAS
#include "./bibliotecas/boneco_forca.h"
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
void sorteador_palavras();
void como_jogar();
void desenvolvedores();


//VARIÁVEIS GLOBAIS
char nome[100], dica[100];


//CÓDIGO
int main()
{
    int op_menu, op_menu2;
    system("color 5F"); //CORES Fundo: Branco; Letra: Roxo
    system("title JOGO DA FORCA"); //Altera o nome da janela
    setlocale(LC_ALL, "Portuguese"); //habilita a acentuação para o português

    animacao_inicio();
    do{
        op_menu = menu(); //Opção menu
        switch (op_menu) {
            case 1:
                op_menu2 = 1;
                while (op_menu2 != 0) {
                    op_menu2 = sub_menu_iniciar_jogo();
                    if (op_menu2 == 0) {
                        /* code */
                    } else if (op_menu2==1) {
                        //Opções boneco se movendo:
                        incializacao_boneco();
                        printf("\n\n");
                        system("cls");
                        boneco1();
                        printf("\n\n");
                        system("pause");
                        system("cls");
                        boneco2();
                        printf("\n\n");
                        system("pause");
                        system("cls");
                        boneco3();
                        printf("\n\n");
                        system("pause");
                        system("cls");
                        boneco4();
                        printf("\n\n");
                        system("pause");
                        system("cls");
                        boneco5();
                        printf("\n\n");
                        system("pause");
                        system("cls");
                        boneco6();
                        printf("\n\n");
                        system("pause");
                        system("cls");
                        boneco7();
                        printf("\n\n");
                        system("pause");
                    } else if (op_menu2 == 2){
                        sorteador_palavras();
                        printf("Palavra Sorteada ");
                        puts(nome);
                        printf("Dica:  ");
                        puts(dica);
                        printf("\n");
                        system("pause");
                    } else {
                        printf("Digite uma opcao valida");
                    }
                }
                
            break;

            case 2:
               como_jogar();
            break;

            case 3:
                desenvolvedores();
            break;

            case 4:
                /* code */
            break;

            case 5:
                /* code */
            break;

            case 0:
                system("cls");
                printf("\n\n\t*------------------------------------------------------------*    \n");
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

//-----------------------------------------------------------------------------------------

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

//MODO CONTRA O COMPUTADOR
void sorteador_palavras(){    //Sorteia uma palavra aleatória de um arquivo
	char caractere='a', temp[100];
	int quantidade_linhas=1, verificando_linha=1, linha_sorteada=0;

    //Limpando conteúdo das variaveis
    strcpy(nome,"");
    strcpy(dica,"");
    strcpy(temp,"");
    
	//Abrindo arquivo para leitura
	FILE *arquivo_palavras;
	arquivo_palavras=fopen("arquivos/arq_palavras.txt","r");
	if(arquivo_palavras == NULL) {
		printf("\nERRO ao abrir o arquivo de palavras\n");
		
	}

	//Contagem de linhas do arquivo
	while ((caractere=fgetc(arquivo_palavras)) != EOF) {				
		if (caractere == '\n') {
			quantidade_linhas++;
		}	
	}
	printf("Linhas Totais do Arquivo: %d\n", quantidade_linhas);

	//Sorteando uma linha aleatória do arquivo
	srand(time(NULL));
	linha_sorteada = (rand() % quantidade_linhas)+1;
	printf("Linha Sorteada: %d \n", linha_sorteada);

	//Posicionando para a linha que foi sorteada
	rewind (arquivo_palavras);
	while ((caractere=fgetc(arquivo_palavras)) != EOF) {				
		if (caractere == '\n') {
			verificando_linha++;
			if (verificando_linha == linha_sorteada) {
				break;
			}
		}	
	}

	//Leitura do nome
	while ((caractere=fgetc(arquivo_palavras)) != ';') {
		temp[0]=caractere;				
		strcat(nome, temp);			//Copia caracteres no final da string nome
	}

	//Leitura da dica
	while ((caractere=fgetc(arquivo_palavras)) != ';') {
		temp[0]=caractere;				
		strcat(dica, temp);			//Copia caracteres no final da string dica
	}

    fclose(arquivo_palavras);
    return; 
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