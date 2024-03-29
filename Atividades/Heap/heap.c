#include <stdio.h>
#include <math.h>
#include "heap.h"
#define N 10

int totalElementos = 0;

int indiceFilhoEsq(int x){
    int indice = (2*x) + 1;
    if(indice >= totalElementos)
        return -1;
    else
        return indice;
}

int indiceFilhoDir(int x){
    int indice = (2*x) + 2;
    if(indice >= totalElementos)
        return -1;
    else
        return indice;
}

int indicePai(int x){
    int indice = (int) floor((x-1)/2);

    if(x<=0 || x >= totalElementos)
        return -1;
    else
        return indice;
}

void Inserir(int *heap, int x){
    heap[totalElementos] = x;
    totalElementos++;

    ajustarSubindo(heap, totalElementos-1);
}

void ajustarSubindo(int *heap, int pos){
    if(pos!=-1){
        int pai = indicePai(pos);
        if(pai != -1){
            if(heap[pos]<heap[pai]){
                int aux = heap[pos];
                heap[pos] =  heap[pai];
                heap[pai] = aux;
                ajustarSubindo(heap, pai);
            }
        }
    }
}

int remover(int *heap){
    if(totalElementos == 0)
        return -1;
    else{
        int retorno = heap[0];
        heap[0] = heap[totalElementos-1];
        totalElementos--;
        ajustarDescendo(heap, 0);
        return retorno;
    }
}

void ajustarDescendo(int *heap, int pos){
    if(pos != (-1) && indiceFilhoEsq(pos)!=-1){
        int indiceMenorFilho = indiceFilhoEsq(pos);
        if( indiceFilhoDir(pos)!=-1 && heap[indiceFilhoDir(pos)] < heap[indiceMenorFilho]){
            indiceMenorFilho = indiceFilhoDir(pos);
        }

        if(heap[indiceMenorFilho] < heap[pos]){
            int aux = heap[pos];
            heap[pos] = heap[indiceMenorFilho];
            heap[indiceMenorFilho] = aux;
            ajustarDescendo(heap, indiceMenorFilho);
        }
            
    }
}


void imprimir(int *heap){
    int quebrar = 1;
    for (int i = 0; i < totalElementos; i++){
        if(i+1 == quebrar){
            printf("\n");
            quebrar *= 2;
        }
        printf("[%d]",heap[i]);
    }
    printf("\n");
}

