#include "lista.h"

Lista *createNode(int value){
    Lista *newNode = (Lista*)calloc(1, sizeof(Lista));
    if(newNode == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }
    newNode -> value = value;
    return newNode;
}

Lista *insertAtBeginning(Lista *head, int value){
    Lista *newNode = createNode(value);

    if(head == NULL)
        head = newNode;
    else{
        newNode -> next = head;
        head = newNode;
    }
    
    return newNode;
}

void printList(Lista *head){
    Lista *currentNode = head;
    if(head == NULL){
        printf("Empty List\n");
        return;
    }
    while(currentNode != NULL){
        printf("%d ", currentNode -> value);
        currentNode = currentNode -> next;
    }
    printf("\n");
    
}