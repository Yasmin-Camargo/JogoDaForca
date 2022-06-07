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
char palavra_enviada[100], dica_enviada[100], jogadas_modo1[100], jogadas_modo2[100];
char letra;

// ESCOPO DAS FUNÇÕES

// CÓDIGO
int main()
int jogadas = 0;
int vitorias = 0;
int derrotas = 0;
{
    int op_menu, op_menu2, op_menu3;
    system("color 5F");              // CORES Fundo: Branco; Letra: Roxo
    system("title JOGO DA FORCA");   // Altera o nome da janela
    setlocale(LC_ALL, "Portuguese"); // habilita a acentuação para o português

    animacao_inicio();
    do
    {
        op_menu = menu(); // Opção menu
        switch (op_menu) {
        case 1:
            op_menu2 = 1;
            while (op_menu2 != 0) {
                op_menu2 = sub_menu_iniciar_jogo();
                if (op_menu2 == 0) {
                    /* code */
                }
                else if (op_menu2 == 1) {
                    // Limpando conteúdo das variaveis 

                    printf("Digite a palavra secreta: ");
                    fflush(stdin);                          //Limpeza da entrada padrão
                    scanf("%[^\n]s", palavra_enviada);              //Leitura com espaços " "
                    fflush(stdin);  
                    printf("Digite a dica: ");
                    scanf("%[^\n]s", dica_enviada);

                    modo_contra_pessoa(palavra_enviada, dica_enviada);
                    system("pause");
                }
                else if (op_menu2 == 2) {
                    sorteador_palavras();
                    
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

        //LISTA JOGADAS
        typedef struct tentativas {
            int jog;
            struct tentativas *prox;
            } JOG;
            //Recebe as jogodas e devolve a lista de jogadas
            JOG* ListaJogadas(int *tentativas, int tamj){
                int i;
                JOG* p = NULL;
                JOG* a = NULL;
                JOG* lista = NULL;
                for(i = 0; i < tamj; i++ )
                
                {
                    p = (JOG*)malloc(sizeof(JOG));
                    p->jog = jogadas[i];
                    p->prox = NULL;
                    if(i==0)
        { 
            lista=p;
        }else{
            a->prox=p;
        }
        a=p;
    }
    return lista;
}

void imprimir(JOG *p){
    printf("\n");
    while(p!=NULL)
    {
        printf("Você jogou %d vezes",p->jog);
        printf("\n");
        p=p->prox;
    }
}
void limparLista(JOG *p){
    JOG *n;
    while(p!=NULL)
    {
        n=p->prox;
        free(p);
        p=n;
    }
}

//LISTA VITORIAS
typedef struct venceu{
    int ganhou;
    struct venceu * prox;
} VIT;

VIT* ListaVitorias(int *vitorias, int tamv){
    int g;
    VIT * v = NULL;
    VIT * b = NULL;
    VIT* lista2 = NULL;
    
    for(g = 0; g < tamv; g++){
        v = (VIT*)malloc(sizeof(VIT));
        v->ganhou = vitorias[g];
        v->prox = NULL;
        
        if(g==0){
            lista=v;
        }else{
            b->prox=v;
        }
        b=v;
    }
    return lista2;
}
void imprimir2(VIT *v){
    printf("\n");
    while(v!=NULL)
    {
        printf("Você ganhou %d vezes",v->ganhou);
        printf("\n");
        v=v->prox;
    }
}
void limparLista2(VIT *v){
    VIT *n;
    while(v!=NULL)
    {
        n=v->prox;
        free(v);
        v=n;
    }
}
//LISTA DERROTAS
typedef struct perdeu{
    int loser;
    struct perdeu * prox;
} DER;

DER* ListaDerrotas(int *derrotas, int tamd){
    int l;
    DER * d = NULL;
    DER * c = NULL;
    DER* lista3 = NULL;
    
    for(l = 0; l < tamd; l++){
        d = (DER*)malloc(sizeof(DER));
        d->loser = derrotas[l];
        d->prox = NULL;
        
        if(l==0){
            lista=d;
        }else{
            c->prox=d;
        }
        c=d;
    }
    return lista3;
}
void imprimir3(DER *d){
    printf("\n");
    while(d!=NULL)
    {
        printf("Você perdeu %d vezes",d->loser);
        printf("\n");
        d=d->prox;
    }
}
void limparLista3(DER *d){
    DER *n;
    while(d!=NULL)
    {
        n=d->prox;
        free(d);
        d=n;
    }
}

int jogadas[100], vitorias[100], derrotas [100];
int tamj = (sizeof(jogadas))/sizeof(int); //tamanho do vetor jogadas
int tamv =(sizeof(vitorias))/sizeof(int); //tamanho do vetor vitorias
int tamd = (sizeof(derrotas))/sizeof(int); //tamanho do vetor derrotas
    
    JOG* p=ListaJogadas(jogadas, tamj);
    VIT* v=ListaVitorias(vitorias, tamv;)
    DER* d=ListaDerrotas(derrotas, tamd);

    imprimir(p);
    imprimir(v);
    imprimir(d);

    //limpar lista(somente depois de usa-la)
    limparLista(p);
    limparLista(v);
    limparLista(d);
    return 0;

        break;
        case 5:
            op_menu3 = 1;
            while (op_menu3 != 0) {
                op_menu3 = sub_menu_arquivo();
                if (op_menu3 == 0) {
                    /* code */

                } else if (op_menu3==1) {
                    visualisar_palavras();
                        
                } else if (op_menu3==2) {
                    inserir_palavra();
                
                } else if (op_menu3==3) {
                    excluir_palavra();
                
                } else {
                    printf("Digite uma opcao valida");
                }
            }
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
