#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

typedef struct {
    int linha;
    int coluna;
    float* v;
};

Matriz criar(int m, int n) {
   Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
   if (mat == NULL){
    printf("Memória cheia!\n");
    exit(1);
   }

   mat->linha = m;
   mat->coluna = n;
   mat->v = (float*) malloc(m*n*sizeof(float));
   return mat;
}

void liberar(Matriz *mat)
{
}

void libera(Matriz* mat){
    free(mat->v);
    free(mat);
}

float acessa(Matriz* mat, int i, int j){
    int k;
    if(i<0 || i>=mat->linha || j<0 || j->mat->coluna){
        printf("Acesso invalido!\n");
    }

    k = i*mat->coluna + j;
    return mat->v[k];
}

void atribuir(Matriz *mat, int i, int j, float v)
{
}

void atribui(Matriz* mat, int i, int j, float v){
    int k;
    if(i<0 || i>mat->linha || j<0 || j>=mat->coluna){
        printf("Não atribuido!\n");
        exit(1)
    }

    k = i*mat->coluna + j;
    mat->v[k] = v;
}

int linhas(Matriz* mat){
    return mat->linhas;
}

int colunas (Matriz* mat){
    return mat->coluna;
}


int ehQuadradaSimetrica(Matriz* mat) {
    if (mat->linha != mat->coluna) {
        return 0; 
    }

    for (int i = 0; i < mat->linha; i++) {
        for (int j = 0; j < i; j++) {
            if (acessa(mat, i, j) != acessa(mat, j, i)) {
                return 0; 
            }
        }
    }

    return 1; 
}

Matriz transposta(Matriz* mat) {
    Matriz transp = criar(mat->coluna, mat->linha);

    for (int i = 0; i < mat->linha; i++) {
        for (int j = 0; j < mat->coluna; j++) {
            atribui(&transp, j, i, acessa(mat, i, j));
        }
    }

    return transp;
}
