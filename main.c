//  ATENÇÃO: para executar o código não esquecer de compilar pelo terminal:
//  gcc main.c ./bibliotecas/boneco_forca.c ./bibliotecas/jogo.c -o main

/*
Trabalho Final - Programação de computadores

Desenvolvido por:
    BIANCA BEPPLER DULLIUS
    CAROLINE SOUZA CAMARGO
    MARIA JULIA DUARTE LORENZONI
    YASMIN SOUZA CAMARGO
*/

// BIBLIOTECAS PRÓPIAS
#include "./bibliotecas/boneco_forca.h" //Biblioteca com as versões do boneco forca
#include "./bibliotecas/jogo.h"         //Biblioteca com as funções do jogo

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <ctype.h>
#include <locale.h>

// VARIÁVEIS GLOBAIS
char palavra_enviada[100], dica_enviada[100];

// CÓDIGO
int main()
{
    int op_menu, op_menu2, op_menu3, op_menu4;
    
    system("color 5F");                 // CORES Fundo: Branco; Letra: Roxo
    system("title JOGO DA FORCA");      // Altera o nome da janela
    setlocale(LC_ALL, "Portuguese");    // habilita a acentuação para o português

    animacao_inicio(); //Animação quando usuário entra no jogo


    //Verificar se o arquivo histórico existe
    FILE *hist_jogadas;
    if (hist_jogadas = fopen("./arquivos/historico.txt", "r")) {
        fclose(hist_jogadas); 
        atualiza_lista(); //Caso exista, adicionar jogadas na lista encadeada
    } else {
        fclose(hist_jogadas);  
        hist_jogadas = fopen("./arquivos/historico.txt","w");  ////Caso não exista, cria o arquivo para armazenar as jogadas
        fclose(hist_jogadas); 
    }
   
    //MENU DO JOGO
    do {
        op_menu = menu();  // Função Mostrar o menu
        switch (op_menu) {
        case 1: //Opção menu: Iniciar jogo
            op_menu2 = 1;
            while (op_menu2 != 0) {
                op_menu2 = sub_menu_iniciar_jogo(); 
                if (op_menu2 == 0) {
                    /* code */
                }
                else if (op_menu2 == 1) { //Opção: Modo contra o jogador
                    // Limpando conteúdo das variaveis 
                    printf("Digite a palavra secreta: ");
                    fflush(stdin);                          //Limpeza da entrada padrão
                    scanf("%[^\n]s", palavra_enviada);      //Leitura com espaços " "
                    fflush(stdin);  
                    printf("Digite a dica: ");
                    scanf("%[^\n]s", dica_enviada);

                    modo_contra_pessoa(palavra_enviada, dica_enviada,0); //Função de execução do jogo em si
    
                    system("pause");
                }

                else if (op_menu2 == 2) { //Opção: Modo contra o computador
                    sorteador_palavras();
                    system("pause"); 
                } 
                
                else {
                    printf("Digite uma opcao valida");
                }
            }
            break;

        case 2: //Opção menu: Como jogar
            como_jogar();
            break;

        case 3: //Opção menu: Desenvolvedores
            desenvolvedores();
            break;

        case 4: //Opção menu: Histórico
            op_menu4 = 1;
            while (op_menu4 != 0) {
                op_menu4 = sub_menu_historico();
                if (op_menu4 == 0) { 
                    /* code */

                } else if (op_menu4==1) { //Opção: Visualizar Histórico
                    imprime(ini); //Mostra conteúdo da lista encadeada
                    system("pause");
                        
                } else if (op_menu4==2) { //Opção: Excluir Registro
                    retira(ini);  //Busca e exclui item do histórico na lista encadeada

                } else {
                    printf("Digite uma opcao valida");
                }
            }
            
            break;

        case 5: //Opção menu: Arquivo de palavras
            op_menu3 = 1;
            while (op_menu3 != 0) {
                op_menu3 = sub_menu_arquivo();
                if (op_menu3 == 0) {
                    /* code */

                } else if (op_menu3==1) { //Opção: Visualizar Palavras sorteador
                    visualisar_palavras();
                        
                } else if (op_menu3==2) { //Opção: Adicionar uma palavra
                    inserir_palavra();
                
                } else if (op_menu3==3) { //Opção: Excluir palavra
                    excluir_palavra();
                
                } else {
                    printf("Digite uma opcao valida");
                }
            }
        break;

        case 0: //Opção menu: Sair do jogo
            system("cls");
            printf("\n\n\t*------------------------------------------------------------*    \n");
            printf("\n   \t\t\t       Obrigado por jogar  :)                                   ");
            printf("\n\n\t*------------------------------------------------------------*\n\n\n\n");
            system("pause");
            break;

        default: //Nenhuma das opçoes: Mensagem de erro
            system("cls");
            printf("\n\n");
            printf("      \\_(o_o)_/  \n");
            printf("         | |     \n");
            printf("         / \\    ");
            printf("\n\n  OPCAO INVALIDA, POR FAVOR TENTE NOVAMENTE \n\n\n");
            system("pause");
            break;
        }
    } while (op_menu != 0);
    
    return 0;
}