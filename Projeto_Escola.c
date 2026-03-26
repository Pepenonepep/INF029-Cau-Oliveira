#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int matricula;
    char * data;
    char * nome;
    char * sexo;
    int cpf;


}Professores;

typedef struct{
    int matricula;
    char * data;
    char * nome;
    char * sexo;
    int cpf;


}Alunos;
int opcaoValida(int opcao,int u){
if(opcao==1 || opcao==2 || opcao==3 || opcao==4){
    printf("\nEscolha a opção:\n\n");
    if(u==1) printf("Digite [1] para cadastrar(Você estava nessa opção!)\nDigite [2] para alterar\nDigite [3] para excluir\nDigite [4] para listar\nOU\nDigite [5] para sair\n");
    if(u==2) printf("Digite [1] para cadastrar\nDigite [2] para alterar(Você estava nessa opção!)\nDigite [3] para excluir\nDigite [4] para listar\nOU\nDigite [5] para sair\n");
    if(u==3) printf("Digite [1] para cadastrar\nDigite [2] para alterar\nDigite [3] para excluir(Você estava nessa opção!)\nDigite [4] para listar\nOU\nDigite [5] para sair\n");
    if(u==4) printf("Digite [1] para cadastrar\nDigite [2] para alterar\nDigite [3] para excluir\nDigite [4] para listar(Você estava nessa opção!)\nOU\nDigite [5] para sair\n");
    scanf("%d",&opcao);
    while(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5){
    printf("\nA opção escolhida não consta nas opções, tente novamente !\n\n");
    if(u==1) printf("Digite [1] para cadastrar(Você estava nessa opção!)\nDigite [2] para alterar\nDigite [3] para excluir\nDigite [4] para listar\nOU\nDigite [5] para sair\n");
    if(u==2) printf("Digite [1] para cadastrar\nDigite [2] para alterar(Você estava nessa opção!)\nDigite [3] para excluir\nDigite [4] para listar\nOU\nDigite [5] para sair\n");
    if(u==3) printf("Digite [1] para cadastrar\nDigite [2] para alterar\nDigite [3] para excluir(Você estava nessa opção!)\nDigite [4] para listar\nOU\nDigite [5] para sair\n");
    if(u==4) printf("Digite [1] para cadastrar\nDigite [2] para alterar\nDigite [3] para excluir\nDigite [4] para listar(Você estava nessa opção!)\nOU\nDigite [5] para sair\n");
    scanf("%d",&opcao);
 }
}
else{    
while(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5){
    printf("\nA opção escolhida não consta nas opções, tente novamente !\n\n");
    printf("Digite [1] para cadastrar\n");
    printf("Digite [2] para alterar\n");
    printf("Digite [3] para excluir\n");
    printf("Digite [4] para listar\n");
    printf("OU\n");
    printf("Digite [5] para sair\n");
    scanf("%d",&opcao);
 }
}
if(opcao==5){
    printf("Obrigado por acessar! :)");
    return 0;
}
 return opcao;
}
 int Primeiroponto(int opcao){
    int ultimoCaso=1;
    switch(opcao){
        case 1:
            printf("\nVocê deseja cadastrar:\n\n--Professores--\t\tdigite [1]\n--Alunos--\t\tdigite [2]\n--Disciplinas--\t\tdigite [3]\n--Voltar--\t\tdigite [4]\n--OU--\n--Sair--\t\tdigite [5]\n");
            scanf("%d",&opcao);if(opcao!=5){ultimoCaso=opcao;}
            while(opcao==4){
                opcao=opcaoValida(opcao,ultimoCaso);
            }
            return opcao; 
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Obrigado por acessar! :)");
            break;
    } 
    return opcao;
}


int main(){
 printf("-----Bem vindo ao Sistema Escola-----\n\n");
 printf("Digite [1] para cadastrar\n");
 printf("Digite [2] para alterar\n");
 printf("Digite [3] para excluir\n");
 printf("Digite [4] para listar\n");
 printf("OU\n");
 printf("Digite [5] para sair\n");
 int opcao;
 int ultimoCaso=0;
 scanf("%d",&opcao);
if(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5){
    opcao = opcaoValida(opcao,ultimoCaso);
}
    opcao=Primeiroponto(opcao);
    
    Professores * prof;
    char rascunho_tam[1024];
    
    switch(opcao){
        case 1:
            prof = (Professores*) malloc(sizeof(Professores));
            printf("Digite o nome do professor: \t");
            scanf("%1023s", rascunho_tam);
            int tamanho_real = strlen(rascunho_tam) + 1;
            prof->nome = (char*)malloc(tamanho_real * sizeof(char));
            strcpy(prof->nome, rascunho_tam);
            
    }
    
    return 0;
}