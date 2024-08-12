#ifndef __BUSCASEQUENCIAL_H
#define __BUSCASEQUENCIAL_H

#include <stdlib.h>

#include "structPrato.h"
#include "util.h"

Sprato *buscaPratoPorId(Sprato *prato, int pratoId) {
    while (prato != NULL) {
        if (prato->pratoId == pratoId)
            return deepCopyPrato(prato);
        prato = prato->proximo;
    }
    return NULL;
}

Sprato *buscaPratoPorNome(Sprato *prato, char nomeCard[]) {
    Sprato *pratoAux = prato;

    while (pratoAux != NULL) {
        if (strcmp(pratoAux->nome, nomeCard) == 0) 
            return deepCopyPrato(pratoAux);
        pratoAux = pratoAux->proximo;
    }
    return NULL;
}

Sprato *buscaPratoPorPreco(Sprato *prato, float preco) {
    // Implementar função
    return NULL;
}

#endif