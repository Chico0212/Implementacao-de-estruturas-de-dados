#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void startList(node** list)
{
    // lista eh inicializada
    *list = NULL;
}

int emptyList(node* list)
{
    // verifica se a lista esta vazia
    return list == NULL;
}

int insertInIndex(node** list, int data, int index)
{
    // alocacao do novo no
    /*-------------------*/
    // alocation of the new node
    node* new = (node*)malloc(sizeof(node*));
    // dado eh atribuido
    new->data = data;
    // auxiliar 
    node* aux = *list;
    // posicao
    int indexCount = 0;

    // verifica se a lista esta vazia e se o indice eh zero
    // pois se ela estiver vazia o unico jeito de inserir eh no incio
    if (emptyList(*list) && index != 0) return 0;

    // verifica se o indice eh possivel
    if (index > lenLinkedList(*list)) return 0;
    
    // switch para certos atalhos
    switch (index)
    {
        // se o indice for 0 
        case 0:
            // o proximo do novo recebe a lista
            new->next = *list;
            // lista recebe o novo
            *list = new;
            break;
        case -1:
            // itera ateh o ultimo item
            while (aux->next != NULL)
            {
                // auxiliar eh atualizado
                aux = aux->next;
            }

            // o proximo em relacao ao novo recebe NULL
            new->next = aux->next;
            // proximo recebe o novo
            aux->next = new;
            break;
        default:
            // procura o item ateh achar o index
            while (indexCount != index-1)
            {
                // a posicao do elemento eh incrementada
                indexCount++;
                // aux eh atualizado
                aux = aux->next;
            }

            // mesmo raciocinio de troca do case anterior
            new->next = aux->next;
            aux->next = new;
            break;
        }
}

void printList(node* list)
{
    // copia da lista
    node* cpyList = list;

    // enquanto cpyList for diferente de NULL
    while (cpyList != NULL)
    {
        // printa o dado da lista 
        printf("{%d}--->", cpyList->data);
        // cpyList eh atuaalizado
        cpyList = cpyList->next;
    }
    printf("NULL\n");
}

int lenLinkedList(node* list)
{
    // tamanho
    int size = 0;

    // enquanto list nao for nula
    while (list != NULL)
    {
        // tamanho eh incrementado
        size++;
        // list eh atualizada
        list = list->next;
    }

    // retorna o tamanho
    return size;
}

int elementIndex(node* list, int element)
{
    // index do elemento
    int index = 0;
    // copia da lista
    node* cpyList = list;

    // enquanto cpyList nao for nulo
    while (cpyList != NULL)
    {
        // se o dado atual for o elemento buscado
        // retorna o indice
        if (cpyList->data == element) return index;

        // caso contrario
        // indece eh incrementado
        index++;

        // cpyList eh iterado
        cpyList = cpyList->next;
    }

    // retorna -1 em caso de erro
    return -1;
}

int removeInIndex(node** list, int index)
{
    // auxiliar eh instanciado
    node* aux = *list;
    // contador para verificar o indice
    int countIndex = 0;

    // se a lista estiver vazia e o indice nao for 0
    // retorna 0
    if (emptyList(*list) && index != 0) return 0;

    // se o indice for maior que o possivel
    // retorna 0
    if (index > lenLinkedList(*list)) return 0;

    switch (index)
    {
        // primeiro indice
        case 0:
            // posicao atual recebe a proxima
            *list = (*list)->next;
            return 1;
        // ultima posicao
        case -1:
            // enquanto o item analizado nao for o prnultimo
            while (aux->next->next != NULL)
            {
                // auxiliar anda uma casa
                aux = aux->next;
            }

            // o proximo item recebe o ultimo
            aux->next = aux->next->next;
            return 1;
        // qualquer outra posicao
        default:
            // enquanto o contador nao estiver antes do indice
            while (countIndex != index-1)
                {
                    // contador eh incrementado
                    countIndex++;
                    // auxiliar eh incrementado
                    aux = aux->next;
                }

            // o proximo item recebe o seu proximo
            aux->next = aux->next->next;
            return 1;
    }
}

int removeItem(node** list, int data)
{
    // se o elemento nao for encontrado ele retorna 0
    if (elementIndex(*list, data) < 0) return 0;

    // auxiiliar eh instanciado
    node* aux = *list;

    // se o dado atual for igual ao dado inserido
    // sigfica que o item eh o primeiro
    if (aux->data == data)
    {
        // entao eh so fazer o atual recber o valor do proximo
        *list = (*list)->next;
        return 1;
    }

    // enquanto o dado for diferente
    while (aux->next->data != data)
    {
        // auxiliar eh atualizado
        aux = aux->next;
    }

    // dado eh removido
    aux->next = aux->next->next;

    return 1;
}

int elementInIndex(node* list, int index)
{
    // verifica se o indice eh possivel
    if (index > lenLinkedList(list) - 1 || index < 0) return 0;

    // para i enquanto for menor que o indice
    for (int i = 0; i < index; i++)
    {
        // lista eh atualizada
        list = list->next;
    }

    // retorna o dado do indice
    return list->data;
}

int equalList(node* listOne, node* listTwo)
{
    // tamanho das listas
    int sizeOne = lenLinkedList(listOne);
    int sizeTwo = lenLinkedList(listTwo);

    // se os tamanhos forem diferentes
    // retorna -1
    if (sizeOne != sizeTwo) return -1;

    // enquanto o tamanho nao for 0
    while (sizeOne > 0)
    {
        // se o o dado entre elas forem diferentes
        if (listOne->data != listTwo->data)
        {
            // retorna 0
            return 0;
        }
        sizeOne--;
    }

    // retorna 1 indicando sucesso
    return 1;
}

int fullToEmpty(node** list)
{
    // se a lista estiver vazia retorna 0
    if (emptyList(*list)) return 0;

    // enquanto a lista nao for nula
    while (*list != NULL)
    {
        // lista eh atualaizada
        *list = (*list)->next;
    }

    // retorna 1
    return 1;
}

int listCpy(node** source, node** destination)
{
    // se o destino nao estiiver vazio
    // ele sera esvaziado
    if (!emptyList(*destination)) fullToEmpty(destination);

    // enquanto a atribuicao for possivel
    while (*destination = *source)
    {   
        // as listas "andarao" uma casa
        *source = (*source)->next;
        *destination = (*destination)->next;
    }

    // se as listas foram diferentes
    // retorna 0
    if (!equalList(*source, *destination)) return 0;

    // retorna um indicando sucesso
    return 1;
}
