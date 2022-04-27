#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struttura e typedef
struct nodo{
  char c;

  struct nodo * next;
};

typedef struct nodo Node;
typedef struct nodo * Link;

// prototipi
Link crea_lista(char string[]);
void stampa_lista(Link node, char name[]);
Link crea_lista_vocali(Link node, char ecc);
int isCopiabile(char c, char ecc);


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


Link crea_lista(char string[]){
  Link head = NULL;
  Link tail = NULL;
  Link temp = NULL;

  int i;

  for(i=0; i<(int)strlen(string); i++){
    temp = malloc(sizeof(Node));

    if(i==0){
      head = temp;
      tail = head;

      tail->next = NULL;
      tail->c = string[i];
    }
    else{
      tail->next = temp;

      tail = tail->next;

      tail->next = NULL;
      tail->c = string[i];
    }
  }

  return head;
}


Link crea_lista_vocali(Link node, char ecc){
  Link head = NULL;
  Link tail = NULL;
  Link temp = NULL;

  int i=0;

  while(node != NULL){

    if(isCopiabile(node->c, ecc) == 1){
      temp = malloc(sizeof(Node));

      if(i==0){
        head = temp;
        tail = head;

        tail->next = NULL;
        tail->c = node->c;
      }
      else{
        tail->next = temp;

        tail = tail->next;

        tail->next = NULL;
        tail->c = node->c;
      }

      i++;
    }
    node = node->next;
  }

  return head;
}

int isCopiabile(char c, char ecc){   // ritorna 1 se è un carattere accettabile per la copia
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
    if(c != ecc) return 1;
    else return 0;
  }
  else return 0;

}


void stampa_lista(Link node, char name[]){

  printf("\n\n\n%s :\t", name);
  while(node != NULL){
    printf("%c -> ", node->c);

    node = node->next;
  }
  printf("NULL\n\n\n");

}





































// EOF
