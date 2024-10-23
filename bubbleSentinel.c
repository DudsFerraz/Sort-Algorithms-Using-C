#include <stdio.h>
#include <stdlib.h>

int *createVet(int size){
    int *newVet = malloc(sizeof(int)*size);

    for(int i=0;i<size;i++){
        int value = rand();
        while(value>99){
            value=value/10;
        }
        newVet[i]=value;
    }
    return newVet;
}   

void swap(int *vet,int a,int b){
    int aux = vet[a];
    vet[a] = vet[b];
    vet[b] = aux;
}

void bubbleSort(int *vet, int size){
    while(size>0){
        int lastSwap=0;
        for(int i=0;i<size-1;i++){
            if(vet[i]>vet[i+1]){
                swap(vet,i,i+1);
                lastSwap=i+1;
            }
        }
        size=lastSwap;
    }
}

void printVet(int *vet,int size){
    for(int i=0;i<size;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}
int main(){
    int *vet, lenVet=25;

    vet = createVet(lenVet);
    printVet(vet,lenVet);
    bubbleSort(vet,lenVet);
    printVet(vet,lenVet);
    free(vet);

    return 0;
}
