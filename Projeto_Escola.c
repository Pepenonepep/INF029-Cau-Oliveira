#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_PROFESSORES 200
#define MAX_ALUNOS 200
#define MAX_DISCIPLINAS 200

// structs

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int p1, p2, p3, dv;

} Cpf;

typedef struct
{
    int matricula;
    Data data;
    char *nome;
    char sexo;
    Cpf cpf;

} Professores;

typedef struct
{
    int matricula;
    Data data;
    char *nome;
    char sexo;
    Cpf cpf;

} Alunos;

typedef struct
{
    char *nome;
    int codigo;
    int semestre;
    Professores professor;
    Alunos alunosMatriculados[MAX_ALUNOS]; 
    int qtdAlunosNestaDisciplina;

} Disciplinas;

Alunos listaAlunos[MAX_ALUNOS];
int qtdAlunosCadastrados = 0;
Professores listaProfessores[MAX_PROFESSORES];
int qtdProfessoresCadastrados = 0;
Disciplinas listaDisciplinas[MAX_DISCIPLINAS];
int qtdDisciplinasCadastradas = 0;

// Funções
int opcaoValida(int opcao, int u)
{
    if (opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4)
    {
        (void)u;
        printf("\n\t--------Escolha a opção--------\t\n\n");
        printf("\t-----Bem vindo ao Sistema Escola-----\n\n");
        printf("\t°°°°°°°°Cadastrar°°°°°°°°\n\t\tDigite [1]\n\n");
        printf("\t°°°°°°°°Alterar°°°°°°°°\n\t\tDigite [2]\n\n");
        printf("\t°°°°°°°°Excluir°°°°°°°°\n\t\tDigite [3]\n\n");
        printf("\t°°°°°°°°Listar°°°°°°°°\n\t\tDigite [4]\n\n");
        printf("\t°°°°°°°°Sair°°°°°°°°\n\t\tDigite [5]\n\n");
        scanf("%d", &opcao);
    }
    else
    {
        while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5)
        {
            printf("\n\t------A opção escolhida não consta nas opções, tente novamente ------\n\n");
            printf("\t°°°°°°°°Cadastrar°°°°°°°°\n\t\tDigite [1]\n\n");
            printf("\t°°°°°°°°Alterar°°°°°°°°\n\t\tDigite [2]\n\n");
            printf("\t°°°°°°°°Excluir°°°°°°°°\n\t\tDigite [3]\n\n");
            printf("\t°°°°°°°°Listar°°°°°°°°\n\t\tDigite [4]\n\n");
            printf("\t°°°°°°°°Sair°°°°°°°°\n\t\tDigite [5]\n\n");
            scanf("%d", &opcao);
        }
    }
    if (opcao == 5)
    {
        printf("Obrigado por acessar! :)");
        return 0;
    }
    return opcao;
}
int menuParte2(int opcao)
{
    switch (opcao)
    {
    case 1:
        printf("\n\t\t  --------CADASTRAR--------\n\n\t\t°°°°°°°°°Professores°°°°°°°°°\n\t\t\t  Digite [1]\n\n\t\t °°°°°°°°°°°Alunos°°°°°°°°°°°\n\t\t\t  Digite [2]\n\n\t\t°°°°°°°°°Disciplinas°°°°°°°°°\n\t\t\t Digite [3]\n\n\t\t°°°°°°°°°Voltar°°°°°°°°°\n\t\t\t Digite [4]\n\n\t\t°°°°°°°°°Sair°°°°°°°°°\n\t\t\t Digite [5]\n");
        scanf("%d", &opcao);
        if (opcao == 4)
        {
            return 4;
        }
        if (opcao == 5)
        {
            return 5;
        }
        return opcao;
    case 2:
       printf("\n\t\t  --------ALTERAR--------\n\n\t\t°°°°°°°°°Professores°°°°°°°°°\n\t\t\t  Digite [1]\n\n\t\t °°°°°°°°°°°Alunos°°°°°°°°°°°\n\t\t\t  Digite [2]\n\n\t\t°°°°°°°°°Disciplinas°°°°°°°°°\n\t\t\t Digite [3]\n\n\t\t°°°°°°°°°Voltar°°°°°°°°°\n\t\t\t Digite [4]\n\n\t\t°°°°°°°°°Sair°°°°°°°°°\n\t\t\t Digite [5]\n");
        scanf("%d", &opcao);
        if (opcao == 4)
        {
            return 4;
        }
        if (opcao == 5)
        {
            return 5;
        }
        return opcao;
    case 3:
       printf("\n\t\t  --------EXCLUIR--------\n\n\t\t°°°°°°°°°Professores°°°°°°°°°\n\t\t\t  Digite [1]\n\n\t\t °°°°°°°°°°°Alunos°°°°°°°°°°°\n\t\t\t  Digite [2]\n\n\t\t°°°°°°°°°Disciplinas°°°°°°°°°\n\t\t\t Digite [3]\n\n\t\t°°°°°°°°°Voltar°°°°°°°°°\n\t\t\t Digite [4]\n\n\t\t°°°°°°°°°Sair°°°°°°°°°\n\t\t\t Digite [5]\n");
        scanf("%d", &opcao);
        if (opcao == 4)
        {
            return 4;
        }
        if (opcao == 5)
        {
            return 5;
        }
        return opcao;
    case 4:
    printf("\n\t\t  --------LISTAR--------\n\n\t\t°°°°°°°°°Listar Alunos°°°°°°°°°\n\t\t\t  Digite [1]\n\n\t\t °°°°°°°°°°°Listar Professores°°°°°°°°°°°\n\t\t\t  Digite [2]\n\n\t\t°°°°°°°°°Listar uma disciplina°°°°°°°°°\n\t\t\t Digite [3]\n\n\t\t°°°°°°°°°Listar Alunos por sexo°°°°°°°°°\n\t\t\t Digite [4]\n\n\t\t°°°°°°°°°Listar Alunos ordenados por Nome°°°°°°°°°\n\t\t\t Digite [5]\n\n\t\t °°°°°°°°°°°Listar Alunos ordenados por data de nascimento°°°°°°°°°°°\n\t\t\t  Digite [6]\n\n\t\t°°°°°°°°°Listar Professores por sexo (Masculino/Feminino)°°°°°°°°°\n\t\t\t Digite [7]\n\n\t\t°°°°°°°°°Listar Professores ordenados por Nome°°°°°°°°°\n\t\t\t Digite [8]\n\n\t\t°°°°°°°°°Listar Professores ordenados por data de nascimento°°°°°°°°°\n\t\t\t Digite [9]\n\n\t\t °°°°°°°°°°°Aniversariantes do mês°°°°°°°°°°°\n\t\t\t Digite [10]\n\n\t\t°°°°°°°°°Lista de pessoas (professor/aluno) a partir de uma string de busca°°°°°°°°°\n\t\t\t Digite [11]\n\n\t\t°°°°°°°°°Lista de alunos matriculados em menos de 3 disciplinas°°°°°°°°°\n\t\t\t Digite [12]\n\t\t\t°°°°°°°°°Lista de disciplinas sem alunos matriculados°°°°°°°°°\n\t\t\t Digite [13]\n\n\t\t°°°°°°°°°Voltar°°°°°°°°°\n\t\t\t Digite [14]\n\n\t\t°°°°°°°°°Sair°°°°°°°°°\n\t\t\t Digite [15]\n");
        scanf("%d", &opcao);
        return opcao;
    case 5:
        printf("Obrigado por acessar! :)");
        break;
    }
    return opcao;
}

