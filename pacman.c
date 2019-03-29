#include <stdlib.h>
#include <stdio.h>

typedef struct MATRIZ Matriz;
struct MATRIZ {
  int ** m;
  int n;
  int deslocamento;
};

Matriz * criaMatriz(int nrovertices){
  Matriz * mat = malloc(sizeof(Matriz));
  if(!mat){
    return NULL;
  }

  (mat)->n = nrovertices;
  (mat)->m = malloc(sizeof(int*)*nrovertices);
  for (int i = 0; i < nrovertices; i++) {
    (mat)->m[i] =  calloc(sizeof(int),nrovertices);
  }
  return mat;
}

 void caminha (int px, int py, int fx, int fy, Grafo * mat, int pacman, int fantasma){
       mat->m[px][py] = pacman;

       calcula(px, py, fx, fy, mat, 0);
       int menorx = mat->m[px-1][py] , menory = mat->m[px][py-1];

       if(mat->m[px+1][py] < mat->m[px-1][py]) menorx = mat->m[px+1][py];
       if(mat->m[px][py+1] < mat->m[px][py-1]) menorx = mat->m[px][py+1];
       if(menorx )



 }

void calcula(int px, int py, int fx, int fy, Grafo ** mat, int peso){

    if(fx == 0 || fx ==4 || fy ==0|| fy == 4 || (fx==px && fy ==py) ) return;

    mat->m[fx][fy] = peso;

    calcula(px, py, fx+1, fy, mat, peso++);
    calcula(px, py, fx-1, fy, mat, peso++);
    calcula(px, py, fx, fy+1, mat, peso++);
    calcula(px, py, fx, fy-1, mat, peso++);
}


int main(){

  Matriz * mat = criaMatriz(5);

  int pacman = -1;
  int fantasma = -2;

  calcula(px,py,fx,fy,mat, pacman, fantasma, 0);


  return 0;
}
