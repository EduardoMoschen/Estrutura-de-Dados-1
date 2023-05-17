#include "lista.h"

int main(){
    Lista *head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    printList(head);

    free(head);

    return 0;
}