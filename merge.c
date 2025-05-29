#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *vet,int start,int middle,int end){
    int size = end-start+1, indexAuxVet=0, counter1=start, counter2=middle+1;
    int *auxVet = malloc(sizeof(int)*(size)); 

    while(counter1<=middle && counter2<=end){
        if(vet[counter1]<=vet[counter2]){
            auxVet[indexAuxVet++]=vet[counter1++];
        }else{
            auxVet[indexAuxVet++]=vet[counter2++];
        }
    }
    while(counter1<=middle){
        auxVet[indexAuxVet++]=vet[counter1++];
    }
    while(counter2<=end){
        auxVet[indexAuxVet++]=vet[counter2++];
    }

    for(int i=0;i<size;i++){
        vet[start+i]=auxVet[i];
    }
    free(auxVet);
}

void mergeSort(int *vet,int start,int end){
    if(start<end){
        int middle = start+(end-start)/2;
        mergeSort(vet,start,middle);
        mergeSort(vet,middle+1,end);
        merge(vet,start,middle,end);
    }
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
    int size=1000;
    int *vet = createRandomVet(size);

    //printVet(vet,size);
    mergeSort(vet,0,size-1);
    printf("%d\n",Sorted(vet,size));
    //printVet(vet,size);

    free(vet);

    return 0;
}