int validarData(int d, int m, int a){
     int v = 0;
    time_t tempoEmSegundos;
    time(&tempoEmSegundos);
    struct tm *data_atual = localtime(&tempoEmSegundos);
    int ano_atual = data_atual->tm_year + 1900;
    if ((m >= 1 && m <= 12) && (a >= 1 && a <= ano_atual))
    {
        if (m == 2 || m == 4 || m == 6 || m == 9 || m == 11)
        {
            if (m == 2)
            {
                int bissexto = 0;
                if (a % 100 == 0)
                {
                    if (a % 400 == 0 && a % 4 == 0)
                    {
                        bissexto = 1;
                    }
                }
                else
                {
                    if (a % 4 == 0)
                    {
                        bissexto = 1;
                    }
                }
                if (bissexto == 1)
                {
                    if (d >= 1 && d <= 29)
                    {
                        v = 1;
                    }
                }
                else
                {
                    if (d >= 1 && d <= 28)
                    {
                        v = 1;
                    }
                }
            }
            else
            {
                if (d >= 1 && d <= 30)
                {
                    v = 1;
                }
            }
        }
        else
        {
            if (d >= 1 && d <= 31)
            {
                v = 1;
            }
        }
    }
    return v;
}
  

int validarSexo(char sexo)
{

    int v = 0;
    if (sexo == 'F' || sexo == 'M' || sexo == 'm' || sexo == 'f')
    {
        v = 1;
    }

    return v;
}
int validarCpf(int p1, int p2, int p3, int dv)
{

    int v = 0;
    int soma = 0;
    int Dv1 = dv / 10;
    int Dv2 = dv % 10;
    soma += (p1 / 100) * 10;
    soma += ((p1 % 100) / 10) * 9;
    soma += ((p1 % 100) % 10) * 8;
    soma += (p2 / 100) * 7;
    soma += ((p2 % 100) / 10) * 6;
    soma += ((p2 % 100) % 10) * 5;
    soma += (p3 / 100) * 4;
    soma += ((p3 % 100) / 10) * 3;
    soma += ((p3 % 100) % 10) * 2;

    int restoDaSoma = soma % 11;

    if (restoDaSoma < 2)
    {
        if (Dv1 == 0)
        {
            v += 1;
        }
    }
    else
    {
        if (Dv1 == (11 - restoDaSoma))
        {
            v += 1;
        }
    }
    soma = 0;
    soma += (p1 / 100) * 11;
    soma += ((p1 % 100) / 10) * 10;
    soma += ((p1 % 100) % 10) * 9;
    soma += (p2 / 100) * 8;
    soma += ((p2 % 100) / 10) * 7;
    soma += ((p2 % 100) % 10) * 6;
    soma += (p3 / 100) * 5;
    soma += ((p3 % 100) / 10) * 4;
    soma += ((p3 % 100) % 10) * 3;
    soma += Dv1 * 2;

    restoDaSoma = soma % 11;

    if (restoDaSoma < 2)
    {
        if (Dv2 == 0)
        {
            v += 1;
        }
    }
    else
    {
        if (Dv2 == (11 - restoDaSoma))
        {
            v += 1;
        }
    }

    return v;
}
int validarSemestre(int s)
{
    int v = 0;

    if (s >= 1 && s <= 12)
    {
        v = 1;
    }

    return v;
}
int matriculaDeProfessor(Professores lista[], int qtd, int matricula)
{
    for (int i = 0; i < qtd; i++)
    {
        if (lista[i].matricula == matricula)
        {
            return i;
        }
    }
    return -1;
}
int verificarseocpfexiste(int p1, int p2, int p3, int dv)
        {
            for (int al = 0; al < qtdAlunosCadastrados; al++)
            {
                if (listaAlunos[al].cpf.p1 == p1 && 
                    listaAlunos[al].cpf.p2 == p2 &&
                    listaAlunos[al].cpf.p3 == p3 &&
                    listaAlunos[al].cpf.dv == dv)
                {
                    return 1;
                }
            }
        
            for (int pr = 0; pr < qtdProfessoresCadastrados; pr++)
            {
                if (listaProfessores[pr].cpf.p1 == p1 &&
                    listaProfessores[pr].cpf.p2 == p2 &&
                    listaProfessores[pr].cpf.p3 == p3 &&
                    listaProfessores[pr].cpf.dv == dv)
                {
                    return 1;
                }
            }
        
            return 0;
        }

