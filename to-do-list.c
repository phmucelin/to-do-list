#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITENS 100
FILE* fptr;
typedef struct todoList
{
    char itemName[100];
    int priority;
    int done;
}item;

item list[MAX_ITENS];
int totalItens = 0;
struct todoList items, *ptr_items;


void addItemList(){
    if(totalItens >= MAX_ITENS){
        printf("Voce ja atingiu o numero maximo de tarefas");
        return;
    }
    ptr_items = &list[totalItens];

    printf("Digite o nome da tarefa: ");
    scanf(" %[^\n]", list[totalItens].itemName);

    printf("Qual a prioridade deste item 1-5? ");
    scanf("%d", &list[totalItens].priority);

    printf("Este item ja foi realizado? 0 NAO, 1 SIM");
    scanf("%d", &list[totalItens].done);

    totalItens++;
}

void saveANDload(){
    fptr = fopen("list.txt", "w");
    if(fptr == NULL){
        printf("Sua lista esta vazia, voce deve adicionar itens antes de executar!");
        addItemList();
    }
    for(int i = 0; i < totalItens ; i++){
        fprintf(fptr, "%s, %d",
            list[i].itemName,
            list[i].priority
        );
    }
    fclose(fptr);
    printf("Voce salvou suas tarefas na sua lista!\n");
}

void removeItemList(){
    char excludeByName[100];
    printf("Qual o nome da tarefa que voce deseja excluir? ");
    scanf(" %[^\n]", excludeByName);
    for(int i = 0; i < totalItens; i++ ){
        if(strcmp(excludeByName, list[i].itemName) == 0){
            int UserConfirmationDel = 0;
            printf("Voce tem certeza de que deseja excluir essa tarefa? 0 para NAO 1 para SIM");
            scanf("%d", &UserConfirmationDel);
            switch (UserConfirmationDel)
            {
            case 1:
               /* list[i].itemName = "";  TEM ERROS NESSA FUNCAO, IREI ALTERAR EM CASA!*/
                // list[i].priority = NULL;
                // list[i].done = NULL;
                break;
            case 0:
                printf("Finalizando a aplicacao, nenhuma alteracao foi efetuada!\n");
                break;
            default:
                break;
            }

        }
    }
}

void check(){
    char filterByName[100];
    printf("Qual o nome da tarefa que voce deseja marcar como concluida? ");
    scanf(" %[^\n]", filterByName);
    for(int i=0; i<totalItens; i++){
        /*STRCAMP compara duas strings e verifica qual delas e maior, como aqui eu do igual zero, entao confirmo que elas sao do mesmo tamanho*/
        if(strcmp(filterByName, list[i].itemName) == 0){
            int UserConfirmation = 0;
            printf("Irei alterar a tarefa para CONCLUIDA, voce confirma? 1 para SIM 0 para NAO: ");
            scanf("%d", &UserConfirmation);
            switch (UserConfirmation)
            {
            case 1:
                list[i].done = 1;
                printf("Tarefa '%s' marcada como concluida!\n", list[i].itemName);
                saveANDload();
                break;
            case 0:
                printf("Finalizando a aplicacao, nenhum dado foi alterado!");
                break;
            default:
                printf("ERROR! Voce esta inserindo valores que nao correspondem a nenhuma opcao!");
                break;
            }
        }
    }    
}
/*Sei que tem um pequeno erro de logica nessa funcao, o que torna ela meio inutil, irei arrumar*/
void readList(){
    int escolha = 0;
    fptr = fopen("list.txt", "r");

    if(fptr == NULL){
        printf("Voce deve inserir elementos em sua lista antes de lista-los.\n");
        return;
    }
    printf("Voce deseja filtrar a sua pesquisa? 0 SIM | 1 NAO: ");
    scanf("%d", &escolha);
    if(escolha==0){
        int concluedorno = 0;
        printf("Voce deseja filtrar por CONCLUIDAS ou por NAO CONCLUIDAS: 0 CONCLUIDAS 1 NAO CONCLUIDAS");
        scanf("%d", &concluedorno);
        switch (concluedorno)
        {
        case 1:
            if(list->done = 0){
            printf("Os itens que nao foram marcados como feitos, sao: \n");
            printf("%s",list->itemName);
            }
            break;
        case 2:
            printf("Itens concluidos: \n");
            printf("%s", list->itemName);
            break;
        default:
            printf("ERROR");
            break;
            
        }
    }else{
        char linha[100];
        while(fgets(linha, sizeof(linha), fptr)){
            printf(" %s", linha);
        }
    }
    fclose(fptr);

}
int main(){
    int escolhas = 0;
    while(escolhas != 6){
    printf("\n---------------------BEM-VINDO---------------------\n");
    printf("Essa eh uma aplicacao totalmente feita em C, para organizar uma to-do-list!\n");
    printf("1 --> Adicionar uma Tarefa\n");
    printf("2 --> Remover uma Tarefa\n");
    printf("3 --> Visualizar Tarefas\n");
    printf("4 --> Marcar como concluida\n");
    printf("5 --> Salvar e carregar\n");
    printf("6 --> Sair\n");
    printf("Qual e a sua escolha? ");
    scanf("%d", &escolhas);
        switch (escolhas)
        {
        case 1:
            addItemList();
            
            break;
        case 2:
            removeItemList();
            break;

        case 3:
            readList();
            break;

        case 4:
            check();
            break;

        case 5:
            saveANDload();
            break;
        default:
            break;
        }
    }      

    return 0;
}
