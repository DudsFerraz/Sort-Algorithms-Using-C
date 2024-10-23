#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *vet, int size){
    int aux, lastChange;

    while(size>0){
        for(int i=0;i<size;i++){
            if(vet[i]>vet[i+1]){
                aux=vet[i];
                vet[i]=vet[i+1];
                vet[i+1]=aux;
                lastChange=i;
            }
        }
        size=lastChange;
    }
}

void printVet(int *vet,int size){
    for(int i=0;i<size;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}
int main(){
    int vet[10] = {2,5,7,8,9,3,2,4,5,-1}, lenVet=10;

    bubbleSort(vet,lenVet);
    printVet(vet,lenVet);

    return 0;
}