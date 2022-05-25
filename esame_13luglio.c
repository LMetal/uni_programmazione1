#include <stdio.h>
#include <stdlib.h>

struct element{
  short dato;
  struct element * next;
};

typedef struct element Node;
typedef struct element * Link;

// prototipi
int lista_leggi_file(FILE * fPtr, Link * lis);
void lista_visualizza(Link node);
Link lista_dividi(Link list, short segno);
void lista_scivi_file(Link list, FILE * fPtr);
void tail_insert(Link * lis, short n);


int main(int argc, char * argv[]){
  Link lista = NULL, lista_positivi = NULL, lista_negativi = NULL;
  FILE * f_input = NULL;
  FILE * f_output1 = NULL;
  FILE * f_output2 = NULL;
  int n_nodi;

  if(argc != 2){
    printf("\nERRORE INSERIMENTO PARAMETRI\n\n");
    return 1;
  }
  f_input = fopen(argv[1], "r");
  if(f_input == NULL){
    printf("\n\nERRORE APERTURA FILE\n\n");
    return 1;
  }

  n_nodi = lista_leggi_file(f_input, &lista);
  fclose(f_input);

  printf("\n\nLista creata:\n");
  lista_visualizza(lista);
  printf("Nodi presenti : %d\n", n_nodi);

  lista_positivi = lista_dividi(lista, 1); // 1 per numeri positivi
  printf("\n\nLista elementi positivi:\n");
  lista_visualizza(lista_positivi);

  lista_negativi = lista_dividi(lista, 0); // 0 per numeri negativi
  printf("\nLista elementi negativi:\n");
  lista_visualizza(lista_negativi);

  f_output1 = fopen("lista1.txt", "w");
  if(f_output1 == NULL){
    printf("\n\nERRORE APERTURA FILE\n\n");
    return 1;
  }
  lista_scivi_file(lista_positivi, f_output1);

  f_output2 = fopen("lista2.txt", "w");
  if(f_output2 == NULL){
    printf("\n\nERRORE APERTURA FILE\n\n");
    return 1;
  }
  lista_scivi_file(lista_negativi, f_output2);
}


int lista_leggi_file(FILE * fPtr, Link * lis){
  int n_nodi = 0, fscanf_r=0;
  short numero;

  while(feof(fPtr)!=1){
    n_nodi++;
    fscanf_r = fscanf(fPtr, "%hd", &numero);

    if(fscanf_r < 0) return n_nodi-1;

    if(numero<-10 || numero >10){
      printf("\n\nERRORE DATI FILE INPUT\n");
      return 0;
    }
    tail_insert(lis, numero);
  }

  return n_nodi;
}


void tail_insert(Link * lis, short n){
  Link p = NULL;

  if((*lis)==NULL){
    *lis = malloc(sizeof(Node));

    if((*lis) == NULL){
      printf("\nERRORE CREAZIONE LISTA\n\n");
      return;
    }

    (*lis)->dato = n;
    (*lis)->next = NULL;
  }
  else{
    p = *lis;
    while(p->next != NULL){
      p = p->next;
    }
    p->next = malloc(sizeof(Node));

    if(p->next == NULL){
      printf("\nERRORE CREAZIONE LISTA\n\n");
      (*lis) = NULL;
      return;
    }

    p->next->dato = n;
    p->next->next = NULL;
  }
}


void lista_visualizza(Link node){
  if(node == NULL){
    printf("NULL\n\n");
    return;
  }

  printf("%hd -> ", node->dato);
  lista_visualizza(node->next);
}


Link lista_dividi(Link list, short s){
  Link head=NULL;

  while(list!=NULL){
    if(s == 1){
      if(list->dato >= 0) tail_insert(&head, list->dato);
    }
    if(s == 0){
      if(list->dato < 0) tail_insert(&head, list->dato);
    }

    list = list->next;
  }
  return head;
}


void lista_scivi_file(Link list, FILE * fPtr){
  while(list!=NULL){
    fprintf(fPtr, "%hd\n", list->dato);
    list = list->next;
  }
}
