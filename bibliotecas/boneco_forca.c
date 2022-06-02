//Biblioteca própia com as versões do boneco forca

#include "boneco_forca.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>


void incializacao_boneco();
void boneco1();
void boneco2();
void boneco3();
void boneco4();
void boneco5();
void boneco6();
void boneco7();

char *boneco[22], *boneco_limpo[22];

void incializacao_boneco(){
 boneco[1]= " ******************                \n";
 boneco[2]= " ******************                    JOGO DA FORCA \n";
 boneco[3]= " ***             **                \n";          
 boneco[4]= " ***             **                \n";
 boneco[5]= " ***           _////_              \n";
 boneco[6]= " ***         /        \\           \n";
 boneco[7]= " ***        |   O  O   |           \n";
 boneco[8]= " ***        |  \\____/  |          \n";
 boneco[9]= " ***         \\___  ___/           Jogada 1 de 6\n";
 boneco[10]= " ***       _____/ \\ _____        \n";
 boneco[11]= " ***      (____      ____)         \n";
 boneco[12]= " ***           |    |              \n";
 boneco[13]= " ***           |____|              \n";
 boneco[14]= " ***          /  /\\  \\           \n";
 boneco[15]= " ***       __/  /  \\  \\__        \n";
 boneco[16]= " ***    __(____/____\\____) __     \n";
 boneco[17]= " ***   |_____________________|     \n";
 boneco[18]= " ***   |_____________________|     \n";
 boneco[19]= " *** __|_____________________|__   \n";
 boneco[20]= " ****                              \n";
 return; 
}

void boneco1(){
    int cont=1;
    while(cont<=20){
        printf("%s", boneco[cont]);
        cont++;
    }
    return; 
}
void boneco2(){
    int cont=1;
    boneco[9]= " ***         \\___  ___/           Jogada 2 de 6\n";
    boneco[16]= " ***                                \n";
    boneco[17]= " ***                               \n";
    boneco[18]= " ***                               \n";
    boneco[19]= " ***                               \n";
    boneco[20]= " ****                              \n";
    while(cont<=20){
        printf("%s", boneco[cont]);
        cont++;
    }
    return; 
}


void boneco3(){
    int cont=1;
    boneco[9]= " ***         \\___  ___/           Jogada 3 de 6\n";
    boneco[14]= " ***                                \n";
    boneco[15]= " ***                                \n";
    printf("%s", boneco[cont]);
    cont++;
    while(cont<=20){
        printf("%s", boneco[cont]);
        cont++;
    }
    return; 
}

void boneco4(){
    int cont=1;
    boneco[9]= " ***         \\___  ___/           Jogada 4 de 6\n";
    boneco[12]= " ***                               \n";
    boneco[13]= " ***                               \n";
    printf("%s", boneco[cont]);
    cont++;
    while(cont<=20){
        printf("%s", boneco[cont]);
        cont++;
    }
    return; 
}
void boneco5(){
    int cont=1;
    boneco[9]= " ***         \\___  ___/           Jogada 5 de 6\n";
    boneco[10]= " ***                              \n";
    boneco[11]= " ***                               \n";
    printf("%s", boneco[cont]);
    cont++;
    while(cont<=20){
        printf("%s", boneco[cont]);
        cont++;
    }
    return; 
}
void boneco6(){
    int cont=1;
    boneco[5]= " ***                              \n";
    boneco[6]= " ***                              \n";
    boneco[7]= " ***                              \n";
    boneco[8]= " ***                              \n";
    boneco[9]= " ***                               Jogada 5 de 6\n";
    printf("%s", boneco[cont]);
    cont++;
    while(cont<=20){
        printf("%s", boneco[cont]);
        cont++;
    }
    return; 
}

void boneco7(){
  printf("******************                \n");             
  printf("******************                \n");
  printf("***             **                \n");        
  printf("***           ******              \n");
  printf("***           _////_              \n");
  printf("***         /        \\                \n");
  printf("***        |   X  X   |               \n");
  printf("***        |   ____   |               \n");
  printf("***         \\___  ___/                \n");
  printf("***         ___/  \\___                \n");
  printf("***        / _      _ \\               \n");
  printf("***       / / |    | \\ \\              \n");
  printf("***           |____|              \n");
  printf("***          /  /\\  \\                 \n");
  printf("***       __/  /  \\  \\__              \n");
  printf("***      (____/     \\___)                  \n");  
  printf("***               \n");
  printf("***                   \n");
  printf("***                   \n");
  printf("*****");
  return; 
}

