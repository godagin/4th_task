#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <assert.h>

int main(){
    int number;
    int listIsCreated = 0;
    int oneElementList = 0;
    NODE *headNode = createNewNode();
    (*headNode).next = NULL;

    ///vieno elemento sarasas
    FILE *readFile = NULL;
    FILE *writeFile = NULL;

    writeFile = fopen("testdata.txt", "w");
    if(writeFile != NULL){
        fprintf(writeFile, "%d", 1);
        fclose(writeFile);
    }

    readFile = fopen("testdata.txt", "r");
    if(readFile != NULL){
        readListFromFile(headNode, readFile, &listIsCreated);
        fclose(readFile);
    }else{
        printf("Negalima atidaryti failo.\n");
        return 0;
    }
    ///******************************************

    ///spausdinimas
    //printList(headNode, listIsCreated);
    ///******************************************

    ///iterpimas
    if(listIsCreated == 1){
        if(headNode->next == NULL){
            oneElementList = 1;
        }
        //iterpti 5 pries 1 => patikrina ar iterpia kai sarase tik 1 elementas
        int valueAfterNew = 1;
        int newValue = 5;
        insertNode(&headNode, valueAfterNew, newValue, oneElementList);
        //iterpti 10 pries 5 => patikrina, ar iterpia i pradzia
        valueAfterNew = 5;
        newValue = 10;
        insertNode(&headNode, valueAfterNew, newValue, oneElementList);
        //iterpti 2 pries 1 => patikrina ar iterpia pries paskutini (arba per viduri)
        valueAfterNew = 1;
        newValue = 2;
        insertNode(&headNode, valueAfterNew, newValue, oneElementList);

        assert(headNode->value == 10);
        assert(headNode->next->value == 5);
        assert(headNode->next->next->value == 2);
        assert(headNode->next->next->next->value == 1);
    }else{
        printf("Sarasas dar nebuvo sukurtas.\n");
    }
    ///******************************************

    ///atminties atlaisvinimas
    freeAll(&headNode);
    ///******************************************
    return 0;
}