void Professor()
{
    int qtdProfessores;
    printf("\nDigite a quantidade de professores para cadastro: ");
    scanf("%d", &qtdProfessores);
    if (qtdProfessores <= 0)
        return;
    if (qtdProfessoresCadastrados >= MAX_PROFESSORES)
    {
        printf("\nNão há mais espaço para cadastrar professores.\n");
        return;
    }
    if (qtdProfessores > MAX_PROFESSORES - qtdProfessoresCadastrados)
    {
        printf("\nQuantidade reduzida para caber no limite máximo de professores.\n");
        qtdProfessores = MAX_PROFESSORES - qtdProfessoresCadastrados;
    }
    char armazenamento[1000];
    for (int l = 0; l < qtdProfessores && qtdProfessoresCadastrados < MAX_PROFESSORES; l++)
    {
        Professores *ptr_professores = &listaProfessores[qtdProfessoresCadastrados];
        // matrícula do professor
        printf("\nDigite a matrícula do professor(a) nº%d: ", l + 1);
        scanf("%d", &ptr_professores->matricula);
        getchar();

        // Nome do professor
        printf("\nDigite o nome completo do professor(a) nº%d: ", l + 1);
        fgets(armazenamento, 1000, stdin);
        armazenamento[strcspn(armazenamento, "\n")] = 0;
        int tamanho = strlen(armazenamento) + 1;
        ptr_professores->nome = (char *)malloc(tamanho * sizeof(char));
        strcpy(ptr_professores->nome, armazenamento);

        // Sexo do professor
        printf("\nDigite se o professor(a) nº%d é do sexo Masculino [M] ou Feminino [F], digite 'M' ou 'F': ", l + 1);
        do
        {
            scanf(" %c", &ptr_professores->sexo);
            if ((validarSexo(ptr_professores->sexo)) == 0)
            {
                printf("\nSexo informado errado, digite 'F/f' para Feminino ou 'M/m' para Masculino: ");
            }
        } while (validarSexo(ptr_professores->sexo) == 0);

        // Data de Nascimento do professor
        printf("\nDigite a data de nascimento, no formato (xx/xx/xxxx) com as '/', do professor(a) nº%d: ", l + 1);
        do
        {
            scanf("%d/%d/%d", &ptr_professores->data.dia, &ptr_professores->data.mes, &ptr_professores->data.ano);
            if ((validarData(ptr_professores->data.dia, ptr_professores->data.mes, ptr_professores->data.ano)) == 0)
            {
                printf("\nErro na data, digite novamente no formato (xx/xx/xxxx) com as '/': \n");
            }
        } while (validarData(ptr_professores->data.dia, ptr_professores->data.mes, ptr_professores->data.ano) == 0);

        // Cadastro do Cpf do Professor
        printf("\nDigite o cpf, no formato (xxx.xxx.xxx-xx) e com 11 digitos, do professor(a) nº%d: ", l + 1);
        int lidos = 0;
        int cpfValido = 0;
        int cpfExiste = 0;
        do
        {
            lidos = scanf("%d.%d.%d-%d",
                &ptr_professores->cpf.p1,
                &ptr_professores->cpf.p2,
                &ptr_professores->cpf.p3,
                &ptr_professores->cpf.dv);

            if (lidos != 4)
            {
                printf("Formato inválido. Digite novamente (xxx.xxx.xxx-xx): ");
                continue;
            }

            cpfValido = (validarCpf(ptr_professores->cpf.p1,
                                    ptr_professores->cpf.p2,
                                    ptr_professores->cpf.p3,
                                    ptr_professores->cpf.dv) == 2);

            if (!cpfValido)
            {
                printf("CPF inválido. Digite novamente: ");
                continue;
            }

            cpfExiste = verificarseocpfexiste(ptr_professores->cpf.p1,
                                              ptr_professores->cpf.p2,
                                              ptr_professores->cpf.p3,
                                              ptr_professores->cpf.dv);

            if (cpfExiste)
            {
                printf("CPF já cadastrado. Digite outro CPF: ");
            }
        } while (lidos != 4 || !cpfValido || cpfExiste);

        printf("\n\t\t Professor(a) n°%d cadastrado com sucesso\t\t\n", l + 1);
        qtdProfessoresCadastrados++;
    }
    printf("Digite '1' se deseja listar ou '2' se deseja voltar para o menu principal: ");
    int opcao;
    scanf("%d", &opcao);
    if (opcao == 1)
    {
        printf("\t\tPROFESSORES\t\t\n\n");
        for (int lista = 0; lista < qtdProfessoresCadastrados; lista++)
        {
            printf("PROFESSOR %d:\n", lista + 1);
            printf("MATRÍCULA- %d\n", listaProfessores[lista].matricula);
            printf("  NOME- %s\n", listaProfessores[lista].nome);
            printf("  SEXO- %c\n", listaProfessores[lista].sexo);
            printf("  CPF- %03d.%03d.%03d-%02d\n", listaProfessores[lista].cpf.p1, listaProfessores[lista].cpf.p2, listaProfessores[lista].cpf.p3,
                   listaProfessores[lista].cpf.dv);
            printf("  DATA DE NASCIMENTO- %d/%d/%d\n", listaProfessores[lista].data.dia, listaProfessores[lista].data.mes,
                   listaProfessores[lista].data.ano);
        }
    }
}
void Aluno()
{
    int qtdAlunos;
    printf("\nDigite a quantidade de alunos para cadastro: ");
    scanf("%d", &qtdAlunos);
    if (qtdAlunos <= 0)
        return;
    if (qtdAlunosCadastrados >= MAX_ALUNOS)
    {
        printf("\nNão há mais espaço para cadastrar alunos.\n");
        return;
    }
    if (qtdAlunos > MAX_ALUNOS - qtdAlunosCadastrados)
    {
        printf("\nQuantidade reduzida para caber no limite máximo de alunos.\n");
        qtdAlunos = MAX_ALUNOS - qtdAlunosCadastrados;
    }
    // lista
    char armazenamento[1000];
    for (int l = 0; l < qtdAlunos && qtdAlunosCadastrados < MAX_ALUNOS; l++)
    {
        Alunos *ptr_alunos = &listaAlunos[qtdAlunosCadastrados];

        // matrícula do aluno
        printf("\nDigite a matrícula do aluno(a) nº%d: ", l + 1);
        scanf("%d", &ptr_alunos->matricula);
        getchar();

        // Nome do aluno
        printf("\nDigite o nome completo do aluno(a) nº%d: ", l + 1);
        fgets(armazenamento, 1000, stdin);
        armazenamento[strcspn(armazenamento, "\n")] = 0;
        int tamanho = strlen(armazenamento) + 1;
        ptr_alunos->nome = (char *)malloc(tamanho * sizeof(char));
        strcpy(ptr_alunos->nome, armazenamento);

        // Sexo do aluno
        printf("\nDigite se o aluno(a) nº%d é do sexo Masculino [M] ou Feminino [F], digite 'M' ou 'F': ", l + 1);
        do
        {
            scanf(" %c", &ptr_alunos->sexo);
            if ((validarSexo(ptr_alunos->sexo)) == 0)
            {
                printf("\nSexo informado errado, digite 'F/f' para Feminino ou 'M/m' para Masculino: ");
            }
        } while (validarSexo(ptr_alunos->sexo) == 0);

        // Data de Nascimento do aluno
        printf("\nDigite a data de nascimento, no formato (xx/xx/xxxx) com as '/', do aluno(a) nº%d: ", l + 1);
        do
        {
            scanf("%d/%d/%d", &ptr_alunos->data.dia, &ptr_alunos->data.mes, &ptr_alunos->data.ano);
            if ((validarData(ptr_alunos->data.dia, ptr_alunos->data.mes, ptr_alunos->data.ano)) == 0)
            {
                printf("\nErro na data, digite novamente no formato (xx/xx/xxxx) com as '/': \n");
            }
        } while (validarData(ptr_alunos->data.dia, ptr_alunos->data.mes, ptr_alunos->data.ano) == 0);

        // Cadastro do Cpf do aluno
        printf("\nDigite o cpf, no formato (xxx.xxx.xxx-xx) e com 11 digitos, do professor(a) nº%d: ", l + 1);
        int lidos = 0;
        int cpfValido = 0;
        int cpfExiste = 0;
        do
        {
            lidos = scanf("%d.%d.%d-%d",
                &ptr_alunos->cpf.p1,
                &ptr_alunos->cpf.p2,
                &ptr_alunos->cpf.p3,
                &ptr_alunos->cpf.dv);

            if (lidos != 4)
            {
                printf("Formato inválido. Digite novamente (xxx.xxx.xxx-xx): ");
                continue;
            }

            cpfValido = (validarCpf(ptr_alunos->cpf.p1,
                                    ptr_alunos->cpf.p2,
                                    ptr_alunos->cpf.p3,
                                    ptr_alunos->cpf.dv) == 2);

            if (!cpfValido)
            {
                printf("CPF inválido. Digite novamente: ");
                continue;
            }

            cpfExiste = verificarseocpfexiste(ptr_alunos->cpf.p1,
                                              ptr_alunos->cpf.p2,
                                              ptr_alunos->cpf.p3,
                                              ptr_alunos->cpf.dv);

            if (cpfExiste)
            {
                printf("CPF já cadastrado. Digite outro CPF: ");
            }
        } while (lidos != 4 || !cpfValido || cpfExiste);

        printf("\n\t\t Aluno(a) n°%d cadastrado com sucesso\t\t\n", l + 1);
        qtdAlunosCadastrados++;

        printf("Digite '1' se deseja listar ou '2' se deseja voltar para o menu principal: ");
        int opcao;
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            printf("\t\tALUNOS\t\t\n\n");
            for (int lista = 0; lista < qtdAlunosCadastrados; lista++)
            {
                printf("ALUNO %d:\n", lista + 1);
                printf("MATRÍCULA\t - %d\n", listaAlunos[lista].matricula);
                printf("  NOME\t    - %s\n", listaAlunos[lista].nome);
                printf("  SEXO\t    - %c\n", listaAlunos[lista].sexo);
                  printf("  CPF\t     - %03d.%03d.%03d-%02d\n", listaAlunos[lista].cpf.p1, listaAlunos[lista].cpf.p2, listaAlunos[lista].cpf.p3,
                      listaAlunos[lista].cpf.dv);
                printf("  DATA DE NASCIMENTO\t - %d/%d/%d\n", listaAlunos[lista].data.dia, listaAlunos[lista].data.mes,
                       listaAlunos[lista].data.ano);
            }
        }
    }
    return;
}
void Disciplina()
{
    int qtdDisciplinas;
    int opcao;
    printf("\nDigite a quantidade de disciplinas para cadastro: ");
    scanf("%d", &qtdDisciplinas);
    if (qtdDisciplinas <= 0)
        return;
    if (qtdDisciplinasCadastradas >= MAX_DISCIPLINAS)
    {
        printf("\nNão há mais espaço para cadastrar disciplinas.\n");
        return;
    }
    if (qtdDisciplinas > MAX_DISCIPLINAS - qtdDisciplinasCadastradas)
    {
        printf("\nQuantidade reduzida para caber no limite máximo de disciplinas.\n");
        qtdDisciplinas = MAX_DISCIPLINAS - qtdDisciplinasCadastradas;
    }
    // tamanho da lista de disciplinas
    char armazenamento[1000];
    for (int l = 0; l < qtdDisciplinas; l++)
    {
        Disciplinas *ptr_disciplinas = &listaDisciplinas[qtdDisciplinasCadastradas];

        // código da disciplina
        printf("\nDigite o código da disciplina nº%d: ", l + 1);
        scanf("%d", &ptr_disciplinas->codigo);
        getchar();

        // Nome da disciplina
        printf("\nDigite o nome da disciplina: ");
        fgets(armazenamento, 1000, stdin);
        armazenamento[strcspn(armazenamento, "\n")] = 0;
        int tamanho = strlen(armazenamento) + 1;
        ptr_disciplinas->nome = (char *)malloc(tamanho * sizeof(char));
        strcpy(ptr_disciplinas->nome, armazenamento);

        // Semestre da disciplina
        printf("\nDigite o semestre da disciplina nº%d, só o número: ", l + 1);
        do
        {
            scanf("%d", &ptr_disciplinas->semestre);
            if (validarSemestre(ptr_disciplinas->semestre) == 0)
            {
                printf("\nSemestre informado incorreto, tente novamente: ");
            }
        } while (validarSemestre(ptr_disciplinas->semestre) == 0);
        // Professor da disciplina
        int valido = 2;
        int matriculaExistente = 0;
        printf("\nDigite '1' se o professor já está cadastrado ou Digite ´2´ se o professor não está cadastrado nº%d: ", l + 1);
        scanf("%d", &valido);
        while (valido != 1 && valido != 2)
        {
            printf("\nNúmero digitado inválido, digite 1 ou 2: ");
            scanf("%d", &valido);
        }
        if (valido == 2)
        {
            getchar();
            printf("\nDigite o nome do Professor dessa disciplina: ");
            fgets(armazenamento, 1000, stdin);
            armazenamento[strcspn(armazenamento, "\n")] = 0;
            tamanho = strlen(armazenamento) + 1;
            ptr_disciplinas->professor.nome = (char *)malloc(tamanho * sizeof(char));
            strcpy(ptr_disciplinas->professor.nome, armazenamento);
        }
        else
        {
            printf("\nDigite a matrícula do professor: ");
            scanf("%d", &matriculaExistente);
            int posicao = matriculaDeProfessor(listaProfessores, qtdProfessoresCadastrados, matriculaExistente);
            while (posicao == -1)
            {
                printf("\nMatrícula não encontrada. Digite novamente: ");
                scanf("%d", &matriculaExistente);
                posicao = matriculaDeProfessor(listaProfessores, qtdProfessoresCadastrados, matriculaExistente);
            }
            ptr_disciplinas->professor = listaProfessores[posicao];
        }
        ptr_disciplinas->qtdAlunosNestaDisciplina = 0;

        // Inserir ou Excluir alunos na disciplina
        printf("\nDigite [1] se você quer inserir um aluno na disciplina, [2] se quer excluir, ou [0] para pular: ");
        scanf("%d", &opcao);

        
        if (opcao == 1)
        {
            int matriculaBusca, i, posAluno = -1;
            
            if (qtdAlunosCadastrados == 0) {
                printf("Erro: Nenhum aluno cadastrado no sistema ainda para ser inserido!\n");
            } else {
                printf("\nDigite a matrícula do aluno: ");
                scanf("%d", &matriculaBusca);

                
                for (i = 0; i < qtdAlunosCadastrados; i++) {
                    if (listaAlunos[i].matricula == matriculaBusca) {
                        posAluno = i;
                        break;
                    }
                }

                if (posAluno != -1) {
                   
                    int posicaoVazia = ptr_disciplinas->qtdAlunosNestaDisciplina;
                    
                   
                    ptr_disciplinas->alunosMatriculados[posicaoVazia] = listaAlunos[posAluno];
                    
                    
                    ptr_disciplinas->qtdAlunosNestaDisciplina++;
                    
                    printf("\nAluno %s matriculado na disciplina com sucesso!\n", listaAlunos[posAluno].nome);
                } else {
                    printf("\nMatrícula não encontrada no sistema!\n");
                }
            }
        }

        
        else if (opcao == 2)
        {
            printf("\nAinda não há alunos nesta disciplina para excluir (ela acabou de ser criada)!\n");
        }

    
        qtdDisciplinasCadastradas++; 
        printf("\n\t\t Disciplina cadastrada com sucesso!\t\t\n");

        
        printf("Digite '1' se deseja listar ou '2' se deseja voltar para o menu principal: ");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            printf("\t\tDisciplinas\t\t\n\n");
            for (int lista = 0; lista < qtdDisciplinasCadastradas; lista++)
            {
                printf("DISCIPLINA %d:\n", lista + 1);
                printf("CÓDIGO\t - %d\n", listaDisciplinas[lista].codigo);
                printf("  NOME\t    - %s\n", listaDisciplinas[lista].nome);
                printf("  SEMESTRE\t    - %d\n", listaDisciplinas[lista].semestre);
                printf("  PROFESSOR DA DISCIPLINA - %s\n", listaDisciplinas[lista].professor.nome);
            }
        }
    }
    }
