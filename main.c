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
char nome[100], dica[100], palavra[100], palavra_secreta[100];
char letra;
int erros = 0;

// ESCOPO DAS FUNÇÕES
void sorteador_palavras();
void percorrer_palavra_secreta();
void mostrar_palavra_secreta();
// CÓDIGO
int main()
{
    int op_menu, op_menu2;
    system("color 5F");              // CORES Fundo: Branco; Letra: Roxo
    system("title JOGO DA FORCA");   // Altera o nome da janela
    setlocale(LC_ALL, "Portuguese"); // habilita a acentuação para o português

    animacao_inicio();
    do
    {
        op_menu = menu(); // Opção menu
        switch (op_menu)
        {
        case 1:
            op_menu2 = 1;
            while (op_menu2 != 0)
            {
                op_menu2 = sub_menu_iniciar_jogo();
                if (op_menu2 == 0)
                {
                    /* code */
                }
                else if (op_menu2 == 1)
                {
                    printf("Digite a palavra secreta: ");
                    scanf("%s", palavra);
                    printf("Digite a dica: ");
                    scanf("%s", dica);

                    mostrar_palavra_secreta();
                    system("pause");

                    while (1)
                    {

                        // system("cls");
                        percorrer_palavra_secreta();
                        // mostrar_boneco(erros);

                        if (strcmp(palavra, palavra_secreta) == 0)
                        {
                            // GANHOU!
                            printf("\nA palavra secreta é ");
                            for (int i = 0; i < strlen(palavra_secreta); i++)
                            {
                                printf("%c", palavra_secreta[i]);
                            }
                            printf("\nPARABENS, VOCE VENCEU!\n");
                            break;
                        }
                        // verifica se perdeu
                        if (erros == 6)
                        {
                            // perdeu
                            //  Mostrar boneco de game over
                            printf("\nJogo perdido. A palavra secreta era %s.\n", palavra);
                            break;
                        }
                    };
                    system("pause");
                    // // Opções boneco se movendo:
                    // incializacao_boneco();
                    // printf("\n\n");
                    // system("cls");
                    // boneco1();
                    // printf("\n\n");
                    // system("pause");
                    // system("cls");
                    // boneco2();
                    // printf("\n\n");
                    // system("pause");
                    // system("cls");
                    // boneco3();
                    // printf("\n\n");
                    // system("pause");
                    // system("cls");
                    // boneco4();
                    // printf("\n\n");
                    // system("pause");
                    // system("cls");
                    // boneco5();
                    // printf("\n\n");
                    // system("pause");
                    // system("cls");
                    // boneco6();
                    // printf("\n\n");
                    // system("pause");
                    // system("cls");
                    // boneco7();
                    // printf("\n\n");
                    // system("pause");
                }
                else if (op_menu2 == 2)
                {
                    sorteador_palavras(nome, dica);
                    printf("Palavra Sorteada ");
                    puts(nome);
                    printf("Dica:  ");
                    puts(dica);
                    printf("\n");
                    system("pause");
                }
                else
                {
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
            sorteador();
            break;
            break;

        case 0:
            system("cls");
            printf("\n\n\t*------------------------------------------------------------*    \n");
            printf("\n   \t\t\t       Obrigado por jogar  :)                                   ");
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
    } while (op_menu != 0);

    return 0;
}

//-----------------------------------------------------------------------------------------

// FUNÇÕES:
// MODO CONTRA O COMPUTADOR
void sorteador_palavras()
{ // Sorteia uma palavra aleatória de um arquivo
    char caractere = 'a', temp[100];
    int quantidade_linhas = 1, verificando_linha = 1, linha_sorteada = 0;

    // Limpando conteúdo das variaveis
    strcpy(nome, "");
    strcpy(dica, "");
    strcpy(temp, "");

    // Abrindo arquivo para leitura
    FILE *arquivo_palavras;
    arquivo_palavras = fopen("arquivos/arq_palavras.txt", "r");
    if (arquivo_palavras == NULL)
    {
        printf("\nERRO ao abrir o arquivo de palavras\n");
    }

    // Contagem de linhas do arquivo
    while ((caractere = fgetc(arquivo_palavras)) != EOF)
    {
        if (caractere == '\n')
        {
            quantidade_linhas++;
        }
    }
    printf("Linhas Totais do Arquivo: %d\n", quantidade_linhas);

    // Sorteando uma linha aleatória do arquivo
    srand(time(NULL));
    linha_sorteada = (rand() % quantidade_linhas) + 1;
    printf("Linha Sorteada: %d \n", linha_sorteada);

    // Posicionando para a linha que foi sorteada
    rewind(arquivo_palavras);
    while ((caractere = fgetc(arquivo_palavras)) != EOF)
    {
        if (caractere == '\n')
        {
            verificando_linha++;
            if (verificando_linha == linha_sorteada)
            {
                break;
            }
        }
    }

    // Leitura do nome
    while ((caractere = fgetc(arquivo_palavras)) != ';')
    {
        temp[0] = caractere;
        strcat(nome, temp); // Copia caracteres no final da string nome
    }

    // Leitura da dica
    while ((caractere = fgetc(arquivo_palavras)) != ';')
    {
        temp[0] = caractere;
        strcat(dica, temp); // Copia caracteres no final da string dica
    }

    fclose(arquivo_palavras);
    return;
}

void mostrar_palavra_secreta()
{
    for (int i = 0; i < (strlen(palavra) - 1); i++)
    {
        char caracter = palavra[i];
        if (strcmp(&caracter, " ") == 0 || strcmp(&caracter, "-") == 0)
        {
            palavra_secreta[i] = '-';
        }
        else
        {
            palavra_secreta[i] = '_';
        }
    }
    printf("\nDica: %s\n", dica);
    for (int a = 0; a < strlen(palavra_secreta); a++)
    {
        printf("%c ", palavra_secreta[a]);
    }
}

void percorrer_palavra_secreta()
{
    system("cls");
    printf("\nDica: %s\n", dica);
    for (int a = 0; a < strlen(palavra_secreta); a++)
    {
        printf("%c ", palavra_secreta[a]);
    }
    printf("\nDigite uma letra : ");
    scanf("%c", &letra);
    int count = 1; // 1=sim 0=não

    for (int i = 0; i < strlen(palavra); i++)
    {
        char caracter = palavra[i];
        if (strcmp(&caracter, &letra) == 0)
        { // certo
            palavra_secreta[i] = letra;
            count = 0;
        }
    }

    if (count == 1)
    {
        erros++;
    }
    system("pause");
    // return;
}
