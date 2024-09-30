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

Sprato * criaNovoPrato(char *nomePrato, float valorPrato) {
    struct sPrato *novoPrato = (struct sPrato *) malloc(sizeof(struct sPrato));

    novoPrato = (struct sPrato *)malloc(sizeof(struct sPrato));
    strcpy(novoPrato->nome, nomePrato);
    novoPrato->valor = valorPrato;
    novoPrato->pratoId = rand() % 100;


    return novoPrato;
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
        
        // Imprime demais pratos
        apresentainfoPrato(*pratoAtual);
    }
    if (!simplificado) {printf("\n\n");}
}

Sprato * excluiPratoPorId(Sprato *cardapio, int pratoId) {
    struct sPrato *pratoAux = cardapio;

    while(pratoAux->pratoId != pratoId) {
        pratoAux = pratoAux->proximo;
    }

    if (pratoAux->pratoId == pratoId) {
        pratoAux->anterior->proximo = pratoAux->proximo;
        pratoAux->proximo->anterior = pratoAux->anterior;
        pratoAux->proximo = NULL;
        pratoAux->anterior = NULL;

        return pratoAux;
    }

    return NULL;
}

#endif