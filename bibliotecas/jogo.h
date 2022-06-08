#ifndef JOGO_H
#define JOGO_H

void animacao_inicio();
char menu();
char sub_menu_iniciar_jogo();
void como_jogar();
void desenvolvedores();
void visualisar_palavras();
char sub_menu_arquivo();
void inserir_palavra();
void sorteador_palavras();
int modo_contra_pessoa(char palavra_obtida[100], char dica_obtida[100],int modo);
void percorrer_palavra_secreta();
void mostra_dica_palavra();
void mostrar_palavra_secreta();
void excluir_palavra();

//LISTA ENCADEADA
struct historico {
	int  jogadas_struct, contador_struct;
    char palavra_struct[100];
    char modo_jogo_struct[100];
	struct historico *prox;
};
typedef struct historico celula;
celula *ini, *pos;

//FUNÇÕES LISTA ENCADEADA
void lista_encadeada();
celula *cria(void);
void imprime(celula * ini);
void insere(int jogadas_isere_lista, char palavra_isere_lista[100], int cont_isere_lista, char modo_jogo_isere_lista[100], celula * p);
#endif
