#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void matrice_genera(const int N, const int M, unsigned matrix[N][M], const int V_MIN, const int V_MAX){
  for(unsigned short i=0; i<N; i++){
    for(unsigned short j=0; j<M; j++){
      matrix[i][j] = (rand()%(V_MAX-V_MIN))+V_MIN;
    }
  }
}


void matrice_visualizza(const int N, const int M, unsigned matrix[N][M]){
  printf("\n\nMatrice generata : \n\n");
  for(unsigned short i=0; i<N; i++){
    printf("\n");
    for(unsigned short j=0; j<M; j++){
      printf("%d\t", *(*(matrix+i)+j));
    }
  }
  printf("\n\n\n");
}


int array_pari(const int N, const int M, unsigned matrix[N][M], unsigned short array_nPari[N*M]){
  int n_pari=0;

  for(unsigned short i=0; i<N; i++){
    for(unsigned short j=0; j<M; j++){
      if(*(*(matrix+i)+j) % 2 == 0){ // se pari
        *(array_nPari + n_pari) = *(*(matrix+i)+j);
        n_pari++;
      }
    }
  }
  return n_pari;
}


void array_visualizza(const int N, const int M, unsigned short array_nPari[N*M], int n_nPari){
  printf("\nArray di numeri pari : \n\n");
  for(int i=0; i<n_nPari; i++){
    printf("%d\t", *(array_nPari + i));
  }
  printf("\n\n");
}


int main(int argc, char *argv[]){
  if(argc != 5){
    printf("\nErrore nell'inserimento degli argomenti: ./*.out [n_righe] [n_colonne] [v_min] [v_max]\n");
    return 1;
  }

  srand((unsigned)time(NULL));

  const unsigned N = (unsigned)atoi(argv[1]);
  const unsigned M = (unsigned)atoi(argv[2]);

  const int V_MIN = atoi(argv[3]);
  const int V_MAX = atoi(argv[4]);


  unsigned matrix[N][M];
  unsigned short array_nPari[N*M];

  matrice_genera(N, M, matrix, V_MIN, V_MAX);
  matrice_visualizza(N, M, matrix);
  int n_nPari = array_pari(N, M, matrix, array_nPari);
  array_visualizza(N, M, array_nPari, n_nPari);

  return 0;
}
