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

void printVet(int *vet,int lenVet){
    for(int i=0;i<lenVet;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

void insertionSort(int *vet,int lenVet){
    int aux;
    for(int i=0;i<lenVet;i++){
        for(int j=i;j>0;j--){
            if(vet[j]<vet[j-1]){
                aux = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = aux; 
            }else{
                break;
            }
        }
    }
}

int main(){
    int *vet, lenVet=25;

    vet = createVet(lenVet);
    printVet(vet,lenVet);
    insertionSort(vet,lenVet);
    printVet(vet,lenVet);
    free(vet);


    return 0;
}