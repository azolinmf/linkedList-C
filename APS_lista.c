#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "stdlib.h"

#define SIZE 20


//struct item
typedef struct item
{
    char nome[20];
    float preco;
    int quantidade;
} Item;

//lista de itens
typedef struct Lista
{
    Item item;
    struct Lista *proximo;
} Lista;


//******* funcoes da lista
int tamanho(Lista *lista)
{
    int cont = 0;
    Lista *and = lista;
    while (and != NULL)
    {
        and = and->proximo;
        cont++;
    }
    return cont;
}

int insert(Lista **lista, Item item)
{
    Lista *novo = malloc(sizeof(Lista));
    Lista *and = *lista;
    if (*lista == NULL) //se a lista esta vazia
    {
        novo->item = item;
        novo->proximo = NULL;
        *lista = novo;
    }
    else
    {
        while (and->proximo != NULL)
            and = and->proximo; //anda ate achar o ultimo
        novo->item = item;
        novo->proximo = NULL;
        and->proximo = novo;
    }
    return 0;
}

Item get(Lista *lista, int posicao)
{
    int i;
    Lista *and = lista;
    Item x;

    if (posicao >= tamanho(lista) || posicao <= -1) //se tenta acessar posiçao que nao existe
        return x;

    else if (posicao == 0) //se quer o primeiro elemento
        return lista->item;
    else
    {
        for (i = 0; i < posicao; i++)
            and = and->proximo;
        return and->item;
    }
}

int removePos(Lista **lista, int posicao)
{
    int i;

    if (posicao >= tamanho(*lista) || posicao <= -1) //se tenta acessar posiçao que nao existe
        return -1;

    else if (posicao == 0) //se só existe um elemento
    {
        Lista *temp = *lista;       //guarda posiçao que sera excluída
        *lista = (*lista)->proximo; //passa a pimeira posiçao pro proximo termo
        free(temp);                 //exclui o antigo primeiro termo
    }

    else
    {
        Lista *and = *lista;
        for (i = 0; i < posicao - 1; i++)     //vai ate uma posiçao antes da que deve ser excluida
            and = and->proximo;               //da um passo
        Lista *temp = and->proximo;           //and->prox é quem será excluido, crio temp pra saber oq excluir dps
        and->proximo = and->proximo->proximo; //faz indicar pra posicao que viria em seguida
        free(temp);
    }
    return 0;
}
//******* fim das funcoes da lista


//ordencao por Inserction Sort usando o nome
void sortedInsertName(Lista **head_ref, Lista *new_node)
{
    Lista *current;

    if (*head_ref == NULL || (*head_ref)->item.preco >= new_node->item.preco)
    {
        new_node->proximo = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->proximo != NULL &&
               strcmp(current->proximo->item.nome, new_node->item.nome) < 0)
        {
            current = current->proximo;
        }
        new_node->proximo = current->proximo;
        current->proximo = new_node;
    }
}

void insertionSortName(Lista **head_ref)
{
    Lista *sorted = NULL;

    Lista *current = *head_ref;
    while (current != NULL)
    {

        Lista *next = current->proximo;
        sortedInsertName(&sorted, current);

        current = next;
    }

    *head_ref = sorted;
}


//ordencao por Inserction Sort usando o preco
void sortedInsertPrice(Lista **head_ref, Lista *new_node)
{
    Lista *current;
    
    if (*head_ref == NULL || (*head_ref)->item.preco >= new_node->item.preco)
    {
        new_node->proximo = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        
        current = *head_ref;
        while (current->proximo != NULL &&
               current->proximo->item.preco < new_node->item.preco)
        {
            current = current->proximo;
        }
        new_node->proximo = current->proximo;
        current->proximo = new_node;
    }
}

void insertionSortPrice(Lista **head_ref)
{
    Lista *sorted = NULL;

    Lista *current = *head_ref;
    while (current != NULL)
    {

        Lista *next = current->proximo;
        sortedInsertPrice(&sorted, current);

        current = next;
    }

    *head_ref = sorted;
}


