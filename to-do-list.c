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

    printf("Qual a prioridade deste item? ");
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
    /*Pesquisar como remover item de uma lista vindo de um struct*/
    /*Descobri talvez uma alternativa, alterando os valores para NULL, porem preciso ter certeza de como filtrar */
}

void check(){
    ptr_items = &list[totalItens];
    fptr = open("list.txt", "w");
    if(fptr==NULL){
        printf("Error! Voce nao possui itens em sua lista, por favor adicione!");
        saveItemInList();
    }
    char filterByName[100];
    printf("Qual o nome da tarefa que voce deseja marcar como concluida? ");
    scanf(" %[^\n]", filterByName);
    if(filterByName == items.itemName){
        int UserConfirmation = 0;
        printf("Irei alterar a tarefa para CONCLUIDA, voce confirma? 1 para SIM 0 para NAO: ");
        scanf("%d", &UserConfirmation);
        switch (UserConfirmation)
        {
        case 1:
            items.done = 1;
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

void readList(){
    int escolha = 0;
    fptr = fopen("list.txt", "r");

    if(fptr == NULL){
        printf("Voce deve inserir elementos em sua lista antes de lista-los.\n");
        return;
    }
    printf("Voce deseja filtrar a sua pesquisa? 0 SIM 1 NAO: ");
    scanf("%d", &escolha);
    if(escolha==1){
        int concluedorno = 0;
        printf("Voce deseja filtrar por CONCLUIDAS ou por NAO CONCLUIDAS: 0 CONCLUIDAS 1 NAO CONCLUIDAS");
        scanf("%d", &concluedorno);
        switch (concluedorno)
        {
        case 1:
            if(list->done == NULL){
            printf("Os itens que nao foram marcados como feitos, sao: \n");
            printf("%s",list->itemName);
            break;
        case 2:
            printf("Itens concluidos: \n");
            printf("%s", list->itemName);
            break;
        default:
            printf("Voce esta inserindo um valor invalido.");
            break;
        }
            
        }
    }else{
        while(fgets(MAX_ITENS, sizeof(MAX_ITENS), fptr)){
            printf("%s", MAX_ITENS);
        }
    }
    fclose(fptr);

}
int main(){
    return 0;
}
