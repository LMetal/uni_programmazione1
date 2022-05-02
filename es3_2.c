#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struttura e typedef
struct nodo{
  char dato;
  struct nodo * next;
};

typedef struct nodo Node;
typedef struct nodo * Link;

// prototipi
Link crea_lista(char string[]);
void stampa_lista(Link node, char name[]);
Link crea_lista_vocali(Link node, char ecc);
int isCopiabile(char c, char ecc);
int isVocale(char c);
void tail_insert(Link*head_ptr, Link* tail_ptr, char dato);


int main(int argc, char *argv[]){
  Link list = NULL;
  Link list_voc = NULL;

  if(argc != 3){
    printf("\nERRORE INSERIMENTO PARAMETRI\n\n");
    return 1;
  }


  list = crea_lista(argv[1]);
  list_voc = crea_lista_vocali(list, argv[2][0]);

  stampa_lista(list, "L1");
  stampa_lista(list_voc, "L2");

  return 0;
}


Link crea_lista(char stringa[]){
  Link head = NULL;
  Link tail = NULL;

  int i;

  for(i=0; stringa[i]!='\0'; i++){
    tail_insert(&head, &tail, stringa[i]);
  }

  return head;
}


Link crea_lista_vocali(Link node, char ecc){
  Link head = NULL;
  Link tail = NULL;


  while(node != NULL){

    if(isCopiabile(node->dato, ecc) == 1){
      tail_insert(&head, &tail, node->dato);
    }
    node = node->next;
  }

  return head;
}


int isCopiabile(char c, char ecc){   // ritorna 1 se è un carattere accettabile per la copia
  if(isVocale(c)){
    if(c != ecc) return 1;
    else return 0;
  }
  else return 0;

}


int isVocale(char c){
  return (c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U');
}


void tail_insert(Link* head_ptr, Link* tail_ptr, char data){
  if(*head_ptr == NULL){    // lista vuota
    *tail_ptr = malloc(sizeof(Node)); // crea nodo, aggiorna valore tail
    *head_ptr = *tail_ptr;  // aggiorna valore head
    if(*tail_ptr == NULL){  // se errore creazione nodo
      printf("\nERRORE CREAZIONE LISTA\n\n");
      //return NULL;
    }

    (*tail_ptr)->next = NULL;
    (*tail_ptr)->dato = data;
  }
  else{
    (*tail_ptr)->next = malloc(sizeof(Node)); // crea nodo, aggiorna valore tail
    if((*tail_ptr)->next == NULL){    // se errore creazione nodo
      printf("\nERRORE CREAZIONE LISTA\n\n");
      //return NULL;
    }

    *tail_ptr = (*tail_ptr)->next;  // aggiorna valore tail
    (*tail_ptr)->next = NULL;
    (*tail_ptr)->dato = data;
  }
}


void stampa_lista(Link node, char name[]){

  printf("\n\n\n%s :\t", name);
  while(node != NULL){
    printf("%c -> ", node->dato);

    node = node->next;
  }
  printf("NULL\n\n\n");

}





































// EOF

