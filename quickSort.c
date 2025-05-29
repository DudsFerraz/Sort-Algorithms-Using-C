#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *vet,int a,int b){
    int aux = vet[a];
    vet[a]=vet[b];
    vet[b]=aux;
}

int particao(int *vet,int inicio,int fim){
    int meio = (inicio+fim)/2;
    int pivo = vet[meio];
    int counter1=inicio, counter2=fim;

    while(counter1<counter2){
        while(vet[counter1]<pivo){
            counter1++;
        }
        while(vet[counter2]>pivo){
            counter2--;
        }
        if(counter1<counter2){
            swap(vet,counter1,counter2);
            counter1++;
            counter2--;
        }
    }
    return counter2;
}

void quickSort(int *vet,int inicio,int fim){
    if(inicio>=fim){
        return;
    }
    int pivo = particao(vet,inicio,fim);
    quickSort(vet,inicio,pivo);
    quickSort(vet,pivo+1,fim);
}

int *createRandomVet(int size){
    srand(time(NULL));
    int *newVet = malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        newVet[i]=(rand()%100);
    }
    return newVet;
}

int Sorted(int *vet,int size){
    for(int i=0;i<size-1;i++){
        if(vet[i]>vet[i+1]){
            return 0;
        }
    }
    return 1;
}

void printVet(int *vet,int size){
    for(int i=0;i<size;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

int main(){
    int *vet, size=15;

    vet = createRandomVet(size);
    quickSort(vet,0,(size-1));
    printf("%d\n",Sorted(vet,size));
    printVet(vet,size);

    free(vet);

    return 0;
}