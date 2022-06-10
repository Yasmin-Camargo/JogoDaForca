#ifndef JOGO_H
#define JOGO_H

//Funções gerais do Jogo
void animacao_inicio();
void como_jogar();
void desenvolvedores();

//Funções de Menu
char menu();
char sub_menu_iniciar_jogo();
char sub_menu_arquivo();
char sub_menu_historico();

//Funções Arquivo Palavra
void sorteador_palavras();
void visualisar_palavras();
void inserir_palavra();
void excluir_palavra();

//Funções de jogo
int modo_contra_pessoa(char palavra_obtida[100], char dica_obtida[100],int modo);
void percorrer_palavra_secreta();
void mostra_dica_palavra();
void mostrar_palavra_secreta();

//LISTA ENCADEADA
struct historico {
	int  jogadas_struct, contador_struct;
    char palavra_struct[100];
    char modo_jogo_struct[100];
	struct historico *prox;
};
typedef struct historico celula;
celula *ini, *pos;

//Funções lista encadeada
celula *cria(void);
void imprime(celula * ini);
void insere(int jogadas_isere_lista, char palavra_isere_lista[100], int cont_isere_lista, char modo_jogo_isere_lista[100], celula *p, int op_atualiza);

//Arquivo + lista encadeada
void atualiza_lista();
void atualiza_arquivo_historico(celula* ini);
celula* retira (celula* ini);

#endif
