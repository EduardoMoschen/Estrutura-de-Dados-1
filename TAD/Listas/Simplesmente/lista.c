#include "lista.h"

Lista *createNode(int valor){
	Lista *novoNo = (Lista*)calloc(1, sizeof(Lista));

	if(novoNo == NULL){
		printf("Erro de alocacao\n");
		exit(1);
	}
	novoNo -> dado = valor;
	return novoNo;
}

Lista *insertAtBeginning(Lista *L, int valor){
	Lista *novoNo = createNode(valor);

	if(L == NULL)
		L = novoNo;
	else{
		novoNo -> proximo = L;
		L = novoNo;
	}
	return L;
}

Lista *insertAtEnd(Lista *L, int valor){
	Lista *novoNo = createNode(valor);
	Lista *auxiliar = L;

	if(L == NULL)
		L = novoNo;
	else{
		while(auxiliar -> proximo != NULL)
			auxiliar = auxiliar -> proximo;
		auxiliar -> proximo = novoNo;
	}
	return L;
}

Lista *insereOrdenado(Lista *L, int valor){
	Lista *novoNo = createNode(valor);
	Lista *auxiliar = L;
	Lista *anterior = NULL;

	if(L == NULL)
		L = novoNo;
	else{
		while(auxiliar != NULL && valor > auxiliar -> dado){
			anterior = auxiliar;
			auxiliar = auxiliar -> proximo;
		}
		if(anterior == NULL){
			novoNo -> proximo = auxiliar;
			L = novoNo;
		}else{
			novoNo -> proximo = auxiliar;
			anterior -> proximo = novoNo;
		}
	}
	return L;
}

Lista *ordenarLista(Lista *L1, Lista *L2){
	Lista *auxiliar = L2;
	Lista *L3 = NULL;

	if(L1 == NULL)
		return L2;
	if(L2 == NULL)
		return L1;

	while(auxiliar != NULL){
		L3 = insereOrdenado(L1, auxiliar -> dado);
		auxiliar = auxiliar -> proximo;
	}
	return L3;
}

Lista *removeFromBeginning(Lista *L){
	Lista *auxiliar = L;

	if(L == NULL)
		return NULL;
	else{
		L = auxiliar -> proximo;
		free(auxiliar);
		return L;
	}
}

Lista *removeFromEnd(Lista *L){
	Lista *auxiliar = L;
	Lista *anterior = NULL;

	if(L == NULL)
		return NULL;
	else{
		while(auxiliar -> proximo != NULL){
			anterior = auxiliar;
			auxiliar = auxiliar -> proximo;
		}
		if(anterior == NULL)
			L = NULL;
		else
			anterior -> proximo = NULL;

		free(auxiliar);
	}
	return L;
}

Lista *excluiValor(Lista *L, int valor){
	Lista *auxiliar = L;
	Lista *anterior = NULL;

	if(L == NULL)
		return NULL;
	else{
		while(auxiliar != NULL && valor != auxiliar -> dado){
			anterior = auxiliar;
			auxiliar = auxiliar -> proximo;
		}
		if(anterior == NULL)
			L = auxiliar -> proximo;
		else
			anterior -> proximo = auxiliar -> proximo;
		free(auxiliar);
		return L;
	}
}

Lista *searchValue(Lista *L, int valor){
	Lista *auxiliar = L;

	if(L == NULL){
		printf("Lista vazia\n");
		return NULL;
	}else{
		while(auxiliar != NULL){
			if(valor == auxiliar -> dado){
				printf("Elemento encontrado\n");
				break;
			}
			if(auxiliar -> proximo == NULL)
				printf("Elemento nao encontrado\n");
			
			auxiliar = auxiliar -> proximo;
		}
		return auxiliar;
	}
}

void printList(Lista *L){
	Lista *auxiliar = L;

	if(L == NULL)
		printf("Lista vazia\n");
	else{
		while(auxiliar != NULL){
			printf("%d\n", auxiliar -> dado);
			auxiliar = auxiliar -> proximo;
		}
	}
}