#ifndef MANIPULALISTA_H
#define MANIPULALISTA_H

#include<stdlib.h>
#include<stdio.h>

#include "structPrato.h"
#include "util.h"

void adicionaPratoNoCardapio(Sprato *novoPrato, Sprato *cardapio) 
{
    struct sPrato *ultimo = buscaUltimoPrato(cardapio);

    if (ultimo == NULL) 
    {
        cardapio = novoPrato;
        novoPrato->posicao = 1;
        novoPrato->proximo = novoPrato;
        novoPrato->anterior = novoPrato;
    }
    else if(ultimo->proximo == NULL)
    {
        // atualizando os 'próximos'
        ultimo->proximo = novoPrato;
        novoPrato->proximo = ultimo;
        
        // atualizando os 'anteriores'
        ultimo->anterior = novoPrato;
        novoPrato->anterior = ultimo;

        ultimo->posicao = 1;
        novoPrato->posicao = 2;
    }
    else 
    {
        // atualizando os 'próximos'
        novoPrato->proximo = ultimo->proximo;
        ultimo-> proximo = novoPrato;

        // atualizando os 'anteriores'
        novoPrato->anterior = ultimo;


        novoPrato->posicao = ultimo->posicao + 1;
    }
}

Sprato *alocaPratoFromChar(char infoPrato[], int numeroCarta) 
{
    struct sPrato *pNovoPrato;

    char *nome, *temp;
    int pratoId;
    float valor;

    pratoId = rand() % 10;

    temp = strdup(infoPrato);
    nome = trim(buscaCampo(temp, 1));

    temp = strdup(infoPrato);
    valor = atof(trim(buscaCampo(temp, 2)));

    pNovoPrato = (struct sPrato *)malloc(sizeof(struct sPrato));
    strcpy(pNovoPrato->nome, nome);
    pNovoPrato->valor = valor;
    pNovoPrato->pratoId = pratoId;
    pNovoPrato->proximo = NULL;
    pNovoPrato->anterior = NULL;

    return pNovoPrato;
}

// Sprato *listaDeCardsPorRaridade(Sprato *cardCardaprio, char raridade) {
//     int tamanhoLista = 1;
//     Sprato *aux, *auxUltimo, *lista = NULL;

//     while (cardCardaprio->proximo != NULL) {
//         if (cardCardaprio->raridade == raridade) {
//             aux = deepCopyPrato(cardCardaprio);

//             if (lista == NULL) {
//                 lista = aux;
//                 auxUltimo = aux;
//             }
//             else {
//                 auxUltimo->proximo = aux;
//                 auxUltimo = auxUltimo->proximo;
//             }
//             tamanhoLista++;
//         }
//         cardCardaprio = cardCardaprio->proximo;
//     }
//     auxUltimo->proximo = NULL;

//     return lista;
// }

void apresentainfoPrato(Sprato card) {
    int cont;
    char *materia;

    printf("\n# %d - %s           R$ %.2f", card.pratoId, card.nome, card.valor);
}

int imprimeCardapio(Sprato *cardapio, bool simplificado) {
    struct sPrato *pratoAtual = cardapio;

    if (cardapio == NULL) 
        printf("\n\n\t NENHUMA PRATO FOI CADASTRADO NO CARDAPIO");
    
    // Imprime primeira carta
    apresentainfoPrato(*pratoAtual);

    while(pratoAtual->posicao < pratoAtual->proximo->posicao) {
        pratoAtual = pratoAtual->proximo;
        
        // Imprime demais cartas
        apresentainfoPrato(*pratoAtual);
    }
}

void escolheCardsAleatorio(Sprato *lista, int qtd, Sprato **booster) {
    int cardEscolhido, contaCards = 1;
    Sprato *auxUltimo, *aux = lista;

    while(contaCards <= qtd) {
        cardEscolhido = rand() % 10 + 1;

        for (int i = 0; i < cardEscolhido ; i++) {
            aux = aux->proximo;
            if (aux == NULL) aux = lista;
        }

        if (*booster == NULL) *booster = deepCopyPrato(aux);
        else {
            auxUltimo = buscaUltimoPrato(*booster);
            auxUltimo->proximo = deepCopyPrato(aux);
        }
        contaCards++;
    }
}

#endif