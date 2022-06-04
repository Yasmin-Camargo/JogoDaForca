#ifndef JOGO_H
#define JOGO_H

void animacao_inicio();
char menu();
char sub_menu_iniciar_jogo();
void como_jogar();
void desenvolvedores();
void sorteador();
char sub_menu_arquivo();
void inserir_palavra();
void modo_contra_pessoa(char palavra_obtida[100], char dica_obtida[100]);
void percorrer_palavra_secreta();
void mostra_dica_palavra();
void mostrar_palavra_secreta();

#endif
