#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node* createNewNode(){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    assert(newNode != NULL);

    return newNode;
}

void readListFromFile(struct Node *headNode, FILE *readFile){
    assert(readFile != NULL);
    assert(headNode != NULL);


    fscanf(readFile, "%d", &(headNode->value));

    struct Node *endNode = headNode;

    while(!feof(readFile)){
        struct Node* currentNode = createNewNode();

        currentNode->next = NULL;
        fscanf(readFile, "%d", &(currentNode->value));
        endNode->next = currentNode;

        endNode = currentNode;
    }
}

void insertNode(struct Node **currentNode, int valueAfter, int number){
    assert((*currentNode) != NULL);


    if((*currentNode)->next == NULL){
        printf("Toks sekos narys neegzistuoja.\n");
        return;
    }else if((*currentNode)->next->value == valueAfter){
        struct Node *insertedNode = createNewNode();

        insertedNode->next = (*currentNode)->next;
        insertedNode->value = number;
        (*currentNode)->next = insertedNode;

        printf("Reiksme iterpta.\n");
        return;
    }else if((*currentNode)->value == valueAfter){
        struct Node *newNode = createNewNode();

        newNode->value = number;
        newNode->next = (*currentNode);
        (*currentNode) = newNode;

        printf("Reiksme iterpta.\n");
        return;
    }else{
        insertNode(&((*currentNode)->next), valueAfter, number);
        return;
    }
    printf("RRR\n");
}

void printList(struct Node *currentNode, int listIsCreated){
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

void freeAll(struct Node **currentNode){
    assert((*currentNode) != NULL);


    if((*currentNode)->next == NULL){
        free((*currentNode));
        return;
    }

    struct Node *nextNode = (*currentNode)->next;

    freeAll(&nextNode);

    free((*currentNode));

    return;
}
