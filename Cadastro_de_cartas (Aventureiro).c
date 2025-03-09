#include <stdio.h>

#define MAX_CARTAS 2 

struct Carta {
    char estado[2];  
    int id;
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

int main()
{
    struct Carta cartas[MAX_CARTAS];  

    printf("OLA, BEM VINDO AO CADASTRO DE CARTAS DO SUPER TRUNFO!\n\n");

    for (int i = 0; i < MAX_CARTAS; i++) {
        printf("[CARTA #%d]!\n", i + 1);

        printf("Por favor, insira uma letra referente a oito estados (entre A - H): ");
        scanf("%1s", cartas[i].estado);  

        printf("Insira o ID desta carta (1, 2, 3, 4): ");
        scanf("%d", &cartas[i].id);
        getchar(); 

        printf("Insira o nome da cidade: ");
        scanf("%49s", cartas[i].cidade);

        printf("Quantos habitantes moram em %s? ", cartas[i].cidade);
        scanf("%d", &cartas[i].populacao);

        printf("Qual a área da cidade de %s? (em km²): ", cartas[i].cidade);
        scanf("%f", &cartas[i].area);

        printf("Qual o PIB desta cidade? ");
        scanf("%f", &cartas[i].pib);

        printf("Quantos pontos turísticos existem em %s? ", cartas[i].cidade);
        scanf("%d", &cartas[i].pontos_turisticos);

    // aqui eu acabei tendo que pesquisar a respeito do "if" e "else", pois nâo estava conseguindo fazer sem!

        if (cartas[i].area > 0) {
            cartas[i].densidade_populacional = cartas[i].populacao / cartas[i].area;
        } else {
            cartas[i].densidade_populacional = 0;
        }

        if (cartas[i].populacao > 0) {
            cartas[i].pib_per_capita = cartas[i].pib / cartas[i].populacao;
        } else {
            cartas[i].pib_per_capita = 0;
        }

        printf("\n");
    }

    printf("\n=========[CARTAS CADASTRADAS]=========\n");
    for (int i = 0; i < MAX_CARTAS; i++) {
        printf("\n[CARTA #%d]\n", i + 1);
        printf("ID da cidade = %s%02d \n", cartas[i].estado, cartas[i].id);
        printf("Nome da cidade = %s \n", cartas[i].cidade);
        printf("População = %d habitantes\n", cartas[i].populacao);
        printf("Área = %.1f km²\n", cartas[i].area);
        printf("PIB = %.2f\n", cartas[i].pib);
        printf("Pontos turísticos = %d\n", cartas[i].pontos_turisticos);
        printf("Densidade Populacional = %.2f hab/km²\n", cartas[i].densidade_populacional);
        printf("PIB Per Capita = %.2f\n", cartas[i].pib_per_capita);
    }

    return 0;
}
