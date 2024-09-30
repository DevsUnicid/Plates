#ifndef _UTIL_H
#define _UTIL_H

#include<string.h>
#include<ctype.h>


struct sPrato *buscaUltimoPrato(struct sPrato *cardapio) {
    struct sPrato *pratoAux;

    /* Cardápio vazio */
    if (cardapio == NULL) return NULL;

    /* Cardápio com 1 elemento */
    if (cardapio->proximo == NULL || cardapio->pratoId == cardapio->proximo->pratoId) return cardapio;

    pratoAux = cardapio;
    while (pratoAux->posicao < pratoAux->proximo->posicao) {
        pratoAux = pratoAux->proximo;
    }

    return pratoAux;
}

char *buscaCampo(char* line, int num) {
    char* token;

    for (token = strtok(line, ","); token && *token; token = strtok(NULL, ",\n")) {
        if (!--num)
            return token;
    }
    
    return NULL;
}

char *leftTrim(char *s) {
    while(isspace(*s)) s++;
    return s;
}

char *rightTrim(char *s) {
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char *trim(char *s) {
    return rightTrim(leftTrim(s)); 
}

Sprato *deepCopyPrato(Sprato *pratoAlvo) {
    Sprato *pNovoPrato = (Sprato *)malloc(sizeof(Sprato));

    strcpy(pNovoPrato->nome, pratoAlvo->nome);
    pNovoPrato->valor = pratoAlvo->valor;
    pNovoPrato->pratoId = pratoAlvo->pratoId;
    pNovoPrato->proximo = NULL;
    pNovoPrato->anterior = NULL;

    return pNovoPrato;
}

int contaPratos(Sprato *cardapio) {
    Sprato *aux = cardapio;
    int contador = 1;

    while(aux->posicao < aux->proximo->posicao) {
        aux = aux->proximo;
        contador++;
    }

    return contador;
}

#endif