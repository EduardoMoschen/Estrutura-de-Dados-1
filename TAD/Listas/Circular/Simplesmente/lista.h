#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int value;
	struct lista *next;
}Lista;

Lista *createNode(int value);
Lista *insertAtBeginning(Lista *head, int value);
void printList(Lista *head);

#endif