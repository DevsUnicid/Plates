#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<stdbool.h>

#include "lib/structPrato.h"
#include "lib/manipulaLista.h"
#include "lib/menu.h"

char PATH_DB[40] = "../database/dbPratos.csv";

Sprato *carregaBancoCsvEmLista() {
    FILE *fArquivoBanco;
    char linhaCsv[1024];
    int qtdPratos = 0;
    Sprato *novoPrato, *cardapio;

    fArquivoBanco = fopen(PATH_DB, "r");

    while(fgets(linhaCsv, 1024, fArquivoBanco) != NULL) {
        
        // Esse if pula o cabeçalho do arquivo csv (../database/dbPrato.csv)
        if (qtdPratos == 0) {
            qtdPratos++;
            continue;
        }

        // 'if' que decide se a coleção já foi iniciada 
        if (qtdPratos == 1) cardapio = alocaPratoFromChar(linhaCsv, qtdPratos);
        else {
            novoPrato = alocaPratoFromChar(linhaCsv, qtdPratos);
            adicionaPratoNoCardapio(novoPrato, cardapio);
        }

        qtdPratos++;
    }
    fclose(fArquivoBanco);

    return cardapio;
}

int main() {
    // Localiza o código no 'Portuguese' para usarmos caracteres especiais
    setlocale(LC_ALL, "Portuguese");

    int cont;
    char escolhaUsuario;
    Sprato *deck, novoPrato, *cardapio;

    cardapio = carregaBancoCsvEmLista();

    menuInicial(true, true);
    printf("\n::: ");

    scanf("%c", &escolhaUsuario);
    getchar();
    system("@cls||clear");

    while(true) {
        if (escolhaUsuario == NULL) {
            menuInicial(false, false);
            printf("\n::: ");

            scanf("%c", &escolhaUsuario);
            getchar();
        }

        switch (escolhaUsuario)
        {
            case '1':
                imprimeCardapio(cardapio, false);
                printf("\n\n\n");
                break;
            
            case '2':
                // sistemaBusca(cardapio);
                printf("\n\n\n");
                break;

            case '3':
                // boosterBox = geraBoosters(cardapio);
                // iniciaDraft(boosterBox);
                fflush(stdin);
                break;

            case '0':
                printf("\n\n\n\t\tObrigado por usar o MagiC. Seu simulador de draft de código aberto!\n\n\n\n\n\n\n");
                exit(0);
            
            default:
                break;
        }

        escolhaUsuario = NULL;
    }


    return 0;
}