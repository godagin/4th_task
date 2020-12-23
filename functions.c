#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
    int value;
    struct Node *next;
}NODE;

NODE* createNewNode(){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));

    return newNode;
}

void readListFromFile(NODE *headNode, FILE *readFile, int *listIsCreated){
    assert(readFile != NULL);
    assert(headNode != NULL);


    if(fscanf(readFile, "%d", &(headNode->value)) != 1){
        printf("Faile pateikti netinkami duomenys arba failas tuscias.\n");
        return;
    }

    NODE *endNode = headNode;

    while(!feof(readFile)){
        NODE* currentNode = createNewNode();

        currentNode->next = NULL;
        fscanf(readFile, "%d", &(currentNode->value));
        endNode->next = currentNode;

        endNode = currentNode;
    }
    *listIsCreated = 1;

    printf("Sarasas sukurtas.\n");
}

void insertNode(NODE **currentNode, int valueAfter, int number, int oneElementList){
    assert((*currentNode) != NULL);


    if(((*currentNode)->next == NULL) && (oneElementList == 0)){
        printf("Toks sekos narys neegzistuoja.\n");
        return;
    }else if((*currentNode)->value == valueAfter){
        NODE *newNode = createNewNode();

        newNode->value = number;
        newNode->next = (*currentNode);
        (*currentNode) = newNode;

        printf("Reiksme iterpta.\n");
        return;
    }else if((*currentNode)->next->value == valueAfter){
        NODE *insertedNode = createNewNode();

        insertedNode->next = (*currentNode)->next;
        insertedNode->value = number;
        (*currentNode)->next = insertedNode;

        printf("Reiksme iterpta.\n");
        return;
    }else{
        insertNode(&((*currentNode)->next), valueAfter, number, oneElementList);
        return;
    }
    printf("RRR\n");
}

void printList(NODE *currentNode, int listIsCreated){
    assert(currentNode != NULL);
    assert(listIsCreated <= 1);
    assert(listIsCreated >= 0);


    if(listIsCreated == 0){
        printf("Sarasas dar nebuvo sukurtas.\n");
        return;
    } else if(currentNode->next == NULL){
        printf("%d\n", currentNode->value);
        return;
    }else{
        printf("%d ", currentNode->value);
        printList(currentNode->next, listIsCreated);
        return;
    }
}

void freeAll(NODE **currentNode){
    assert((*currentNode) != NULL);


    if((*currentNode)->next == NULL){
        free((*currentNode));
        return;
    }

    NODE *nextNode = (*currentNode)->next;

    freeAll(&nextNode);

    free((*currentNode));

    return;
}
