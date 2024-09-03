#include <stdio.h>

// Função para calcular a soma da PA
void calcularPA(int *partida, int razao, int iteracoes) {
    int soma = 0;
    for (int i = 0; i <= iteracoes; i++) {
        soma += *partida + i * razao;
    }
    *partida = soma;
}

// Função principal que solicita os dados ao usuário e chama a função de cálculo da PA
void solicitarDados() {
    int partida;
    int razao, iteracoes;

    printf("Digite o número de partida: ");
    scanf("%d", &partida);

    printf("Digite a razão: ");
    scanf("%d", &razao);

    printf("Digite o número de iterações: ");
    scanf("%d", &iteracoes);

    calcularPA(&partida, razao, iteracoes);

    printf("O somatório da PA é: %d\n", partida);
}

int main() {
    solicitarDados();
    return 0;
}
