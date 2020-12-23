#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct Node{
    int value;
    struct Node *next;
}NODE;

NODE* createNewNode();
void readListFromFile(NODE *headNode, FILE *readFile, int *listIsCreated);
void insertNode(NODE **currentNode, int valueAfter, int number, int oneElementList);
void printList(NODE *currentNode, int listIsCreated);
void freeAll(NODE **currentNode);


#endif
