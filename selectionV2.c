#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void swap(int *vet,int a,int b){
    int aux = vet[a];
    vet[a] = vet[b];
    vet[b] = aux;
}

void selectionSort(int *vet,int lenVet){
    int menor, maior, indexMenor, i=0, counter=lenVet-1, indexMaior;
    while(i<=counter){
        menor = INT_MAX;
        maior = INT_MIN;
        for(int j=i;j<=counter;j++){
            if(vet[j]<menor){
                menor = vet[j];
                indexMenor = j;
            }
            if(vet[j]>maior){
                maior = vet[j];
                indexMaior = j;
            }
        }
        swap(vet,i,indexMenor);
        if(indexMaior!=i){
            swap(vet,counter,indexMaior);
            counter--;
        }
        i++;
    }
}

int main(){
    int *vet, lenVet=30;

    vet = createVet(lenVet);
    printVet(vet,lenVet);
    selectionSort(vet,lenVet);
    printVet(vet,lenVet);
    free(vet);

    return 0;    
}