#ifndef _MENU_H
#define _MENU_H

#include<stdlib.h>
#include<stdio.h>

#include "buscaSequencial.h"
#include "manipulaLista.h"

TAMANHO_PADRAO=80;

void imprimeRepeticao(char padrao, int qtd) {
    for (int cont = 0; cont < qtd; cont++) {
        printf("%c", padrao);
    }
}

void espacamentoVertical(char padrao, int tamanhoPadrao) {
    printf("\n");
    imprimeRepeticao(padrao, (tamanhoPadrao - 56)/2);
    printf("                                                        ");
    imprimeRepeticao(padrao, (tamanhoPadrao - 56)/2);
}

void menuInicial(bool comCabecalho, bool apagaTudo, Sprato *cardapio) {
    int tamanhoPadrao = TAMANHO_PADRAO, 
        qtdCardapio   = contaPratos(cardapio);

    if (apagaTudo) system("@cls||clear");

    imprimeRepeticao('*', tamanhoPadrao);
    printf("\n");
    imprimeRepeticao('*', tamanhoPadrao);

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('*', tamanhoPadrao);

    // Cabeçalho
    if (comCabecalho) {    
        printf("\n");
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
        printf("          Seja muito bem vindo(a) ao Plates!            ");
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

        printf("\n");
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
        printf("       O sistema de cardápio dos Deuses do Olimpo       ");
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

        printf("\n");
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
        printf("       Já temos %d pratos cadastrados no cardápio!      ", qtdCardapio);
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    }

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('*', tamanhoPadrao);
    espacamentoVertical('*', tamanhoPadrao);

    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("              O que deseja fazer agora?                 ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("   (Digite o número correspondente à ação que deseja)   ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    if (!comCabecalho) {
        printf("\n");
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
        printf("       Agora temos %d pratos cadastrados no cardápio!      ", qtdCardapio);
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    }

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('*', tamanhoPadrao);
    espacamentoVertical('*', tamanhoPadrao);

    // Opção 1 - Apresentar cardápio
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("          1 - Apresentar cardápio                       ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Opção 2 - Inserir um prato
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("          2 - Inserir um prato                          ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Opção 3 - Buscar pratos
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("          3 - Buscar pratos                             ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Opção 4 - Exclui prato
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("          4 - Excluir um prato pelo Id                  ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Opção 0 - Sair do programa
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("          0 - Sair do programa                          ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Pula linha no menu (espaçamento vert ical)
    espacamentoVertical('*', tamanhoPadrao);
    espacamentoVertical('*', tamanhoPadrao);

    // Rodapé
    printf("\n");
    imprimeRepeticao('*', tamanhoPadrao);
    printf("\n");
}

void menuBusca(char *nomePrato, bool apagaTudo) {
    int tamanhoPadrao = TAMANHO_PADRAO;

    if (apagaTudo) system("@cls||clear");

    imprimeRepeticao('#', tamanhoPadrao);
    printf("\n");
    imprimeRepeticao('#', tamanhoPadrao);

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('#', tamanhoPadrao);

    
    printf("\n");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);
    printf("          ATENCAO! Você está no menu de busca.          ");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);

    printf("\n");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);
    printf("       Digite o nome do prato que está buscando?         ");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);


    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('#', tamanhoPadrao);
    espacamentoVertical('#', tamanhoPadrao);

    // Rodapé
    printf("\n");
    imprimeRepeticao('#', tamanhoPadrao);
    printf("\n");

    printf("\n::: ");
    gets(nomePrato);
}

void menuInserePrato(Sprato *cardapio) {
    int tamanhoNome, tamanhoPadrao = TAMANHO_PADRAO;
    char *nomeNovoPrato, nomePratoAux[50];
    float valorPrato;

    // Primeira etapa: Perguntar o nome do prato
    system("@cls||clear");

    imprimeRepeticao('#', tamanhoPadrao);
    printf("\n");
    imprimeRepeticao('#', tamanhoPadrao);

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('#', tamanhoPadrao);

    printf("\n");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);
    printf("             ATENCAO! Você está no menu de              ");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);

    printf("\n");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);
    printf("               inserção de um novo prato.               ");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);

    espacamentoVertical('#', tamanhoPadrao);

    printf("\n");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);
    printf("      Digite o nome do prato que está inserindo?        ");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);


    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('#', tamanhoPadrao);
    espacamentoVertical('#', tamanhoPadrao);

    // Rodapé
    printf("\n");
    imprimeRepeticao('#', tamanhoPadrao);
    printf("\n");

    // Lendo nome do prato
    printf("\n::: ");
    gets(nomePratoAux);

    // Alocando nome dinamicamente
    tamanhoNome = strlen(nomePratoAux);

    // Alocando memória para o nome do prato
    nomeNovoPrato = (char *)malloc(tamanhoNome * sizeof(char));
    if (nomeNovoPrato == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Copiando uma string para a memória alocada
    strcpy(nomeNovoPrato, nomePratoAux);

    // Segunda etapa: Perguntar o valor do prato    
    system("@cls||clear");

    imprimeRepeticao('#', tamanhoPadrao);
    printf("\n");
    imprimeRepeticao('#', tamanhoPadrao);

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('#', tamanhoPadrao);

    printf("\n");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);
    printf("             ATENCAO! Você está no menu de              ");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);

    printf("\n");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);
    printf("               inserção de um novo prato.               ");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);

    espacamentoVertical('#', tamanhoPadrao);

    printf("\n");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);
    printf("                Nome do prato: %s            ", nomeNovoPrato);
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);

    espacamentoVertical('#', tamanhoPadrao);

    printf("\n");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);
    printf("      Digite o valor do prato que está inserindo?        ");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);


    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('#', tamanhoPadrao);
    espacamentoVertical('#', tamanhoPadrao);

    // Rodapé
    printf("\n");
    imprimeRepeticao('#', tamanhoPadrao);
    printf("\n");

    printf("\n::: ");
    scanf("%f", &valorPrato);

    // Liberando a memória alocada
    free(nomeNovoPrato);

    adicionaPratoNoCardapio(criaNovoPrato(nomePratoAux, valorPrato), cardapio);
}

int menuExcluiPrato(bool apagaTudo) {
    int tamanhoPadrao = TAMANHO_PADRAO,
        pratoId;

    if (apagaTudo) system("@cls||clear");

    imprimeRepeticao('#', tamanhoPadrao);
    printf("\n");
    imprimeRepeticao('#', tamanhoPadrao);

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('#', tamanhoPadrao);

    
    printf("\n");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);
    printf("      ATENCAO! Você está no de exclusão de um prato     ");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);

    printf("\n");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);
    printf("       Qual o ID do prato que deseja excluir?           ");
    imprimeRepeticao('#', (tamanhoPadrao - 56)/2);


    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('#', tamanhoPadrao);
    espacamentoVertical('#', tamanhoPadrao);

    // Rodapé
    printf("\n");
    imprimeRepeticao('#', tamanhoPadrao);
    printf("\n");

    printf("\n::: ");
    scanf("%d", &pratoId);

    return pratoId;
}

#endif