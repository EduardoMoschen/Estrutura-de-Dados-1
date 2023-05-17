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

	novoNo -> proximo = L;
	
	if(L != NULL)
		L -> anterior = novoNo;
	
	return novoNo;
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
		novoNo -> anterior = auxiliar;
	}
	return L;
}

Lista *removeFromBeginning(Lista *L){
	Lista *auxiliar = L;

	if(L == NULL)
		return NULL;
	else{
		L = auxiliar -> proximo;

		if(L != NULL)
			L -> anterior = NULL;
		
		free(auxiliar);
	}
	return L;
}

Lista *removeFromEnd(Lista *L){
	Lista *auxiliar = L;

	if(L == NULL)
		return NULL;
	else{
		while(auxiliar -> proximo != NULL)
			auxiliar = auxiliar -> proximo;
		
		if(auxiliar -> anterior == NULL)
			L = NULL;
		else
			auxiliar -> anterior -> proximo = NULL;
		
		free(auxiliar);
	}
	return L;
}

Lista *value(Lista *L, int valor){ // USADA PARA INSERIR ORDENADO E EXCLUIR ELEMENTO ESPECÍFICO
	Lista *auxiliar = L;

    if(L == NULL)
        return NULL;
	else{
		while(auxiliar != NULL && valor > auxiliar -> dado){
			if(auxiliar -> proximo == NULL)
				break;
			auxiliar = auxiliar -> proximo;
		}
	}
    return auxiliar;
}

Lista *insereOrdenado(Lista *L, int valor){
	Lista *novoNo = createNode(valor);
	Lista *auxiliar = value(L, valor);

	if(auxiliar == NULL)
        L = novoNo;
    else{
        if(auxiliar -> dado < valor){
           auxiliar -> proximo = novoNo;
		   novoNo -> anterior = auxiliar;
        }else{
            novoNo -> proximo = auxiliar;
            if(auxiliar -> anterior == NULL)
                L = novoNo;
            else{
                auxiliar -> anterior -> proximo = novoNo;
                novoNo -> anterior = auxiliar -> anterior;
            }
            auxiliar -> anterior = novoNo;
        }
    }
    return L;
}

Lista *excluiElementoEspecifico(Lista *L, int valor){
	Lista *auxiliar = value(L, valor);

	if(auxiliar == NULL || valor != auxiliar -> dado)
		printf("Elemento nao encontrado\n");
	else{
		if(auxiliar != NULL){
			if(auxiliar -> anterior == NULL)
				L = auxiliar -> proximo;
			else
				auxiliar -> anterior -> proximo = auxiliar -> proximo;

			if(auxiliar -> proximo != NULL)
				auxiliar -> proximo -> anterior = auxiliar -> anterior;
			
			free(auxiliar);
		}
	}
	return L;
}

Lista *searchValue(Lista *L, int valor){
	Lista *auxiliar = L;

	if(L == NULL)
		return NULL;
	else{
		while(auxiliar != NULL){
			if(valor == auxiliar -> dado){
				printf("Elemento encontrado\n");
				break;
			}

			if(auxiliar -> proximo == NULL)
				printf("Elemento nao encontrado\n");
				
			auxiliar = auxiliar -> proximo;
		}
	}
	return auxiliar;
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