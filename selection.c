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

void selectionSort(int *vet,int lenVet){
    int menor, aux, index;
    for(int i=0;i<lenVet;i++){
        menor = vet[i];
        for(int j=i;j<lenVet;j++){
            if(vet[j]<=menor){
                menor = vet[j];
                index = j;
            }
        }
        aux = vet[i];
        vet[i] = menor;
        vet[index] = aux;
    }
}

void printVet(int *vet,int lenVet){
    for(int i=0;i<lenVet;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

int main(){
    int *vet, lenVet=15;

    vet = createVet(lenVet);
    printVet(vet,lenVet);
    selectionSort(vet,lenVet);
    printVet(vet,lenVet);
    free(vet);

    return 0;    
}
    printVet(vet,lenVet);
    free(vet);

    return 0;    
}
