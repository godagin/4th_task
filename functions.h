#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct Node{
    int value;
    struct Node *next;
};

struct Node* createNewNode();
void readListFromFile(struct Node *headNode, FILE *readFile);
void insertNode(struct Node **currentNode, int valueAfter, int number);
void printList(struct Node *currentNode, int listIsCreated);
void freeAll(struct Node **currentNode);


#endif
