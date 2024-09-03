#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura que armazena as informações de um aluno
typedef struct {
    char nome[100];
    int matricula;
    char curso[100];
    int periodo;
    float media;
} Aluno;

// Função para adicionar um novo aluno
void adicionarAluno(Aluno* alunos, int* contador, int tamanhoMax) {
    if (*contador >= tamanhoMax) {
        printf("Lista de alunos cheia. Não é possível adicionar mais alunos.\n");
        return;
    }

    Aluno* alunoAtual = &alunos[*contador];

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", alunoAtual->nome);

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &alunoAtual->matricula);

    printf("Digite o curso do aluno: ");
    scanf(" %[^\n]", alunoAtual->curso);

    printf("Digite o período do aluno: ");
    scanf("%d", &alunoAtual->periodo);

    printf("Digite a média do aluno: ");
    scanf("%f", &alunoAtual->media);

    (*contador)++;
    printf("Aluno adicionado com sucesso!\n");
}

// Função para listar todos os alunos
void listarAlunos(Aluno* alunos, int contador) {
    if (contador == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
        Aluno* alunoAtual = &alunos[i];
        printf("Nome: %s\n", alunoAtual->nome);
        printf("Matrícula: %d\n", alunoAtual->matricula);
        printf("Curso: %s\n", alunoAtual->curso);
        printf("Período: %d\n", alunoAtual->periodo);
        printf("Média: %.2f\n", alunoAtual->media);
        printf("---------------------------\n");
    }
}

int main() {
    int tamanhoMax, opcao, contador = 0;

    printf("Digite o número máximo de alunos: ");
    scanf("%d", &tamanhoMax);

    // Alocando memória dinamicamente para o array de alunos
    Aluno* alunos = (Aluno*)malloc(tamanhoMax * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    do {
        printf("Menu:\n");
        printf("1. Adicionar novo aluno\n");
        printf("2. Listar alunos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAluno(alunos, &contador, tamanhoMax);
                break;
            case 2:
                listarAlunos(alunos, contador);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);

    // Liberando a memória alocada
    free(alunos);

    return 0;
}