//busca binária
void binarySearch(Lista *lista, char x[], int posPrimeiro, int posUltimo)
{
    int meio = (posPrimeiro + posUltimo)/2;

    //caso de erro, se primeiro ou ultimo valem 0
    if (posUltimo < 1 || posPrimeiro < 1) {
        printf("\nLista vazia\n");
        return;
    }
        
    Item temp;
    temp = get(lista, meio);

    //se meio é igual ao item, imprime o item e da return
    if (strcmp(x, temp.nome) == 0) {
        printf("\nItem achado por busca binária:\n");
        printf("nome: %s", temp.nome);
        printf("\npreco: %.1f", temp.preco);
        printf("\nquantidade: %d\n", temp.quantidade);

        return;
    }

    //se meio é maior que o item, primeiro da lista é igual ao primeiro, e ultimo igual a meio-1
    if (strcmp(temp.nome, x)  > 0) {
        binarySearch(lista, x, posPrimeiro, meio - 1);
    }

    //se meio é menor que o item, primeiro da lista é meio+1 e ultimo é ultimo
    if (strcmp(temp.nome, x)  < 0) {
        binarySearch(lista, x, meio + 1, posUltimo);
    }

}


int main()
{

    Item x;
    Item y;

    int op;
    char stringToRemove[20];
    char stringToFind[20];
    int cont = 0;
    int a;

    FILE *entrada = fopen("entrada.txt", "r");
    FILE *saida = fopen("saida.txt", "w");

    Lista *lista = NULL;
    lista = malloc(sizeof(Lista));

    while (op != 9)
    {
        do
        {
            printf("\n\nMenu\n1- Adicionar novo item\n2- Buscar item\n3- Remover item\n4- Mostrar toda a lista\n5- Salvar no arquivo\n6- Ler itens de arquivo\n7- Ordenar itens por nome\n8- Ordenar itens por preco\n9- Sair\n\n");
            scanf("%d", &op);
            system("clear");
        } while (op < 1 || op > 9);

        switch (op)
        {
        case 1:

            printf("Adicionar novo item\n\nNome: ");
            scanf("%19s", x.nome);
            printf("\nPreco: ");
            scanf("%f", &x.preco);
            printf("\nQuantidade: ");
            scanf("%d", &x.quantidade);

            insert(&lista, x);

            break;
        case 2:

            //busca binaria
            printf("Nome do item que deseja buscar: ");
            scanf("%19s", stringToFind);

            //ordena antes de fazer a busca
            insertionSortName(&lista);

            if (tamanho(lista) > 1) 
                binarySearch(lista, stringToFind, 1,tamanho(lista));
            else
            {
                binarySearch(lista, stringToFind, 0,tamanho(lista));
            }

            break;
        case 3:
            printf("Nome do item a ser removido: ");
            scanf("%19s", stringToRemove);

            cont = 0;
            int pos = 0;
            for (int index = 1; index < tamanho(lista); index++)
            {
                y = get(lista, index);

                if (strcmp(y.nome, stringToRemove) == 0)
                {
                    pos = index;
                }
                cont++;
            }

            if (pos != 0)
            {
                removePos(&lista, pos);
            }
            else
            {
                printf("Esse item nao existe");
            }

            break;
        case 4:
            for (int index = 1; index < tamanho(lista); index++)
            {
                printf("\nItem %d da lista:\n", index);
                y = get(lista, index);

                printf("nome: %s", y.nome);
                printf("\npreco: %.2f", y.preco);
                printf("\nquantidade: %d\n", y.quantidade);
            }
            break;
        case 5:

            if (saida == NULL)
            {
                printf("Error opening file!\n");
                return -1;
            }

            for (int index = 1; index < tamanho(lista); index++)
            {
                y = get(lista, index);

                fprintf(saida, "\n%s %f %d", y.nome, y.preco, y.quantidade);
            }

            fclose(saida);

            break;
        case 6:

            if(entrada == NULL)
            {
                printf("Erro na abertura do arquivo!");
                return 1;
            }

            char ret = '\0';

            do {
                ret = fscanf(entrada, "%s %f %d", y.nome, &y.preco, &y.quantidade);
                insert(&lista, y);

            } while (ret != EOF);

            fclose(entrada);
            
            break;
        case 7:
            insertionSortName(&lista);
            break;
        case 8:
            insertionSortPrice(&lista);
            break;
        default:
            break;
        }
    }

    printf("\n\n");
    return 0;
}
