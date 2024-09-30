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

    int cont, numeroPratoAux;
    char escolhaUsuario, nomePrato[50];
    Sprato *novoPrato, *cardapio, *pratoAux;

    cardapio = carregaBancoCsvEmLista();

    menuInicial(true, true, cardapio);
    printf("\n::: ");

    scanf("%c", &escolhaUsuario);
    getchar();
    system("@cls||clear");

    while(true) {
        // printf("\n escolhaUsuario: %c - escolhaUsuario == NULL: %d", escolhaUsuario, escolhaUsuario == NULL);
        if (escolhaUsuario == NULL) {
            menuInicial(false, false, cardapio);
            printf("\n::: ");

            scanf("%c", &escolhaUsuario);
            getchar();
        }

        switch (escolhaUsuario)
        {
            // Opção 1 - Apresentar cardápio
            case '1':
                imprimeCardapio(cardapio, false);
                printf("\n\n\n");

                break;
            
            // Opção 2 - Inserir um prato
            case '2':
                menuInserePrato(cardapio);
                imprimeCardapio(cardapio, false);

                escolhaUsuario = NULL;

                break;

            // Opção 3 - Buscar pratos
            case '3':
                menuBusca(nomePrato, true);
                novoPrato = buscaPratoPorNome(cardapio, nomePrato);

                if (novoPrato != NULL) {
                    apresentainfoPrato(*novoPrato);
                    printf("\n\n\n");
                }
                else {
                    printf("\n\n\n\t\tPrato não encontrado!\n\n\n\n\n\n\n");
                }

                break;

            // Opção 4 - Exclui prato
            case '4':
                imprimeCardapio(cardapio, false);
                pratoAux = excluiPratoPorId(cardapio, menuExcluiPrato(true));

                if (pratoAux != NULL) {
                    apresentainfoPrato(*pratoAux);
                    printf("\n\tPrato excluído com sucesso!\n\n\n\n");
                }
                else {
                    printf("\n\n\n\t\tPrato não encontrado!\n\n\n\n\n\n\n");
                    imprimeCardapio(cardapio, false);
                };

                break;

            // Opção 0 - Sair do programa
            case '0':
                printf("\n\n\n\t\tObrigado por usar o Plates. O sistema de cardápio dos Deuses do Olimpo e de código aberto!\n\n\n\n\n\n\n");
                exit(0);
            
            default:
                break;
        }

        escolhaUsuario = NULL;
    }


    return 0;
}