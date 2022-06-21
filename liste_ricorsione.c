#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct elem{
    int dato;
    struct elem * next;
};

typedef struct elem Node;
typedef struct elem * Link;

//prototipi
int lista_crea(Link * next_elem, int n);
void lista_visualizza(Link blocco);
void clear_lista(Link * head);

int main() {
    srand((unsigned) time(NULL));

    Link list = NULL;
    int n_blocchi = 4;

    int err = lista_crea(&list, n_blocchi);
    if(err == -1){
        list = NULL;
    }

    lista_visualizza(list);

    clear_lista(&list);

    lista_visualizza(list);

    return 0;
}



int lista_crea(Link * next_elem, int n){
    if(n<=0) return 0;

    *next_elem = malloc(sizeof(Node));
    if((*next_elem) == NULL){
        printf("\n\nERRORE MEMORIA\n\n");
        return -1;
    }

    (*next_elem)->dato = rand()%100+1;
    (*next_elem)->next = NULL;

    int err = lista_crea(&((*next_elem)->next), n-1);

    if(err == -1) return -1;
    else return 0;
}


void lista_visualizza(Link blocco){
    printf("\n\n");
    while(blocco != NULL){
        printf("%d->\t", blocco->dato);
        blocco = blocco->next;
    }
    printf("NULL\n\n");
}

void clear_lista(Link * head){
    Link temp = NULL;
    Link blocco = *head;

    while(blocco != NULL){
        temp = blocco;
        blocco = blocco->next;
        free(temp);
    }
    *head = NULL;

}
