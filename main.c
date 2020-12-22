#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){
    int number;
    int command;
    int listIsCreated = 0;
    struct Node *headNode = createNewNode();
    (*headNode).next = NULL;

    printf("Meniu:\n");
    printf("Iveskite 0, jei norite sukurti sarasa is faile esanciu duomenu.\n");
    printf("Iveskite 1, jei norite spausdinti sarasa.\n");
    printf("Iveskite 2, jei norite atlikti iterpima.\n");
    printf("Iveskite 3, jei norite baigti darba.\n");

    do{
        scanf("%d", &command);

        if(command == 0){
            FILE *readFile = NULL;
            readFile = fopen("data.txt", "r");

            if(readFile != NULL){
                readListFromFile(headNode, readFile);
            }else{
                printf("Negalima atidaryti failo.\n");
                return 0;
            }
            listIsCreated = 1;
            printf("Sarasas sukurtas.\n");
        }else if(command == 1){
            printList(headNode, listIsCreated);
        }else if(command == 2){
            if(listIsCreated != 0){
                int valueAfterNew;
                int newValue;

                printf("Reiksme, pries kuria iterpti: ");
                while(scanf("%d", &valueAfterNew) != 1){
                    printf("Netinkamo formato ivestis. Prasome ivesti sveika skaiciu:\n");
                    while(getchar() != '\n');
                }
                printf("Reiksme, kuria norite iterpti: ");
                while(scanf("%d", &newValue) != 1){
                    printf("Netinkamo formato ivestis. Prasome ivesti sveika skaiciu:\n");
                    while(getchar() != '\n');
                }

                insertNode(&headNode, valueAfterNew, newValue);
            }else{
                printf("Sarasas dar nebuvo sukurtas.\n");
            }

        }else if(command == 3){
            printf("Darbo pabaiga.");
        }else{
            printf("Ivesta netinkama komanda. Bandykite is naujo:\n");
        }
    }while(command != 3);

    freeAll(&headNode);

    return 0;
}
