#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para malloc, calloc, free, rand, srand
#include <time.h>   // Essencial para time(NULL)

// ============================================================================
// Definição dos limitadores utilizados nos campos do struct
// ============================================================================
#define MAX_TERRITORIOS 5 // Máximo de 5 territórios
#define MAX_NOME 30       // Máximo de 30 caracteres no nome
#define MAX_COR 15        // Máximo de 15 caracteres na cor

// ============================================================================
// DEFINIÇÃO DA STRUCT
// Território que serão usados no jogo
// ============================================================================
typedef struct
{
    char nome[MAX_NOME]; // Nome do território, max 30 chars
    char cor[MAX_COR];   // Ex: "Azul", "Verde" max 15 chars
    int tropas;          // Quantidade de exércitos
} Territorio;

// ============================================================================
// DECLARAÇÃO DE FUNÇÕES
// Funções que serão utilizadas no jogo
// ============================================================================

void create_map(Territorio *lista);
void show_map(Territorio *lista);
void attack(Territorio *lista);

int main()
{
    Territorio *lista;

    lista = calloc(MAX_TERRITORIOS, sizeof(Territorio));

    if (lista == NULL)
    {
        printf("Memoria insuficiente! \n");
        return 1;
    }

    printf("=== JOGO WAR ===\n");
    printf("Por favor, cadastre 5 territorios.\n");

    create_map(lista);

    int opcao;
    do {
        show_map(lista);
        
        printf("\nO que deseja fazer?\n");
        printf("1 - Atacar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            attack(lista);
        }
    } while (opcao != 0);

    free(lista);
    printf("Memoria liberada. Jogo encerrado.\n");

    return 0;
}

void create_map(Territorio *lista)
{
    int i; // Variável para controlar os laços (loops)

    // ========================================================================
    // ENTRADA DE DADOS (Loop FOR)
    // O laço roda 5 vezes (de 0 a 4) para preencher cada posição do vetor.
    // ========================================================================
    for (i = 0; i < 5; i++)
    {
        printf("\n--- Territorio %d/%d ---\n", i + 1, MAX_TERRITORIOS);

        // 1. Lê o Nome do Território
        printf("Nome: ");
        fgets(lista[i].nome, 30, stdin);
        lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;

        // 2. Lendo a Cor
        printf("Cor do exercito: ");
        fgets(lista[i].cor, 10, stdin);
        lista[i].cor[strcspn(lista[i].cor, "\n")] = 0;

        // 3. Lendo as Tropas
        printf("Número de tropas: ");
        scanf("%d", &lista[i].tropas);

        while (getchar() != '\n' && !feof(stdin))
            ; // buffer limpo
    }

    show_map(lista);
}

void show_map(Territorio *lista)
{
    int i;
    // ========================================================================
    // EXIBIÇÃO DOS DADOS
    // Exibe os dados atualizados do mapa
    // ========================================================================
    printf("--------------------------------------------------\n");
    printf("\n\n=== MAPA DO MUNDO - ESTADO ATUAL ===\n");
    printf("--------------------------------------------------\n");

    for (i = 0; i < 5; i++)
    {
        printf("%d. %s (Exercito %s, Tropas: %d)\n", i + 1, lista[i].nome, lista[i].cor, lista[i].tropas);
    }
    printf("--------------------------------------------------\n");
}

void attack(Territorio *lista)
{
    int atacante, defensor;
    int dado_atk, dado_def;

    printf("\n ---- FASE DE ATAQUE ---- \n");
    printf("\n Quem ataca? (Digite um número de 1 a 5): ");
    scanf("%d", &atacante);

    printf("\n Quem defende? (Digite um número de 1 a 5): ");
    scanf("%d", &defensor);

    atacante--;
    defensor--;

    if(atacante < 0 || atacante >= MAX_TERRITORIOS || defensor < 0 || defensor >= MAX_TERRITORIOS) {
        printf("Territorios invalidos!");
        return;
    }

    dado_atk = (rand() % 6) + 1;
    dado_def = (rand() % 6) + 1;

    printf("\nPreparando o ataque...\n");
    printf("O atacante %s tirou: %d\n", lista[atacante].nome, dado_atk);
    printf("O defensor %s tirou: %d\n", lista[defensor].nome, dado_def);

    if (dado_atk >= dado_def) {
        printf("VITORIA DO ATACANTE!\n");
        lista[defensor].tropas--; // Tira tropa do defensor
        
        if(lista[defensor].tropas <= 0) {
            printf("O TERRITORIO FOI CONQUISTADO!\n");
            // Aqui você poderia mudar a cor do dono, etc.
        }
    } else {
        printf("VITORIA DA DEFESA!\n");
    }
    
    // Pausa dramática
    printf("Pressione Enter para continuar...");
    while (getchar() != '\n'); getchar();
}