int voltar(){
    int opcao;
   printf("\t-----Bem vindo ao Sistema Escola-----\n\n");
        printf("\t°°°°°°°°Cadastrar°°°°°°°°\n\t\tDigite [1]\n\n");
        printf("\t°°°°°°°°Alterar°°°°°°°°\n\t\tDigite [2]\n\n");
        printf("\t°°°°°°°°Excluir°°°°°°°°\n\t\tDigite [3]\n\n");
        printf("\t°°°°°°°°Listar°°°°°°°°\n\t\tDigite [4]\n\n");
        printf("\t°°°°°°°°Sair°°°°°°°°\n\t\tDigite [5]\n\n");
    scanf("%d", &opcao);
    return opcao;
}
void alterarProfessor() {
    int buscarmatricula, i, indiceEncontrado = -1;
    char armazenamento[1000];
    int opcaoAlterar;

    if (qtdProfessoresCadastrados == 0) {
        printf("\nNenhum professor cadastrado ainda!\n");
        return;
    }

    printf("\n--- ALTERAR DADOS DE PROFESSOR ---\n");
    printf("Digite a matrícula do professor que deseja alterar: ");
    scanf("%d", &buscarmatricula);

    for (i = 0; i < qtdProfessoresCadastrados; i++) {
        if (listaProfessores[i].matricula == buscarmatricula) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado == -1) {
        printf("\nProfessor com a matrícula %d não encontrado.\n", buscarmatricula);
        return;
    }

    // Menu de alteração
    printf("\nProfessor encontrado: %s\n", listaProfessores[indiceEncontrado].nome);
    printf("O que deseja alterar?\n");
    printf("[1] Nome\n");
    printf("[2] Sexo\n");
    printf("[3] Data de Nascimento\n");
    printf("[0] Cancelar\n");
    printf("Escolha: ");
    scanf("%d", &opcaoAlterar);
    getchar();

    switch (opcaoAlterar) {
        case 1:
            printf("Digite o novo nome: ");
            fgets(armazenamento, 1000, stdin);
            armazenamento[strcspn(armazenamento, "\n")] = 0;
            
            free(listaProfessores[indiceEncontrado].nome); 
            
            int tamanho = strlen(armazenamento) + 1;
            listaProfessores[indiceEncontrado].nome = (char *)malloc(tamanho * sizeof(char));
            strcpy(listaProfessores[indiceEncontrado].nome, armazenamento);
            printf("Nome atualizado com sucesso!\n");
            break;

        case 2:
            printf("Digite o novo sexo [M/F]: ");
            do {
                scanf(" %c", &listaProfessores[indiceEncontrado].sexo);
                if (validarSexo(listaProfessores[indiceEncontrado].sexo) == 0) {
                    printf("Sexo inválido. Digite 'F/f' ou 'M/m': ");
                }
            } while (validarSexo(listaProfessores[indiceEncontrado].sexo) == 0);
            printf("Sexo atualizado com sucesso!\n");
            break;

        case 3:
            printf("Digite a nova data de nascimento (xx/xx/xxxx): ");
            do {
                scanf("%d/%d/%d", 
                    &listaProfessores[indiceEncontrado].data.dia, 
                    &listaProfessores[indiceEncontrado].data.mes, 
                    &listaProfessores[indiceEncontrado].data.ano);
                    
                if (validarData(listaProfessores[indiceEncontrado].data.dia, 
                                listaProfessores[indiceEncontrado].data.mes, 
                                listaProfessores[indiceEncontrado].data.ano) == 0) {
                    printf("Data inválida. Digite novamente (xx/xx/xxxx): ");
                }
            } while (validarData(listaProfessores[indiceEncontrado].data.dia, 
                                 listaProfessores[indiceEncontrado].data.mes, 
                                 listaProfessores[indiceEncontrado].data.ano) == 0);
            printf("Data atualizada com sucesso!\n");
            break;

        case 0:
            printf("Alteração cancelada.\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }
}
void alterarAluno(){
 int buscarmatricula, i, indiceEncontrado = -1;
    char armazenamento[1000];
    int opcaoAlterar;

    if (qtdAlunosCadastrados== 0) {
        printf("\nNenhum aluno cadastrado ainda!\n");
        return;
    }

    printf("\n--- ALTERAR DADOS DE ALUNO ---\n");
    printf("Digite a matrícula do professor que deseja alterar: ");
    scanf("%d", &buscarmatricula);

    for (i = 0; i < qtdAlunosCadastrados; i++) {
        if (listaAlunos[i].matricula == buscarmatricula) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado == -1) {
        printf("\nAluno com a matrícula %d não encontrado.\n", buscarmatricula);
        return;
    }

    printf("\nAluno encontrado: %s\n", listaAlunos[indiceEncontrado].nome);
    printf("O que deseja alterar?\n");
    printf("[1] Nome\n");
    printf("[2] Sexo\n");
    printf("[3] Data de Nascimento\n");
    printf("[0] Cancelar\n");
    printf("Escolha: ");
    scanf("%d", &opcaoAlterar);
    getchar();

    switch (opcaoAlterar) {
        case 1:
            printf("Digite o novo nome: ");
            fgets(armazenamento, 1000, stdin);
            armazenamento[strcspn(armazenamento, "\n")] = 0;
            
            free(listaAlunos[indiceEncontrado].nome); 
            
            int tamanho = strlen(armazenamento) + 1;
            listaAlunos[indiceEncontrado].nome = (char *)malloc(tamanho * sizeof(char));
            strcpy(listaAlunos[indiceEncontrado].nome, armazenamento);
            printf("Nome atualizado com sucesso!\n");
            break;

        case 2:
            printf("Digite o novo sexo [M/F]: ");
            do {
                scanf(" %c", &listaAlunos[indiceEncontrado].sexo);
                if (validarSexo(listaAlunos[indiceEncontrado].sexo) == 0) {
                    printf("Sexo inválido. Digite 'F/f' ou 'M/m': ");
                }
            } while (validarSexo(listaAlunos[indiceEncontrado].sexo) == 0);
            printf("Sexo atualizado com sucesso!\n");
            break;

        case 3:
            printf("Digite a nova data de nascimento (xx/xx/xxxx): ");
            do {
                scanf("%d/%d/%d", 
                    &listaAlunos[indiceEncontrado].data.dia, 
                    &listaAlunos[indiceEncontrado].data.mes, 
                    &listaAlunos[indiceEncontrado].data.ano);
                    
                if (validarData(listaAlunos[indiceEncontrado].data.dia, 
                                listaAlunos[indiceEncontrado].data.mes, 
                                listaAlunos[indiceEncontrado].data.ano) == 0) {
                    printf("Data inválida. Digite novamente (xx/xx/xxxx): ");
                }
            } while (validarData(listaAlunos[indiceEncontrado].data.dia, 
                                 listaAlunos[indiceEncontrado].data.mes, 
                                 listaAlunos[indiceEncontrado].data.ano) == 0);
            printf("Data atualizada com sucesso!\n");
            break;

        case 0:
            printf("Alteração cancelada.\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }
}
void alterarDisciplina() {
    int codigoBusca, i, indiceEncontrado = -1;
    char armazenamento[1000];
    int opcaoAlterar;

   
    if (qtdDisciplinasCadastradas == 0) {
        printf("\nNenhuma disciplina cadastrada ainda!\n");
        return;
    }

    printf("\n--- ALTERAR DADOS DE DISCIPLINA ---\n");
    printf("Digite o código da disciplina que deseja alterar: ");
    scanf("%d", &codigoBusca);

   
    for (i = 0; i < qtdDisciplinasCadastradas; i++) {
        if (listaDisciplinas[i].codigo == codigoBusca) {
            indiceEncontrado = i;
            break;
        }
    }

    
    if (indiceEncontrado == -1) {
        printf("\nDisciplina com o código %d não encontrada.\n", codigoBusca);
        return;
    }

    //Menu de alteração
    printf("\nDisciplina encontrada: %s\n", listaDisciplinas[indiceEncontrado].nome);
    printf("O que deseja alterar?\n");
    printf("[1] Nome\n");
    printf("[2] Semestre\n");
    printf("[3] Professor Responsável\n");
    printf("[0] Cancelar\n");
    printf("Escolha: ");
    scanf("%d", &opcaoAlterar);
    getchar(); 

    switch (opcaoAlterar) {
        case 1:
            printf("Digite o novo nome da disciplina: ");
            fgets(armazenamento, 1000, stdin);
            armazenamento[strcspn(armazenamento, "\n")] = 0; 
            
            
            free(listaDisciplinas[indiceEncontrado].nome); 
            
            int tamanho = strlen(armazenamento) + 1;
            listaDisciplinas[indiceEncontrado].nome = (char *)malloc(tamanho * sizeof(char));
            strcpy(listaDisciplinas[indiceEncontrado].nome, armazenamento);
            printf("Nome da disciplina atualizado com sucesso!\n");
            break;

        case 2:
            printf("Digite o novo semestre (apenas o número): ");
            do {
                scanf("%d", &listaDisciplinas[indiceEncontrado].semestre);
                if (validarSemestre(listaDisciplinas[indiceEncontrado].semestre) == 0) {
                    printf("Semestre inválido. Tente novamente: ");
                }
            } while (validarSemestre(listaDisciplinas[indiceEncontrado].semestre) == 0);
            printf("Semestre atualizado com sucesso!\n");
            break;

        case 3:
        {
            if (qtdProfessoresCadastrados == 0) {
                printf("Nenhum professor cadastrado no sistema para assumir a disciplina.\n");
                break;
            }
            
            int matriculaNova;
            printf("Digite a matrícula do novo professor responsável: ");
            scanf("%d", &matriculaNova);
            
            
            int posProf = matriculaDeProfessor(listaProfessores, qtdProfessoresCadastrados, matriculaNova);
            
            while (posProf == -1) {
                printf("\nMatrícula não encontrada. Digite novamente (ou digite 0 para cancelar): ");
                scanf("%d", &matriculaNova);
                
                if (matriculaNova == 0) {
                    break; 
                }
                posProf = matriculaDeProfessor(listaProfessores, qtdProfessoresCadastrados, matriculaNova);
            }

          
            if (posProf != -1) {
                listaDisciplinas[indiceEncontrado].professor = listaProfessores[posProf];
                printf("Professor responsável atualizado com sucesso para: %s\n", listaProfessores[posProf].nome);
            } else {
                printf("Alteração de professor cancelada.\n");
            }
            break;
        }

        case 0:
            printf("Alteração cancelada.\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }
}
void excluirProfessor() {
    int buscamatricula, i, j, indiceEncontrado = -1;
    int confirmacao;

    if (qtdProfessoresCadastrados == 0) {
        printf("\nNenhum professor cadastrado ainda!\n");
        return;
    }

    printf("\n--- EXCLUIR PROFESSOR ---\n");
    printf("Digite a matrícula do professor que deseja excluir: ");
    scanf("%d", &buscamatricula);

    for (i = 0; i < qtdProfessoresCadastrados; i++) {
        if (listaProfessores[i].matricula == buscamatricula) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado == -1) {
        printf("\nProfessor com a matrícula %d não encontrado.\n", buscamatricula);
        return;
    }

    printf("\nProfessor encontrado: %s\n", listaProfessores[indiceEncontrado].nome);
    printf("Tem certeza que deseja EXCLUIR este professor de forma permanente?\n");
    printf("[1] Sim\n[2] Nao\n");
    printf("Escolha: ");
    scanf("%d", &confirmacao);

    if (confirmacao == 1) {

        free(listaProfessores[indiceEncontrado].nome);

        for (j = indiceEncontrado; j < qtdProfessoresCadastrados - 1; j++) {
            listaProfessores[j] = listaProfessores[j + 1];
        }

        qtdProfessoresCadastrados--;
        
        printf("\nProfessor excluido com sucesso!\n");
    } else {
        printf("\nExclusão cancelada.\n");
    }
}
void excluirAluno(){
     int buscamatricula, i, j, indiceEncontrado = -1;
    int confirmacao;

    if (qtdAlunosCadastrados == 0) {
        printf("\nNenhum aluno cadastrado ainda!\n");
        return;
    }

    printf("\n--- EXCLUIR ALUNO ---\n");
    printf("Digite a matrícula do aluno que deseja excluir: ");
    scanf("%d", &buscamatricula);

    for (i = 0; i < qtdAlunosCadastrados; i++) {
        if (listaAlunos[i].matricula == buscamatricula) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado == -1) {
        printf("\nAluno com a matrícula %d não encontrado.\n", buscamatricula);
        return;
    }

    printf("\nAluno encontrado: %s\n", listaAlunos[indiceEncontrado].nome);
    printf("Tem certeza que deseja EXCLUIR este aluno de forma permanente?\n");
    printf("[1] Sim\n[2] Nao\n");
    printf("Escolha: ");
    scanf("%d", &confirmacao);

    if (confirmacao == 1) {

        free(listaAlunos[indiceEncontrado].nome);

        for (j = indiceEncontrado; j < qtdAlunosCadastrados - 1; j++) {
            listaAlunos[j] = listaAlunos[j + 1];
        }

        qtdAlunosCadastrados--;
        
        printf("\nAluno excluido com sucesso!\n");
    } else {
        printf("\nExclusão cancelada.\n");
    }
}
void excluirDisciplina() {
    int codigoBusca, i, j, indiceEncontrado = -1;
    int confirmacao;

    if (qtdDisciplinasCadastradas == 0) {
        printf("\nNenhuma disciplina cadastrada ainda!\n");
        return;
    }

    printf("\n--- EXCLUIR DISCIPLINA ---\n");
    printf("Digite o código da disciplina que deseja excluir: ");
    scanf("%d", &codigoBusca);

    for (i = 0; i < qtdDisciplinasCadastradas; i++) {
        if (listaDisciplinas[i].codigo == codigoBusca) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado == -1) {
        printf("\nDisciplina com o código %d não encontrada.\n", codigoBusca);
        return;
    }
    
    printf("\nDisciplina encontrada: %s\n", listaDisciplinas[indiceEncontrado].nome);
    printf("Tem certeza que deseja EXCLUIR esta disciplina de forma permanente?\n");
    printf("[1] Sim\n[2] Nao\n");
    printf("Escolha: ");
    scanf("%d", &confirmacao);

    if (confirmacao == 1) {
        
        free(listaDisciplinas[indiceEncontrado].nome);

        for (j = indiceEncontrado; j < qtdDisciplinasCadastradas - 1; j++) {
            listaDisciplinas[j] = listaDisciplinas[j + 1];
        }

        qtdDisciplinasCadastradas--;
        
        printf("\nDisciplina excluída com sucesso!\n");
    } else {
        printf("\nExclusão cancelada.\n");
    }
}
void imprimirAluno(Alunos a) {
    printf("Matrícula: %d | Nome: %s | Sexo: %c | Nasc: %02d/%02d/%04d | CPF: %03d.%03d.%03d-%02d\n",
           a.matricula, a.nome, a.sexo, a.data.dia, a.data.mes, a.data.ano,
           a.cpf.p1, a.cpf.p2, a.cpf.p3, a.cpf.dv);
}
void imprimirProfessor(Professores p) {
    printf("Matrícula: %d | Nome: %s | Sexo: %c | Nasc: %02d/%02d/%04d | CPF: %03d.%03d.%03d-%02d\n",
           p.matricula, p.nome, p.sexo, p.data.dia, p.data.mes, p.data.ano,
           p.cpf.p1, p.cpf.p2, p.cpf.p3, p.cpf.dv);
}
void listarTodosAlunos() {
    if (qtdAlunosCadastrados == 0) { printf("Nenhum aluno cadastrado.\n"); return; }
    printf("\n--- LISTA DE ALUNOS ---\n");
    for (int i = 0; i < qtdAlunosCadastrados; i++) imprimirAluno(listaAlunos[i]);
}
void listarTodosProfessores() {
    if (qtdProfessoresCadastrados == 0) { printf("Nenhum professor cadastrado.\n"); return; }
    printf("\n--- LISTA DE PROFESSORES ---\n");
    for (int i = 0; i < qtdProfessoresCadastrados; i++) imprimirProfessor(listaProfessores[i]);
}
void listarDisciplinas() {
    if (qtdDisciplinasCadastradas == 0) { printf("Nenhuma disciplina cadastrada.\n"); return; }
    printf("\n--- LISTA DE DISCIPLINAS ---\n");
    for (int i = 0; i < qtdDisciplinasCadastradas; i++) {
        printf("Código: %d | Nome: %s | Semestre: %d | Professor: %s\n", 
               listaDisciplinas[i].codigo, listaDisciplinas[i].nome, 
               listaDisciplinas[i].semestre, listaDisciplinas[i].professor.nome);
    }
}
void listarPorSexo(int tipoPessoa) {
    char sexoBusca;
    printf("Digite o sexo para busca (M/F): ");
    scanf(" %c", &sexoBusca);
    
    int encontrou = 0;
    if (tipoPessoa == 1) {
        printf("\n--- ALUNOS DO SEXO %c ---\n", sexoBusca);
        for (int i = 0; i < qtdAlunosCadastrados; i++) {
            if (listaAlunos[i].sexo == sexoBusca || listaAlunos[i].sexo == sexoBusca + 32 || listaAlunos[i].sexo == sexoBusca - 32) { // Considera maiúscula/minúscula
                imprimirAluno(listaAlunos[i]);
                encontrou = 1;
            }
        }
    } else {
        printf("\n--- PROFESSORES DO SEXO %c ---\n", sexoBusca);
        for (int i = 0; i < qtdProfessoresCadastrados; i++) {
            if (listaProfessores[i].sexo == sexoBusca || listaProfessores[i].sexo == sexoBusca + 32 || listaProfessores[i].sexo == sexoBusca - 32) {
                imprimirProfessor(listaProfessores[i]);
                encontrou = 1;
            }
        }
    }
    if (!encontrou) printf("Nenhuma pessoa encontrada com esse sexo.\n");
}
int comparaData(Data d1, Data d2) {
    if (d1.ano != d2.ano) return d1.ano - d2.ano;
    if (d1.mes != d2.mes) return d1.mes - d2.mes;
    return d1.dia - d2.dia;
}
void listarOrdenadoPorNome(int tipo) { 
    int max = (tipo == 1) ? qtdAlunosCadastrados : qtdProfessoresCadastrados;
    if (max == 0) { printf("Nenhum cadastro encontrado.\n"); return; }

    int idx[max];
    for (int i = 0; i < max; i++) idx[i] = i;

    for (int i = 0; i < max - 1; i++) {
        for (int j = 0; j < max - i - 1; j++) {
            int troca = 0;
            if (tipo == 1 && strcmp(listaAlunos[idx[j]].nome, listaAlunos[idx[j+1]].nome) > 0) troca = 1;
            else if (tipo == 2 && strcmp(listaProfessores[idx[j]].nome, listaProfessores[idx[j+1]].nome) > 0) troca = 1;

            if (troca) {
                int temp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = temp;
            }
        }
    }

    printf("\n--- LISTA ORDENADA POR NOME ---\n");
    for (int i = 0; i < max; i++) {
        if (tipo == 1) imprimirAluno(listaAlunos[idx[i]]);
        else imprimirProfessor(listaProfessores[idx[i]]);
    }
}
void listarOrdenadoPorData(int tipo) {
    int max = (tipo == 1) ? qtdAlunosCadastrados : qtdProfessoresCadastrados;
    if (max == 0) { printf("Nenhum cadastro encontrado.\n"); return; }

    int idx[max];
    for (int i = 0; i < max; i++) idx[i] = i;

    for (int i = 0; i < max - 1; i++) {
        for (int j = 0; j < max - i - 1; j++) {
            int troca = 0;
            if (tipo == 1 && comparaData(listaAlunos[idx[j]].data, listaAlunos[idx[j+1]].data) > 0) troca = 1;
            else if (tipo == 2 && comparaData(listaProfessores[idx[j]].data, listaProfessores[idx[j+1]].data) > 0) troca = 1;

            if (troca) {
                int temp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = temp;
            }
        }
    }

    printf("\n--- LISTA ORDENADA POR DATA DE NASCIMENTO ---\n");
    for (int i = 0; i < max; i++) {
        if (tipo == 1) imprimirAluno(listaAlunos[idx[i]]);
        else imprimirProfessor(listaProfessores[idx[i]]);
    }
}
void listarAniversariantesDoMes() {
    int mesBusca, encontrou = 0;
    printf("Digite o número do mês (1 a 12): ");
    scanf("%d", &mesBusca);

    printf("\n--- ANIVERSARIANTES DO MÊS %d ---\n", mesBusca);
    for (int i = 0; i < qtdAlunosCadastrados; i++) {
        if (listaAlunos[i].data.mes == mesBusca) {
            printf("[ALUNO] "); imprimirAluno(listaAlunos[i]); encontrou = 1;
        }
    }
    for (int i = 0; i < qtdProfessoresCadastrados; i++) {
        if (listaProfessores[i].data.mes == mesBusca) {
            printf("[PROFESSOR] "); imprimirProfessor(listaProfessores[i]); encontrou = 1;
        }
    }
    if (!encontrou) printf("Nenhum aniversariante neste mês.\n");
}
void buscarPessoasPorString() {
    char busca[50];
    int encontrou = 0;
    printf("Digite o nome ou parte do nome para buscar (min. 3 letras): ");
    scanf(" %49[^\n]", busca); 

    if (strlen(busca) < 3) {
        printf("A busca precisa ter pelo menos 3 caracteres!\n");
        return;
    }

    printf("\n--- RESULTADOS DA BUSCA PARA '%s' ---\n", busca);
   
    for (int i = 0; i < qtdAlunosCadastrados; i++) {
        if (strstr(listaAlunos[i].nome, busca) != NULL) {
            printf("[ALUNO] "); imprimirAluno(listaAlunos[i]); encontrou = 1;
        }
    }
    for (int i = 0; i < qtdProfessoresCadastrados; i++) {
        if (strstr(listaProfessores[i].nome, busca) != NULL) {
            printf("[PROFESSOR] "); imprimirProfessor(listaProfessores[i]); encontrou = 1;
        }
    }
    if (!encontrou) printf("Ninguém encontrado.\n");
}
int contarDisciplinasDoAluno(int matriculaAluno) {
    int total = 0;
    for (int i = 0; i < qtdDisciplinasCadastradas; i++) {
        for (int j = 0; j < listaDisciplinas[i].qtdAlunosNestaDisciplina; j++) {
            if (listaDisciplinas[i].alunosMatriculados[j].matricula == matriculaAluno) {
                total++;
                break;
            }
        }
    }
    return total;
}
void listarAlunosMenosDe3Disciplinas() {
    if (qtdAlunosCadastrados == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    int encontrou = 0;
    printf("\n--- ALUNOS MATRICULADOS EM MENOS DE 3 DISCIPLINAS ---\n");
    for (int i = 0; i < qtdAlunosCadastrados; i++) {
        int qtd = contarDisciplinasDoAluno(listaAlunos[i].matricula);
        if (qtd < 3) {
            imprimirAluno(listaAlunos[i]);
            printf("Quantidade de disciplinas: %d\n", qtd);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum aluno encontrado com menos de 3 disciplinas.\n");
    }
}
void listarDisciplinasSemAlunos() {
    if (qtdDisciplinasCadastradas == 0) {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }

    int encontrou = 0;
    printf("\n--- DISCIPLINAS SEM ALUNOS MATRICULADOS ---\n");
    for (int i = 0; i < qtdDisciplinasCadastradas; i++) {
        if (listaDisciplinas[i].qtdAlunosNestaDisciplina == 0) {
            printf("Código: %d | Nome: %s | Semestre: %d\n",
                   listaDisciplinas[i].codigo,
                   listaDisciplinas[i].nome,
                   listaDisciplinas[i].semestre);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Todas as disciplinas possuem alunos matriculados.\n");
    }
}

int main()
{
    printf("\t-----Bem vindo ao Sistema Escola-----\n\n");
    printf("\t°°°°°°°°Cadastrar°°°°°°°°\n\t\tDigite [1]\n\n");
    printf("\t°°°°°°°°Alterar°°°°°°°°\n\t\tDigite [2]\n\n");
    printf("\t°°°°°°°°Excluir°°°°°°°°\n\t\tDigite [3]\n\n");
    printf("\t°°°°°°°°Listar°°°°°°°°\n\t\tDigite [4]\n\n");
    printf("\t°°°°°°°°Sair°°°°°°°°\n\t\tDigite [5]\n\n");
    int opcao;
    int opcaoCadastro;
    int ultimoCaso = 0;
    scanf("%d", &opcao);
    if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5)
    {
        opcao = opcaoValida(opcao, ultimoCaso);
    }
    while (opcao != 5)
    {
        switch (opcao)
        {
        case 1:
        {
           opcaoCadastro = menuParte2(1);
            if (opcaoCadastro == 1)
            {
                Professor();
            }
            else if (opcaoCadastro == 2)
            {
                Aluno();
            }
            else if (opcaoCadastro == 3)
            {
                Disciplina();
            }
            else if (opcaoCadastro == 5)
            {
                opcao = 5;
            }
            break;
        }
        case 2:
            opcaoCadastro = menuParte2(2);
             if (opcaoCadastro == 1)
            {
                alterarProfessor();
            }
            else if (opcaoCadastro == 2)
            {
                alterarAluno();
            }
            else if (opcaoCadastro == 3)
            {
                alterarDisciplina();
            }
            else if (opcaoCadastro == 5)
            {
                opcao = 5;
            }
            break;
        case 3:
            opcaoCadastro = menuParte2(3);
             if (opcaoCadastro == 1)
            {
               excluirProfessor();
            }
            else if (opcaoCadastro == 2)
            {
                excluirAluno();
            }
            else if (opcaoCadastro == 3)
            {
                excluirDisciplina();
            }
            else if (opcaoCadastro == 5)
            {
                opcao = 5;
            }
            break;
        case 4:
             opcaoCadastro = menuParte2(4);
             if(opcaoCadastro==1) {
                listarTodosAlunos();
                 break;
             }
                else if(opcaoCadastro==2) {
                    listarTodosProfessores(); 
                    break;
                }
                else if(opcaoCadastro==3) {
                 listarDisciplinas();
                  break;
                }
                else if(opcaoCadastro==4) {
                listarPorSexo(1); 
                break;
                }
                else if(opcaoCadastro==5){
                 listarOrdenadoPorNome(1); 
                 break;
                }
                else if(opcaoCadastro==6){
                listarOrdenadoPorData(1);
                 break;
                }
                else if(opcaoCadastro==7){
                listarPorSexo(2); 
                break;
                }
                else if(opcaoCadastro==8){
                 listarOrdenadoPorNome(2);
                  break;
                }
                else if(opcaoCadastro==9){
                listarOrdenadoPorData(2); 
                break;
                }
                else if(opcaoCadastro==10){
                 listarAniversariantesDoMes(); 
                 break;
                }
                else if(opcaoCadastro==11){
                 buscarPessoasPorString(); 
                 break;
                }
                else if(opcaoCadastro==12){  
                listarAlunosMenosDe3Disciplinas();
                break;
                } 
                else if(opcaoCadastro==13){ 
                    listarDisciplinasSemAlunos();
                     break;
                }
                else if(opcaoCadastro==14){
                    break;
                }
                else if(opcaoCadastro==15){
                    opcao = 5;
                     break;
                } 
        case 5:
            break;
        }

        if (opcao == 5)
        {
            break;
        }
        
        printf("\t-----Bem vindo ao Sistema Escola-----\n\n");
        printf("\t°°°°°°°°Cadastrar°°°°°°°°\n\t\tDigite [1]\n\n");
        printf("\t°°°°°°°°Alterar°°°°°°°°\n\t\tDigite [2]\n\n");
        printf("\t°°°°°°°°Excluir°°°°°°°°\n\t\tDigite [3]\n\n");
        printf("\t°°°°°°°°Listar°°°°°°°°\n\t\tDigite [4]\n\n");
        printf("\t°°°°°°°°Sair°°°°°°°°\n\t\tDigite [5]\n\n");
        scanf("%d", &opcao);

        if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5)
        {
            opcao = opcaoValida(opcao, ultimoCaso);
        }

    }
    printf("\t\tObrigado por acessar!\t\t");
    return 0;
}