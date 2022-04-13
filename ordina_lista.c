#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define N_NUM 10

struct element{
  int data;

  struct element * next;
};

typedef struct element Node;
typedef struct element * Link;

// prototipi
void stampa_lista(Link);
Link makelist();
Link makeNode();
void order_list(Link * );

// end prototipi


int main(){
  srand((unsigned)time(NULL));

  Link list = makelist();

  stampa_lista(list);

  order_list(&list);
  stampa_lista(list);

  return 0;
}


void stampa_lista(Link Node){
  while(Node != NULL){
    printf("\nindirizzo : %p\tdato : %d\tpunto a : %p", Node, Node-> data, Node->next);

    Node = Node->next;
  }

  printf("\n\n\n");
}




Link makelist(){
  Link head = NULL;
  Link tail = NULL;

  for(short i=N_NUM; i>0; i--){


    if(head == NULL){
      head = makeNode();

      head-> next = NULL;
      head-> data = i; //rand()%100;

      tail = head;
    }
    else{
      tail-> next = makeNode();
      tail = tail->next;

      tail-> next = NULL;
      tail-> data = i; //rand()%100;
    }
  }

  return head;
}


void swap_node(Link current){
  Link tmp = current-> next;

  current->next = current-> next-> next;
  tmp->next = current-> next ->next;

  current-> next-> next = tmp;
}


Link makeNode(){
  return malloc(sizeof(Node));
}


void order_list(Link * head){
  Link tmp = NULL;
  Link current = NULL;

  int cicli=0;

  for(int i=0; i<N_NUM-1; i++){
    cicli = 0;
    for(short k=0; k<N_NUM-i-1; k++){

      // se dato nodo1 > dato nodo2 e nodo1 e' head
      if((*head)-> data > (*head)-> next-> data && k==0){
        tmp = *head;

        *head = (*head)-> next;

        tmp->next = (*head)->next;
        (*head)-> next = tmp;

      }

      else if(current-> next-> data > current-> next-> next-> data){
        swap_node(current);
      }

      // update valori
      if(k == 0) current = (*head);
      else current = current-> next;

      cicli++;
    }
    stampa_lista(*head);
    printf("numero cicli : %d\n\n\n", cicli);
  }



}


























// EOF
