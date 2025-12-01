#include <stdio.h>
#include <string.h>

// ============================================================================
// 1. Definição dos limitadores utilizados nos campos do struct
// ============================================================================
#define MAX_TERRITORIOS 5 // Máximo de 5 territórios
#define MAX_NOME 30       // Máximo de 30 caracteres no nome
#define MAX_COR 15        // Máximo de 15 caracteres na cor

// ============================================================================
// 2. DEFINIÇÃO DA STRUCT
// Território que serão usados no jogo
// ============================================================================
typedef struct
{
    char nome[MAX_NOME]; // Nome do território, max 30 chars
    char cor[MAX_COR];  // Ex: "Azul", "Verde" max 15 chars
    int tropas;    // Quantidade de exércitos
} Territorio;

int main()
{
    // ========================================================================
    // 3. DECLARAÇÃO DO VETOR
    // Criamos uma lista (array) que contém 5 "fichas" do tipo Territorio.
    // ========================================================================
    Territorio lista[MAX_TERRITORIOS];
    int i; // Variável para controlar os laços (loops)

    printf("=== SISTEMA DE CADASTRO WAR ===\n");
    printf("Por favor, cadastre 5 territorios.\n");
    printf("Dica: Use nomes sem espaco (Ex: Brasil, China)\n");

    // ========================================================================
    // 4. ENTRADA DE DADOS (Loop FOR)
    // O laço roda 5 vezes (de 0 a 4) para preencher cada posição do vetor.
    // ========================================================================
    for (i = 0; i < 5; i++)
    {
        printf("\n--- Territorio %d ---\n", i + 1);

        // 1. Lê o Nome do Território
        printf("Nome: ");
        // fgets lê a linha inteira até você apertar Enter
        fgets(lista[i].nome, 30, stdin);
        // O fgets pega o "Enter" (\n) junto. Esse comando abaixo remove o Enter:
        lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;

        // 2. Lendo a Cor
        printf("Cor do exercito: ");
        fgets(lista[i].cor, 10, stdin);
        lista[i].cor[strcspn(lista[i].cor, "\n")] = 0; // Remove o Enter

        // 3. Lendo as Tropas
        printf("Número de tropas: ");
        scanf("%d", &lista[i].tropas);

        // Limpar o buffer para não dar problema nos inputs em nomes como "América do Sul, América do Norte..."
        while (getchar() != '\n');
    }

    // ========================================================================
    // 5. EXIBIÇÃO DOS DADOS
    // Percorremos o vetor novamente para mostrar o que foi salvo.
    // ========================================================================
    printf("\n\n=== MAPA ATUALIZADO ===\n");
    printf("--------------------------------------------------\n");
    // Cabeçalho da tabela com tabulações (\t) para alinhar
    printf("TERRITORIO\t\tCOR\t\tTROPAS\n");
    printf("--------------------------------------------------\n");

    for (i = 0; i < 5; i++)
    {
        // %s = string, %d = inteiro, \t = tabulação
        printf("%s\t\t%s\t\t%d\n", lista[i].nome, lista[i].cor, lista[i].tropas);
    }
    printf("--------------------------------------------------\n");

    return 0;
}