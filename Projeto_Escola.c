#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//structs

typedef struct { 
        int dia;
        int mes;
        int ano;
    }Data;

typedef struct {
    int p1,p2,p3,dv;

}Cpf;

typedef struct{
    int matricula;
    Data data;
    char * nome;
    char sexo;
    Cpf cpf;


}Professores;

typedef struct{
    int matricula;
    Data data;
    char *nome;
    char sexo;
    Cpf cpf;


}Alunos;

typedef struct{
  char *nome;
  int codigo;
  int semestre;
  Professores professor;

}Disciplinas

//Funções
int opcaoValida(int opcao,int u){
if(opcao==1 || opcao==2 || opcao==3 || opcao==4){
    printf("\n\t--------Escolha a opção--------\t\n\n");
    if(u==1) printf("\t-----Bem vindo ao Sistema Escola-----\n\n");
 printf("\t°°°°°°°°**Cadastrar**°°°°°°°°\n\t\tDigite [1]\n\n");
 printf("\t°°°°°°°°Alterar°°°°°°°°\n\t\tDigite [2]\n\n");
 printf("\t°°°°°°°°Excluir°°°°°°°°\n\t\tDigite [3]\n\n");
 printf("\t°°°°°°°°Listar°°°°°°°°\n\t\tDigite [4]\n\n");
 printf("\t°°°°°°°°Sair°°°°°°°°\n\t\tDigite [5]\n\n");
    if(u==2) printf("\t-----Bem vindo ao Sistema Escola-----\n\n");
 printf("\t°°°°°°°°Cadastrar°°°°°°°°\n\t\tDigite [1]\n\n");
 printf("\t°°°°°°°°**Alterar**°°°°°°°°\n\t\tDigite [2]\n\n");
 printf("\t°°°°°°°°Excluir°°°°°°°°\n\t\tDigite [3]\n\n");
 printf("\t°°°°°°°°Listar°°°°°°°°\n\t\tDigite [4]\n\n");
 printf("\t°°°°°°°°Sair°°°°°°°°\n\t\tDigite [5]\n\n");
    if(u==3)printf("\t-----Bem vindo ao Sistema Escola-----\n\n");
 printf("\t°°°°°°°°Cadastrar°°°°°°°°\n\t\tDigite [1]\n\n");
 printf("\t°°°°°°°°Alterar°°°°°°°°\n\t\tDigite [2]\n\n");
 printf("\t°°°°°°°°**Excluir**°°°°°°°°\n\t\tDigite [3]\n\n");
 printf("\t°°°°°°°°Listar°°°°°°°°\n\t\tDigite [4]\n\n");
 printf("\t°°°°°°°°Sair°°°°°°°°\n\t\tDigite [5]\n\n");
    if(u==4) printf("\t-----Bem vindo ao Sistema Escola-----\n\n");
 printf("\t°°°°°°°°Cadastrar°°°°°°°°\n\t\tDigite [1]\n\n");
 printf("\t°°°°°°°°Alterar°°°°°°°°\n\t\tDigite [2]\n\n");
 printf("\t°°°°°°°°Excluir°°°°°°°°\n\t\tDigite [3]\n\n");
 printf("\t°°°°°°°°**Listar**°°°°°°°°\n\t\tDigite [4]\n\n");
 printf("\t°°°°°°°°Sair°°°°°°°°\n\t\tDigite [5]\n\n");
    scanf("%d",&opcao);
 }
else{    
while(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5){
    printf("\n\t------A opção escolhida não consta nas opções, tente novamente ------\n\n");
printf("\t°°°°°°°°Cadastrar°°°°°°°°\n\t\tDigite [1]\n\n");
 printf("\t°°°°°°°°Alterar°°°°°°°°\n\t\tDigite [2]\n\n");
 printf("\t°°°°°°°°Excluir°°°°°°°°\n\t\tDigite [3]\n\n");
 printf("\t°°°°°°°°Listar°°°°°°°°\n\t\tDigite [4]\n\n");
 printf("\t°°°°°°°°Sair°°°°°°°°\n\t\tDigite [5]\n\n");
    scanf("%d",&opcao);
 }
}
if(opcao==5){
    printf("Obrigado por acessar! :)");
    return 0;
}
 return opcao;
}
 int menuParte2(int opcao){
    int ultimoCaso=1;
    switch(opcao){
        case 1:
            printf("\n\t\t  --------CADASTRAR--------\n\n\t\t°°°°°°°°°Professores°°°°°°°°°\n\t\t\t  Digite [1]\n\n\t\t °°°°°°°°°°°Alunos°°°°°°°°°°°\n\t\t\t  Digite [2]\n\n\t\t°°°°°°°°°Disciplinas°°°°°°°°°\n\t\t\t Digite [3]\n\n\t\t°°°°°°°°°Voltar°°°°°°°°°\n\t\t\t Digite [4]\n\n\t\t°°°°°°°°°Sair°°°°°°°°°\n\t\t\t Digite [5]\n");
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
int validarData(int d,int m, int a){
    int v =0;
    time_t tempoEmSegundos;
    time(&tempoEmSegundos);
    struct tm*data_atual=localtime(&tempoEmSegundos);
    int ano_atual= data_atual->tm_year+1900;
    if((m>=1 && m<=12)&& (a>=1 && a<=ano_atual)){
        if(m==2 || m==4 || m==6 || m==9 || m==11){
        if(m==2){
             int bissexto=0;
    if(a%100==0){
        if(a%400==0 && a%4==0){
            bissexto=1;
        }
    }
    else{
        if(a%4==0){
            bissexto=1;
        }
    }
                if(bissexto==1){
                if(d>=1 && d<=29){
                    v=1;
                }
            }
            else{
                if(d>=1 && d<=28){
                    v=1;
                }
            }
        }
        else{ 
            if(d>=1 && d<=30){
                v=1;
            }
        }
    

        }
        else{
            if(d>=1 && d<=31){
                v=1;
            }
        }
    }
        return v;
    
}
int validarSexo(char sexo){

    int v=0;
    if(sexo=='F' || sexo=='M' || sexo=='m' || sexo=='f'){
        v=1;
    }

    return v;
}
int validarCpf(int p1,int p2, int p3, int dv){

    int v=0;
    int soma=0;
    int Dv1=dv/10;
    int Dv2=dv%10;
    soma += (p1/100)*10;
    soma += ((p1%100)/10)*9;
    soma += ((p1%100)%10)*8;
    soma += (p2/100)*7;
    soma += ((p2%100)/10)*6;
    soma += ((p2%100)%10)*5;
    soma += (p3/100)*4;
    soma += ((p3%100)/10)*3;
    soma += ((p3%100)%10)*2;

    int restoDaSoma=soma%11;

    if(restoDaSoma<2){
        if(Dv1==0){
            v+=1;
        }
    }
    else{
        if(Dv1==(11-restoDaSoma)){
            v+=1;
        }
    }
    soma=0;
    soma += (p1/100)*11;
    soma += ((p1%100)/10)*10;
    soma += ((p1%100)%10)*9;
    soma += (p2/100)*8;
    soma += ((p2%100)/10)*7;
    soma += ((p2%100)%10)*6;
    soma += (p3/100)*5;
    soma += ((p3%100)/10)*4;
    soma += ((p3%100)%10)*3;
    soma += Dv1*2;

    restoDaSoma= soma%11;


    if(restoDaSoma<2){
        if(Dv2==0){
            v+=1;
        }
    }
    else{
        if(Dv2==(11-restoDaSoma)){
            v+=1;
        }
    }


    return v;
}

void Professor(){
        int qtdProfessores;
            printf("\nDigite a quantidade de professores para cadastro: ");
            scanf("%d",&qtdProfessores); //lista
            Professores listaProfessores[qtdProfessores];
            char armazenamento[1000];
            for(int l=0;l<qtdProfessores;l++){
            Professores *ptr_professores = &listaProfessores[l];

            //matrícula do professor
            printf("\nDigite a matrícula do professor(a) nº%d: ",l+1);
            scanf("%d",&ptr_professores->matricula);
            getchar();

            //Nome do professor
            printf("\nDigite o nome completo do professor(a) nº%d: ",l+1);
            fgets(armazenamento,1000,stdin);
            armazenamento[strcspn(armazenamento,"\n")]=0;
            int tamanho = strlen(armazenamento)+1;
            ptr_professores->nome=(char*)malloc(tamanho*sizeof(char)); 
            strcpy(ptr_professores->nome,armazenamento);

            //Sexo do professor
            printf("\nDigite se o professor(a) nº%d é do sexo Masculino [M] ou Feminino [F], digite 'M' ou 'F': ",l+1);
            while((validarSexo(ptr_professores->sexo))==0){
            scanf("%c",&ptr_professores->sexo);
            if((validarSexo(ptr_professores->sexo))==0){
                printf("\nSexo informado errado, digite 'F/f' para Feminino ou 'M/m' para Masculino: ");
            }
            };

            //Data de Nascimento do professor 
            printf("\nDigite a data de nascimento, no formato (xx/xx/xxxx) com as '/', do professor(a) nº%d: ",l+1);
                while((validarData(ptr_professores->data.dia,ptr_professores->data.mes,ptr_professores->data.ano))==0){
            scanf("%d/%d/%d",&ptr_professores->data.dia,&ptr_professores->data.mes,&ptr_professores->data.ano);
            if((validarData(ptr_professores->data.dia,ptr_professores->data.mes,ptr_professores->data.ano))==0){
                printf("\nErro na data, digite novamente no formato (xx/xx/xxxx) com as '/': \n");
            }
            };

            //Cadastro do Cpf do Professor
            printf("\nDigite o cpf, no formato (xxx.xxx.xxx-xx) e com 11 digitos, do professor(a) nº%d: ",l+1);
            while((validarCpf(ptr_professores->cpf.p1,ptr_professores->cpf.p2,ptr_professores->cpf.p3,ptr_professores->cpf.dv))!=2){
            scanf("%d.%d.%d-%d",&ptr_professores->cpf.p1,&ptr_professores->cpf.p2,&ptr_professores->cpf.p3,&ptr_professores->cpf.dv);
            if((validarCpf(ptr_professores->cpf.p1,ptr_professores->cpf.p2,ptr_professores->cpf.p3,ptr_professores->cpf.dv))!=2){
                printf("\nCpf Inválido, digite novamente no formato (xxx.xxx.xxx-xx) e com 11 digitos: ");
            }
            };
            
            printf("\n\t\t Professor(a) n°%d cadastrado com sucesso\t\t\n",l+1);
            }
            return;
}
void Aluno(){
     int qtdAlunos;
            printf("\nDigite a quantidade de alunos para cadastro: ");
            scanf("%d",&qtdAlunos); 
            //lista
            Alunos listaAlunos[qtdAlunos];
            char armazenamento[1000];
            for(int l=0;l<qtdAlunos;l++){
            Alunos *ptr_alunos = &listaAlunos[l];

            //matrícula do aluno
            printf("\nDigite a matrícula do aluno(a) nº%d: ",l+1);
            scanf("%d",&ptr_alunos->matricula);
            getchar();

            //Nome do aluno
            printf("\nDigite o nome completo do aluno(a) nº%d: ",l+1);
            fgets(armazenamento,1000,stdin);
            armazenamento[strcspn(armazenamento,"\n")]=0;
            int tamanho = strlen(armazenamento)+1;
            ptr_alunos->nome=(char*)malloc(tamanho*sizeof(char)); 
            strcpy(ptr_alunos->nome,armazenamento);

            //Sexo do aluno
            printf("\nDigite se o aluno(a) nº%d é do sexo Masculino [M] ou Feminino [F], digite 'M' ou 'F': ",l+1);
            while((validarSexo(ptr_alunos->sexo))==0){
            scanf("%c",&ptr_alunos->sexo);
            if((validarSexo(ptr_alunos->sexo))==0){
                printf("\nSexo informado errado, digite 'F/f' para Feminino ou 'M/m' para Masculino: ");
            }
            };

            //Data de Nascimento do aluno
            printf("\nDigite a data de nascimento, no formato (xx/xx/xxxx) com as '/', do aluno(a) nº%d: ",l+1);
                while((validarData(ptr_alunos->data.dia,ptr_alunos->data.mes,ptr_alunos->data.ano))==0){
            scanf("%d/%d/%d",&ptr_alunos->data.dia,&ptr_alunos->data.mes,&ptr_alunos->data.ano);
            if((validarData(ptr_alunos->data.dia,ptr_alunos->data.mes,ptr_alunos->data.ano))==0){
                printf("\nErro na data, digite novamente no formato (xx/xx/xxxx) com as '/': \n");
            }
            };

            //Cadastro do Cpf do aluno
            printf("\nDigite o cpf, no formato (xxx.xxx.xxx-xx) e com 11 digitos, do aluno(a) nº%d: ",l+1);
            while((validarCpf(ptr_alunos->cpf.p1,ptr_alunos->cpf.p2,ptr_alunos->cpf.p3,ptr_alunos->cpf.dv))!=2){
            scanf("%d.%d.%d-%d",&ptr_alunos->cpf.p1,&ptr_alunos->cpf.p2,&ptr_alunos->cpf.p3,&ptr_alunos->cpf.dv);
            if((validarCpf(ptr_alunos->cpf.p1,ptr_alunos->cpf.p2,ptr_alunos->cpf.p3,ptr_alunos->cpf.dv))!=2){
                printf("\nCpf Inválido, digite novamente no formato (xxx.xxx.xxx-xx) e com 11 digitos: ");
            }
            };
            
            printf("\n\t\t Aluno(a) n°%d cadastrado com sucesso\t\t\n",l+1);
            }
            return;
}
void Disciplina(){
        int qtdDisciplinas;
            printf("\nDigite a quantidade de disciplinas para cadastro: ");
            scanf("%d",&qtdDisciplinas); 
            //lista
            Disciplinas listaDisciplinas[qtdDisciplinas];
            char armazenamento[1000];
            for(int l=0;l<qtdDisciplinas;l++){
            Disciplinas *ptr_disciplinas = &listaDisciplinas[l];

            //código do aluno
            printf("\nDigite o código do aluno(a) nº%d: ",l+1);
            scanf("%d",&ptr_disciplinas->matricula);
            getchar();

            //Nome do aluno
            printf("\nDigite o nome da disciplina nº%d: ",l+1);
            fgets(armazenamento,1000,stdin);
            armazenamento[strcspn(armazenamento,"\n")]=0;
            int tamanho = strlen(armazenamento)+1;
            ptr_disciplinas->nome=(char*)malloc(tamanho*sizeof(char)); 
            strcpy(ptr_disciplinas->nome,armazenamento);
            }
}

int main(){
 printf("\t-----Bem vindo ao Sistema Escola-----\n\n");
 printf("\t°°°°°°°°Cadastrar°°°°°°°°\n\t\tDigite [1]\n\n");
 printf("\t°°°°°°°°Alterar°°°°°°°°\n\t\tDigite [2]\n\n");
 printf("\t°°°°°°°°Excluir°°°°°°°°\n\t\tDigite [3]\n\n");
 printf("\t°°°°°°°°Listar°°°°°°°°\n\t\tDigite [4]\n\n");
 printf("\t°°°°°°°°Sair°°°°°°°°\n\t\tDigite [5]\n\n");
 int opcao;
 int ultimoCaso=0;
 scanf("%d",&opcao);
if(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5){
    opcao = opcaoValida(opcao,ultimoCaso);
}
    opcao=menuParte2(opcao);
  
    //Cadastro
    switch(opcao){
        case 1:
       Professor();
       break;
        case 2:
        Aluno();
        break;
        case 3:
        Disciplina();
        break;
    }


    printf("\t\tObrigado pelo cadastro !\t\t");
    return 0;
}