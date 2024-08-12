#ifndef STRUCTPRATO_H
#define STRUCTPRATO_H

typedef struct sPrato {
    int pratoId;
    char nome[50];
    float valor;
    int posicao;
    struct sPrato *proximo;
    struct sPrato *anterior;
} Sprato;

#endif