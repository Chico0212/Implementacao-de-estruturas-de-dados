#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "linkedList.h"

// prototipos
/*---------*/
// prototypes
void menu(node* list);
void userMenu(node* list);

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    node* list;
    startList(&list);

    menu(list);
}

void menu(node* list)
{
    // mostra os itens do menu
    printf("\n");
    printf("\t[0] -> para sair do programa\n");
    printf("\t[1] -> para adicionar um elemento\n");
    printf("\t[2] -> para remover um elemento num determinado �ndice\n");
    printf("\t[3] -> para remover um elemento\n");
    printf("\t[4] -> para obter o tamanho da lista\n");
    printf("\t[5] -> para consultar o indice de um elemento\n");
    printf("\t[6] -> para consultar o elemento num determinado �ndice\n");
    printf("\t[7] -> para comparar duas listas\n");
    printf("\t[8] -> para transferir dados entre listas\n");
    printf("\t[9] -> para limpar a lista\n");
    printf("\t[10] -> para printar a lista\n");
    printf("\t[11] -> para verificar se a lista esta vazia\n\n");

    return userMenu(list);
}

void userMenu(node* list)
{
    // op��o dada pelo usu�rio
    int opt;
    // indice e elemento da lista
    int index, element;

    printf("\tIsira sua op��o: ");
    scanf("%d", &opt);
    printf("\n");

    switch (opt)
    {
        case 0:
            exit(0);
        case 1:
            printf("\tIsira o �ndice: ");
            scanf("%d", &index);

            printf("\t\nInsira o elemento que voce deseja inserir: ");
            scanf("%d", &element);

            if (!insertInIndex(&list, element, index)) printf("\n\tNao foi poss�vel concluir a opera��o\n");

            break;
        case 2:
            printf("\tIsira o �ndice: ");
            scanf("%d", &index);

            if (!removeInIndex(&list, index)) printf("\n\tNao foi poss�vel concluir a opera��o\n");

            break;
        case 3:
            printf("\tInsira o elemento que voce deseja remover: ");
            scanf("%d", &element);

            if (!insertInIndex(&list, element, index)) printf("\n\tNao foi poss�vel concluir a opera��o\n");

            break;
        case 4:
            if (lenLinkedList(list) == 0)
            {
                printf ("\tA lista ainda est� vazia!\n");
            } else printf("\tO tamanho da lista ?: %d\n", lenLinkedList(list));

            break;
        case 5:
            printf("\tInsira o elemeto a ser consultado: ");
            scanf("%d", &element);

            index = elementIndex(list, element);

            if (index < 0)
            {
                printf("\n\tElemento n�o encontrado!\n");
            } else printf("\n\tO �ndice do elemento %d ? %d\n", element, index);

            break;
        case 6:
            printf("\tIsira o �ndice a ser consultado: ");
            scanf("%d", &index);

            element = elementIndex(list, index);

            if (element == 0)
            {
                printf("\n\tO �ndice n�o foi encontrado\n");
            } else printf("\n\tO elemento no �ndice %d ? %d\n", index, element);

            break;
        case 7:
            printf("\n\tDesculpe, eu n�o consigo fazer isso por voc�...\n");
            printf("\tMas voc� pode tentar manualmente usando a fun��o equalList\n");
            break;
        case 8:
            printf("\n\tDesculpe, eu n�o consigo fazer isso por voc�...\n");
            printf("\tMas voc� pode tentar manualmente usando a fun��o listCpy\n");
            break;
        case 9:
            if (!fullToEmpty(&list))
            {
                printf("\n\tA lista j? est� vazia\n");
            } else printf("\n\tLista esvaziada com sucesso\n");

            break;
        case 10:
            printf("\t");
            printList(list);

            break;
        case 11:
            printf("%s", isEmpty(list) ? "\n\tSim, a lista est� vazia\n" : "\n\tn�o, a lista n�o est� vazia\n");
        default:
            printf("\n\tOp��o invalida\n");

        return menu(list);
    }
}
