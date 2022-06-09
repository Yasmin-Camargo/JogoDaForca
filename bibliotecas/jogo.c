//Biblioteca própia com as funções do jogo

#include "jogo.h"
#include "boneco_forca.h" //Biblioteca com as versões do boneco forca
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
void visualisar_palavras();
char sub_menu_arquivo();
void inserir_palavra();
void sorteador_palavras();
int modo_contra_pessoa(char palavra_obtida[100], char dica_obtida[100],int modo);
void percorrer_palavra_secreta();
void mostra_dica_palavra();
void mostrar_palavra_secreta();
void excluir_palavra();

//Funções lista encadeada
void lista_encadeada();
celula *cria(void);
void imprime(celula * ini);
void insere(int jogadas_isere_lista, char palavra_isere_lista[100], int cont_isere_lista, char modo_jogo_isere_lista[100], celula * p);


//VARIAVEIS GLOBAIS
char nome[100], dica[100], palavra[100], palavra_secreta[100], letras_digitadas[100];
char letra;
int erros = 0, contador;


//FUNÇÕES
void animacao_inicio(){ //animação quando o usuário entra no jogo
    ini = cria(); //Cria Lista encadeada
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
    printf (" \n\t|                    5  -  ARQUIVO DE PALAVRAS                   |");
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


char sub_menu_arquivo(){  //submenu do jogo ARQUIVO
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
    printf (" \n\t|                    1  -  VISUALISAR PALAVRAS DO SORTEADOR      |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                    2  -  ADICIONAR UMA PALAVRA                 |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                    3  -  EXCLUIR UMA PALAVRA                   |");
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

//-----------------------------------------------------------------------------------------
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
    modo_contra_pessoa(nome,dica,2);

}


//-----------------------------------------------------------------------------------------
// FUNÇÕES DE MANIPULAÇAO DO ARQUIVO PALAVRAS

//Função para ler palavras 
void visualisar_palavras(){
    system("cls");
    char caractere, aux[3]="", palavra[20];
    int cont=1;

    //Limpando strings
    strcpy(palavra,"");
    strcpy(aux,"");
 
    //Abrindo arquivo para leitura
    FILE *arquivo_palavras;
    arquivo_palavras=fopen("arquivos/arq_palavras.txt","r");
    if(arquivo_palavras == NULL) {
        printf("\nERRO ao abrir o arquivo de palavras\n");  
    }
 
    //Lendo arquivo
    printf (" \n\t*-----------------------------------------------------------------*\n");
    printf("\n\n\tLINHA\t\t\t  PALAVRA    \t \t         DICA    \n\n\t");
    printf("%5d", cont);
    while( (caractere=fgetc(arquivo_palavras))!= EOF ){	
        aux[0]=caractere;
		if(caractere == ';'){
            printf("%28s", palavra);
            strcpy(palavra,"");
        }
        else if (caractere == '\n') {
            cont++;
            printf("\n\n\t%5d", cont);
        }
        else if (caractere != '\n'){
            strcat(palavra, aux);	
        }
	}

    printf ("\n\n\n\t*-----------------------------------------------------------------*\n");
    printf("\n\n");
 
    //Fechando arquivo
    fclose(arquivo_palavras);
    system("pause");
}

//Função para inserir palavras
void inserir_palavra(){
    char palavra_adicionada[100], dica_adicionada[100];
    char caracter, palavra_lida[100], aux[3];
    int gravar;
    
    //Inicializando variaveis
    gravar=1; 
    caracter=' ';
    strcpy(palavra_lida," ");
    strcpy(dica_adicionada," ");
    strcpy(palavra_adicionada," ");
    strcpy(aux," ");
    
    //Abrindo arquivo para escrita e leitura
	FILE *arquivo_palavras;
	arquivo_palavras=fopen("./arquivos/arq_palavras.txt","a+");
	if(arquivo_palavras == NULL) {
		printf("\nERRO ao abrir o arquivo de palavras\n");
	}
    
    fflush(stdin);  //Descarregando buffers de saída
    system("cls");
    printf("\n  Digite a palavra para ser adicionada no arquivo: ");
    scanf("%[^\n]s", palavra_adicionada);
   
    fflush(stdin);  //Descarregando buffers de saída
    printf("\n  Digite a dica da palavra: ");
    scanf("%[^\n]s", dica_adicionada);
    fflush(stdin);  //Descarregando buffers de saída
 
    
    //Teste para verificar se a palavra já existe  no arquivo
    while( (caracter=fgetc(arquivo_palavras))!= EOF ){	
        aux[0]=caracter;		
		if(caracter == ';'){
            if(strcmp(palavra_adicionada, palavra_lida)==0){
                gravar=0;
            }
            strcpy(palavra_lida,"");
        }
        else if (caracter != '\n'){
            strcat(palavra_lida, aux);	
        }
	}

    if(gravar == 1){    //Adiciona palavra e dica no arquivo
        fprintf(arquivo_palavras,"\n");
        fprintf(arquivo_palavras,palavra_adicionada);
        fprintf(arquivo_palavras,";");

        fprintf(arquivo_palavras,dica_adicionada);
        fprintf(arquivo_palavras,";");

        system("cls");
        printf("\n\n  Palavra adicionada com sucesso\n\n");
        system("pause");
    }
    else{
        system("cls");
        printf("\n\n  ERRO!!");
        printf("\n  Esta palavra ja existe no arquivo\n\n");
        system("pause");
    }
    fclose(arquivo_palavras);
}

//Função para excluir uma palavra do arquivo
void excluir_palavra(){
    char palavra_excluida[100];
    char caracter, palavra_lida[100], aux[3];
    int excluir, quantidade_linhas=1, linha_excluir, cont_linhas=1;
    
    //Inicializando variaveis
    excluir=0; 
    caracter=' ';
    strcpy(palavra_lida,"");
    strcpy(palavra_excluida," ");
    strcpy(aux," ");
    
    //Abrindo arquivo para escrita 
	FILE *arquivo_palavras;
	arquivo_palavras=fopen("./arquivos/arq_palavras.txt","r");
	if(arquivo_palavras == NULL) 
    {
		printf("\nERRO ao abrir o arquivo de palavras\n");
	}

    //Abrindo arquivo temporário para escrita e leitura
    FILE *arquivo_palavras_temp;
    arquivo_palavras_temp=fopen("./arquivos/arq_palavras_temp.txt","w+");
    if(arquivo_palavras_temp == NULL) 
    {
        printf("\nERRO ao abrir o arquivo de palavras\n");
    }

    // Contagem de linhas totais do arquivo
    while ((caracter = fgetc(arquivo_palavras)) != EOF){
        if (caracter == '\n') {
            quantidade_linhas++;
        }
    }
    
    system("cls");
    fflush(stdin);  //Descarregando buffers de saída
    printf("\n  Digite a palavra para ser excluida do arquivo: ");
    scanf("%[^\n]s", palavra_excluida);
    fflush(stdin);  //Descarregando buffers de saída
   
    //Teste para verificar se a palavra já existe no arquivo
    //A função também salva uma cópia do arquivo original em um temporário sem a linha correspondente da palavra excluida
    rewind(arquivo_palavras);   //Posicionando ponteiro do arquivo para o início
    while( (caracter=fgetc(arquivo_palavras))!= EOF ) {
        aux[0]=caracter;	
		if(caracter == ';') {
            if(strcmp(palavra_excluida, palavra_lida)==0) {     //Quando encontra no arquivo a palavra que quer excluir 
                excluir=1;
                linha_excluir = cont_linhas;
                caracter=fgetc(arquivo_palavras);
                while ((caracter=fgetc(arquivo_palavras))!= ';')
                {
                    //Pula leitura da linha da palavra a ser excluida e não grava no arquivo temporário
                }
                caracter=fgetc(arquivo_palavras);
            } else{
                fprintf(arquivo_palavras_temp,palavra_lida);
                fprintf(arquivo_palavras_temp,";");
            }
            strcpy(palavra_lida,"");
        } 
        else if (caracter == '\n') {
            cont_linhas++;
            if (cont_linhas == (quantidade_linhas)) {
                //Não pode gravar o \n no arquivo, caso seja a última linha
            } else {
                fprintf(arquivo_palavras_temp,"\n");
            }
        }
        else if (caracter != '\n') {
            strcat(palavra_lida, aux);	
        }
	}

    //Atualização do arquivo sem a linha excluida
    if(excluir == 1)    //Caso o arquivo original tenha sido modificado 
    { 
        //Abrindo para escrita
        arquivo_palavras=fopen("./arquivos/arq_palavras.txt","w");
        if(arquivo_palavras == NULL) 
        {
            printf("\nERRO ao abrir o arquivo de palavras\n");
        }

        system("cls");
        rewind(arquivo_palavras_temp);
        while ((caracter=fgetc(arquivo_palavras_temp))!= EOF)
        {
            aux[0] = caracter;
            fprintf(arquivo_palavras,aux);
        }

        //Removendo arquivo temporário
        char nome_remove[]="./arquivos/arq_palavras_temp.txt";  
        fclose(arquivo_palavras_temp);                          
        remove(nome_remove);

        printf("\n\n..... Palavra excluida com sucesso .....\n\n");
        printf("\n Palavra excluida: %s", palavra_excluida);
        printf("\n Linha do arquivo que foi excluida: %d\n\n", linha_excluir);
        system("pause");
    } 
    else    //Caso o arquivo original não tenha sido modificado
    {
        system("cls");
        printf("\n\n  ERRO: NAO FOI POSSIVEL EXCLUIR!!");
        printf("\n  Esta palavra nao existe no arquivo\n\n");

        //Removendo arquivo temporário
        char nome_remove[]="./arquivos/arq_palavras_temp.txt";  
        fclose(arquivo_palavras_temp);                          
        remove(nome_remove);

        system("pause");
    }
    fclose(arquivo_palavras);
}


//-----------------------------------------------------------------------------------------
//MODO CONTRA PESSOA
int modo_contra_pessoa(char palavra_obtida[100], char dica_obtida[100], int modo){
    strcpy(palavra_secreta, "\0");
    strcpy(palavra, "\0");
    strcpy(letras_digitadas,"\0");
    int jogadas = 0;
    char palavra_enviada[100];

    erros=0;

    strcpy(palavra,palavra_obtida);
    strcpy(dica,dica_obtida);

    mostrar_palavra_secreta();

    while (1)
    {
        // system("cls");
        percorrer_palavra_secreta();
        // mostrar_boneco(erros);
                        
        if (strcmp(palavra, palavra_secreta) == 0)
        {
             // GANHOU!
            system("cls");
            printf("\n\n       PARABENS!!! VOCE VENCEU!\n\n");
            boneco8();
            printf("\n\n");
            printf("\tPalavra: %s\n\n", palavra);
            break;
        }
        // verifica se perdeu
        if (erros == 6)
        {
            // perdeu
            //  Mostrar boneco de game over
            system("cls");
            printf("\n\n       VOCE PERDEU! :(\n\n");
            boneco7();
            printf("\n\n");
            printf("\tA palavra secreta era %s", palavra);
            printf("\n\n");
            break;
        }
    };
    contador++;

    //Adiciona dados na lista encadeada
    if (modo==0){
        insere(erros,palavra,contador,"Modo contra uma pessoa",ini);
    }
    else if (modo==2){
        insere(erros,palavra,contador,"Modo contra o computador",ini);
    }
    return(erros);
}


void mostrar_palavra_secreta(){
    strcpy(palavra_secreta,palavra); //Define o tamanho da palavra secreta (para não dar erro)
    for (int i=0; i<(strlen(palavra)); i++)
    {
        //Casos especiais
        if (palavra[i] == ' ' ){
            palavra_secreta[i] = ' ';
        } else if (palavra[i] == '-')
        {
            palavra_secreta[i] = '-';
        } else
        {
            palavra_secreta[i] = '_';
        }
    }
}

void percorrer_palavra_secreta()
{
    int gravar=1;
    char aux[3];

    strcpy(aux," ");
    fflush(stdin);
    system("cls");
    if (erros == 0)
    {
        system("cls");
        incializacao_boneco();
        printf("\n\n");
    }
    else if (erros == 1)
    {
        system("cls");
        boneco1();
        printf("\n\n");
    }
    else if (erros == 2)
    {
        system("cls");
        boneco2();
        printf("\n\n");

    }
    else if (erros == 3)
    {
        system("cls");
        boneco3();
        printf("\n\n");
    }
    else if (erros == 4)
    {
        system("cls");
        boneco4();
        printf("\n\n");
    }
    else if (erros == 5)
    {
        system("cls");
        boneco5();
        printf("\n\n");
    }
    else if (erros == 6)
    {
        system("cls");
        boneco6();
        printf("\n\n");
    }
    
    mostra_dica_palavra();
    printf("   Digite uma letra: ");
    scanf("%c", &letra);
    aux[0] = letra;

    //Verifica se a letra já foi digitada
    for (int i=0; i< strlen(letras_digitadas); i++){
        if (letra == letras_digitadas[i]){
            printf("\n\t\t--- LETRA JA FOI DIGITADA --- \n\n");
            system("pause");
            gravar = 0;
        }
    }

    if (gravar == 1){
        strcat(letras_digitadas,aux);
        strcat(letras_digitadas,"-");
        int count = 1; // 1=sim 0=não

        for (int i=0; i<strlen(palavra); i++)
        {
            if (palavra[i] == letra)
            { // certo
                palavra_secreta[i] = letra;
                count = 0;
            }
        }

        if (count == 1)
        {
            erros++;
        }
    }
   
    // return;
}

void mostra_dica_palavra(){
    printf(" \tDica: %s\t\t", dica);
    for (int a = 0; a < strlen(palavra_secreta); a++)
    {
        printf("%c ", palavra_secreta[a]);
    }
    printf("\n\n");
    printf("  %s ", letras_digitadas);
    printf("\n\n");
}

//-------------------------------------------------------------------------------------
//FUNÇÕES LISTA ENCADEADA

//Cria a Lista encadeada
celula *cria(void)
{
	celula *start;

	start = (celula *) malloc(sizeof(celula));
	start->prox = NULL;
	return start;
}

//Insere dados na Lista
void insere(int jogadas_isere_lista, char palavra_isere_lista[100], int cont_isere_lista, char modo_jogo_isere_lista[100], celula * p){
//Cria arquivo para armazenar o histórico
    FILE *hist_jogadas;
    char resultados_modo_jogo[100]; 
    char resultados_palavra[100];
    char resultados_jogadas[100];
//Se o histórico não estiver vazio, pega os dados anteriores do historico e cola para ser usado na lista 
    if (resultados_modo_jogo !=0){
        strcpy(modo_jogo_isere_lista, resultados_modo_jogo);
    }
    if(resultados_jogadas != 0){
        strcpy(jogadas_isere_lista, resultados_jogadas);
    }
    if(resultados_palavra != 0){
        strcpy(palavra_isere_lista, resultados_palavra);
    }
	
	celula *nova;
	nova = (celula *) malloc(sizeof(celula));

	nova->jogadas_struct = jogadas_isere_lista; //Insere as jogadas
    strcpy(nova->palavra_struct, palavra_isere_lista); //Insere a palavra
    nova->contador_struct = cont_isere_lista; //Insere qual é o numero em que esta a lista 
    strcpy(nova->modo_jogo_struct, modo_jogo_isere_lista); //Insere o modo de jogo

	nova->prox = p->prox;
	p->prox = nova;
	
	
	hist_jogadas = fopen("./arquivos/historico.txt","a");
        printf("Historico de Jogadas");
        fprintf(hist_jogadas,"\n");
        fprintf(hist_jogadas, "Modo de jogo: %s \n", resultados_modo_jogo);
        fprintf(hist_jogadas,"Palavra Sorteada: %s\n", resultados_palavra);
        fprintf(hist_jogadas,"Quantidade de erros: %d\n", resultados_jogadas);
        fclose(hist_jogadas);
}

//Mostra a Lista Encadeada
void imprime(celula * ini){
    int vitorias=0, derrotas=0;
	celula *p;
    celula *p2;
    celula *p3;
    celula *p4;

    p2 = ini->prox;
    p3 = ini->prox;
    p4 = ini->prox;

    system("cls");

    printf ("\n\n---------------------------------------------------");

    //Percorre a lista
    for (p = ini->prox; p != NULL || p2 != NULL || p3 != NULL || p4 != NULL; p = p->prox){
		printf("\n  %d)\n", p->contador_struct); //Mostra os campos da lista
        printf("    Modo de Jogo: %s\n", p4->modo_jogo_struct);
        printf("    Palavra Sorteada: %s\n", p3->palavra_struct);
        printf("    Quantidade de erros: %d\n", p2->jogadas_struct);
        
        //Teste para verificar se a pessoa ganhou:
        if (p2->jogadas_struct < 6){
            printf("    Resultado: Venceu\n");
            vitorias++;
        }
        else{
            printf("    Resultado: Perdeu\n");
            derrotas++;
        }
        p2 = p2->prox;
        p3 = p3->prox;
        p4 = p4->prox;
        printf ("\n---------------------------------------------------\n");
    }
    printf("\n\n");

    printf("\n\n RESUMO    \n");
    printf("\n  -> TOTAL DE VITORIAS: %d    ",vitorias);
    printf("\n  -> TOTAL DE DERROTAS: %d   \n\n\n",derrotas); 
}
