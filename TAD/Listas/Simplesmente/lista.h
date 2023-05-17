#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int dado;
	struct lista *proximo;
}Lista;

Lista *createNode(int valor);
Lista *insertAtBeginning(Lista *L, int valor);
Lista *insertAtEnd(Lista *L, int valor);
Lista *insereOrdenado(Lista *L, int valor);
Lista *ordenarLista(Lista *L1, Lista *L2);
Lista *removeFromBeginning(Lista *L);
Lista *removeFromEnd(Lista *L);
Lista *searchValue(Lista *L, int valor);
Lista *excluiValor(Lista *L, int valor);
void printList(Lista *L);

#endif