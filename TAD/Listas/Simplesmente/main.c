#include "lista.h"

int main(){
	Lista *Inicio = NULL, *Final = NULL, *Ordenada = NULL;

	Inicio = insertAtBeginning(Inicio, 3);
	Inicio = insertAtBeginning(Inicio, 2);
	Inicio = insertAtBeginning(Inicio, 1);
	Inicio = insertAtBeginning(Inicio, 0);
	printList(Inicio);
	printf("\n");

	Inicio = removeFromBeginning(Inicio);
	printList(Inicio);

	printf("\n");

	Final = insertAtEnd(Final, 0);
	Final = insertAtEnd(Final, 1);
	Final = insertAtEnd(Final, 2);
	Final = insertAtEnd(Final, 3);
	printList(Final);
	printf("\n");

	Final = removeFromEnd(Final);
	printList(Final);

	printf("\n");

	Inicio = excluiValor(Inicio, 2);
	printList(Inicio);

	printf("\n");

	Ordenada = insereOrdenado(Ordenada, 7);
	Ordenada = insereOrdenado(Ordenada, 2);
	Ordenada = insereOrdenado(Ordenada, 4);
	Ordenada = insereOrdenado(Ordenada, 19);
	Ordenada = insereOrdenado(Ordenada, 1);
	printList(Ordenada);

	Ordenada = searchValue(Ordenada, 2);

	free(Inicio);
	free(Final);
	free(Ordenada);

	return 0;
}