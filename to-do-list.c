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

void saveItemInList(){
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
}

void readList(){
    fptr = fopen("list.txt", "r");

    if(fptr == NULL){
        printf("Voce deve inserir elementos em sua lista antes de lista-los.\n");
        return;
    }
    if(list->done == NULL){
        printf("Os itens que nao foram marcados como feitos, sao: \n");
        printf("%s",list->itemName);
    }else{
        printf("Itens concluidos: \n");
        printf("%s", list->itemName);
    }
    while(fgets(MAX_ITENS, sizeof(MAX_ITENS), fptr)){
        printf("%s", MAX_ITENS);
    }
    fclose(fptr);

}
int main(){
    return 0;
}
