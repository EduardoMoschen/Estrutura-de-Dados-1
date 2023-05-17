#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int dado;
	struct lista *proximo;
	struct lista *anterior;
}Lista;

Lista *createNode(int valor);
Lista *insertAtBeginning(Lista *L, int valor);
Lista *insertAtEnd(Lista *L, int valor);
Lista *removeFromBeginning(Lista *L);
Lista *removeFromEnd(Lista *L);
Lista *insereOrdenado(Lista *L, int valor);
Lista *value(Lista *L, int valor);
Lista *excluiElementoEspecifico(Lista *L, int valor);
Lista *searchValue(Lista *L, int valor);
void printList(Lista *L);

#endif