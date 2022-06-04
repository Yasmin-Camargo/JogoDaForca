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
void sorteador();
char sub_menu_arquivo();
void inserir_palavra();
void sorteador_palavras();
void modo_contra_pessoa(char palavra_obtida[100], char dica_obtida[100]);
void percorrer_palavra_secreta();
void mostra_dica_palavra();
void mostrar_palavra_secreta();

//VARIAVEIS GLOBAIS
char nome[100], dica[100], palavra[100], palavra_secreta[100], letras_digitadas[100];
char letra;
int erros = 0;

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
void sorteador(){
system("cls");

    printf (" \n\t*----------------------------------------------------------------*");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                     CATEGORIA CORES:                           |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|  amarelo queimado                 castanho avermelhado         |");
    printf (" \n\t|  azul celeste                     azul turquesa                |");
    printf (" \n\t|  dourado                          verde fluorescente           |");
    printf (" \n\t|  rosa choque                      lilas                        |");
    printf (" \n\t|  vermelho                         amarelo                      |");
    printf (" \n\t|  azul                             branco                       |");
    printf (" \n\t|  roxo                             verde                        |");
    printf (" \n\t|  laranja                          rosa                         |");
    printf (" \n\t|  marrom                           cinza                        |");
    printf (" \n\t|  preto                            purpura                      |");
    printf (" \n\t|                                                                |");
    printf (" \n\t*-----------------------------------------------------------------*");


    printf (" \n\n\t*----------------------------------------------------------------*");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                     CATEGORIA OBJETOS:                         |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|  prato                           caneca                        |");
    printf (" \n\t|  dentadura                       drone                         |");
    printf (" \n\t|  ededrom                         espelho                       |");
    printf (" \n\t|  esponja                         escada                        |");
    printf (" \n\t|  fritadeira                      furadeira                     |");
    printf (" \n\t|  geladeira                       guitarra                      |");
    printf (" \n\t|  helicoptero                     hidratante                    |");
    printf (" \n\t|  impressora                      isopor                        |");
    printf (" \n\t|  liquidificador                  janela                        |");
    printf (" \n\t|  celular                         notebook                      |");
    printf (" \n\t|  armário                         livro                         |");
    printf (" \n\t|  mesa                            luminaria                     |");  
    printf (" \n\t|  sofa                            caixa                         |");
    printf (" \n\t|  borracha                        lapis                         |");
    printf (" \n\t|  caneta                          estojo                        |");
    printf (" \n\t|  pincel                          caderno                       |");
    printf (" \n\t|  quadro                          televisao                     |"); 
    printf (" \n\t|  garrafa                         copo                          |");
    printf (" \n\t|  garfo                           faca                          |");
    printf (" \n\t|  relogio                         chapeu                        |");
    printf (" \n\t|  brinco                          bolsa                         |");  
    printf (" \n\t|  chave                           tesoura                       |");
    printf (" \n\t|  apontador                       regua                         |");
    printf (" \n\t|  almofada                        cama                          |");
    printf (" \n\t|  escrivaninha                    coberta                       |");
    printf (" \n\t|  cadeira                         fogao                         |");
    printf (" \n\t|  pia                             pote                          |");
    printf (" \n\t|  cristaleira                     vaso                          |");
    printf (" \n\t|  mala                            brinquedo                     |");
    printf (" \n\t|  boneca                          livro                         |");
    printf (" \n\t|  oculos                          bola                          |");
    printf (" \n\t|                                                                |");
    printf (" \n\t*-----------------------------------------------------------------*");


    printf (" \n\n\t*----------------------------------------------------------------*");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                CATEGORIA INSTRUMENTOS MUSICAIS:                |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|  bateria                         castanhola                    |");
    printf (" \n\t|  corneta                         clarim                        |");
    printf (" \n\t|  gaita                           escaleta                      |");
    printf (" \n\t|  flauta                          orgao                         |");
    printf (" \n\t|  sanfona                         saxofone                      |");
    printf (" \n\t|  trombeta                        trombone                      |");
    printf (" \n\t|  tuba                            baixo                         |");
    printf (" \n\t|  cavaquinho                      guitarra                      |");
    printf (" \n\t|  banjo                           berimbau                      |");
    printf (" \n\t|  harpa                           piano                         |");
    printf (" \n\t|  vukulele                        viola                         |");
    printf (" \n\t|  violao                          violino                       |");
    printf (" \n\t|  violoncelo                      teclado                       |");
    printf (" \n\t|                                                                |");
    printf (" \n\t*-----------------------------------------------------------------*");

    printf (" \n\n\t*----------------------------------------------------------------*");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                         CATEGORIA FRUTAS:                      |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|  abacate                         abacaxi                       |");
    printf (" \n\t|  acerola                         amora                         |");
    printf (" \n\t|  acai                            bergamota                     |");
    printf (" \n\t|  banana                          cacau                         |");
    printf (" \n\t|  caqui                           carambola                     |");
    printf (" \n\t|  cereja                          coco                          |");
    printf (" \n\t|  cupuacu                         figo                          |");
    printf (" \n\t|  framboesa                       goiaba                        |");
    printf (" \n\t|  groselha                        jabuticaba                    |");
    printf (" \n\t|  jaca                            kiwi                          |");
    printf (" \n\t|  laranja                         limao                         |");
    printf (" \n\t|  maca                            mamao                         |");
    printf (" \n\t|  manga                           maracuja                      |");
    printf (" \n\t|  melancia                        melao                         |");
    printf (" \n\t|  morango                         pequi                         |");
    printf (" \n\t|  pera                            pessego                       |");
    printf (" \n\t|  pitanga                         pitaya                        |");
    printf (" \n\t|  uva                                                           |");
    printf (" \n\t|                                                                |");
    printf (" \n\t*-----------------------------------------------------------------*");

    printf (" \n\n\t*----------------------------------------------------------------*");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                         CATEGORIA ANIMAIS:                     |");
    printf (" \n\t|                                                                |");
    printf (" \n\t|  abelha                          abutre                        |");
    printf (" \n\t|  aguia                           alce                          |");
    printf (" \n\t|  alpaca                          anaconda                      |");
    printf (" \n\t|  andorinha                       anta                          |");
    printf (" \n\t|  aranha                          arara                         |");
    printf (" \n\t|  asno                            avestruz                      |");
    printf (" \n\t|  babuino                         bagre                         |");
    printf (" \n\t|  baleia                          barracuda                     |");
    printf (" \n\t|  besouro                         bezerro                       |");
    printf (" \n\t|  bode                            barata                        |");
    printf (" \n\t|  besouro                         burro                         |");
    printf (" \n\t|  boi                             borboleta                     |");
    printf (" \n\t|  boto                            cabra                         |");
    printf (" \n\t|  cachorro                        camelo                        |");
    printf (" \n\t|  canario                         carneiro                      |");
    printf (" \n\t|  caranguejo                      cascavel                      |");
    printf (" \n\t|  cavalo                          centopeia                     |");
    printf (" \n\t|  crocodilo                       corvo                         |"); 
    printf (" \n\t|  coiote                          chimpanze                     |");
    printf (" \n\t|  egua                            elefante                      |");
    printf (" \n\t|  enguia                          escorpiao                     |");
    printf (" \n\t|  escaravelho                     esponja                       |");
    printf (" \n\t|  falcao                          foca                          |");
    printf (" \n\t|  flamingo                        furao                         |"); 
    printf (" \n\t|  formiga                         gafanhoto                     |");
    printf (" \n\t|  gaivota                         galinha                       |");
    printf (" \n\t|  galo                            gamba                         |");
    printf (" \n\t|  ganso                           gato                          |");
    printf (" \n\t|  gaviao                          gazela                        |");
    printf (" \n\t|  grilo                           guaxinim                      |");
    printf (" \n\t|  harpia                          jabuti                        |");
    printf (" \n\t|  jacare                          jaguar                        |");
    printf (" \n\t|  joaninha                        jumento                       |");
    printf (" \n\t|  javali                          jiboia                        |");
    printf (" \n\t|  lacraia                         lagarta                       |");
    printf (" \n\t|  lagartixa                       lagarto                       |");
    printf (" \n\t|  leao                            lebre                         |");
    printf (" \n\t|  lemure                          leopardo                      |");
    printf (" \n\t|  lesma                           lobo                          |");
    printf (" \n\t|  lula                            macaco                        |");
    printf (" \n\t|  mamute                          mariposa                      |");
    printf (" \n\t|  marmota                         morcego                       |");
    printf (" \n\t|  mosquito                        naja                          |");
    printf (" \n\t|  onca                            orangotango                   |");
    printf (" \n\t|  orca                            ostra                         |");
    printf (" \n\t|  ovelha                          panda                         |");
    printf (" \n\t|  pantera                         papagaio                      |");
    printf (" \n\t|  pardal                          passaro                       |");
    printf (" \n\t|  pato                            pavao                         |");
    printf (" \n\t|  peixe                           pinguim                       |");
    printf (" \n\t|  piranha                         pulga                         |");
    printf (" \n\t|  porco                           raposa                        |");
    printf (" \n\t|  rato                            rena                          |");
    printf (" \n\t|  ratazana                        salamandra                    |");
    printf (" \n\t|  sapo                            salmao                        |");
    printf (" \n\t|  sucuri                          tamandua                      |");
    printf (" \n\t|  tatu                            tigre                         |");                       
    printf (" \n\t|  texugo                          touro                         |");
    printf (" \n\t|  toupeira                        tubarao                       |");                   
    printf (" \n\t|  urso                            urubu                         |");
    printf (" \n\t|  vaca                            veado                         |");
    printf (" \n\t|  vespa                           zebra                         |");
    printf (" \n\t|                                                                |");
    printf (" \n\t*-----------------------------------------------------------------*");

    printf (" \n\n\t*----------------------------------------------------------------*");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                     CATEGORIA  PROFISSOES:                     |");
    printf (" \n\t|                                                                |");                
    printf (" \n\t|  padeiro                         veterinario                   |");
    printf (" \n\t|  professor                       programador                   |");
    printf (" \n\t|  ator                            engenheiro                    |");
    printf (" \n\t|  dentista                        medico                        |");
    printf (" \n\t|  fretista                        motorista                     |");
    printf (" \n\t|  empresario                      cabelereiro                   |");
    printf (" \n\t|  cantor                          cozinheiro                    |");  
    printf (" \n\t|  cineasta                        artista                       |");
    printf (" \n\t|  nutricionista                   garcom                        |");
    printf (" \n\t|  desenhista                      escritor                      |");
    printf (" \n\t|  publicitario                    historiador                   |");
    printf (" \n\t|                                                                |");
    printf (" \n\t*-----------------------------------------------------------------*");

    printf (" \n\n\t*----------------------------------------------------------------*");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                       CATEGORIA  PAISES:                       |");
    printf (" \n\t|                                                                |");  
    printf (" \n\t|  brasil                          argentina                     |");
    printf (" \n\t|  mexico                          canada                        |");
    printf (" \n\t|  colombia                        frança                        |");
    printf (" \n\t|  holanda                         espanha                       |");
    printf (" \n\t|  portugal                        uruguai                       |");
    printf (" \n\t|  paraguai                        alemanha                      |");
    printf (" \n\t|  japao                           chile                         |");
    printf (" \n\t|  turquia                         russia                        |");
    printf (" \n\t|  bolivia                         dinamarca                     |");
    printf (" \n\t|  italia                          irlanda                       |");
    printf (" \n\t|  australia                       india                         |");
    printf (" \n\t|                                                                |");
    printf (" \n\t*-----------------------------------------------------------------*");

    printf (" \n\n\t*----------------------------------------------------------------*");
    printf (" \n\t|                                                                |");
    printf (" \n\t|                      CATEGORIA  LUGARES:                       |");
    printf (" \n\t|                                                                |");  
    printf (" \n\t|  hotel                           igreja                        |");
    printf (" \n\t|  banco                           loja                          |");
    printf (" \n\t|  prefeitura                      restaurante                   |");
    printf (" \n\t|  cinema                          boate                         |");
    printf (" \n\t|  balada                          mercado                       |");
    printf (" \n\t|  lanchonete                      bar                           |");
    printf (" \n\t|  hospital                        rodoviaria                    |");
    printf (" \n\t|  quiosque                        parque                        |");
    printf (" \n\t|  praça                           praia                         |");
    printf (" \n\t|  padaria                                                       |");
    printf (" \n\t|                                                                |");
    printf (" \n\t*-----------------------------------------------------------------*\n");
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

    printf("Palavra Sorteada ");
    puts(nome);
    printf("Dica:  ");
    puts(dica);
    printf("\n");
    system("pause");
    return;
}


//Função para inserir palavras no arquivo
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
    
    //Abrindo arquivo para escrita
	FILE *arquivo_palavras;
	arquivo_palavras=fopen("./arquivos/arq_palavras.txt","a+");
	if(arquivo_palavras == NULL) {
		printf("\nERRO ao abrir o arquivo de palavras\n");
	}
    
    fflush(stdin);
    system("cls");
    printf("\n  Digite a palavra para ser adicionada no arquivo: ");
    scanf("%[^\n]s", palavra_adicionada);
   
    fflush(stdin);
    printf("\n  Digite a dica da palavra: ");
    scanf("%[^\n]s", dica_adicionada);
    fflush(stdin);
 
    
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

    if(gravar == 1){ //Adiciona palavra e dica no arquivo
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


//-----------------------------------------------------------------------------------------
//MODO CONTRA PESSOA
void modo_contra_pessoa(char palavra_obtida[100], char dica_obtida[100]){
    strcpy(palavra_secreta, "\0");
    strcpy(palavra, "\0");
    strcpy(letras_digitadas,"\0");
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