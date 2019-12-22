#include <stdio.h>
#include <stdlib.h>

void yerDegistir(int dizi[], int x, int y) {
    int temp = dizi[x];
    dizi[x] = dizi[y];
    dizi[y] = temp;
}

void selectionSort(int dizi[], int diziBoyutu){
    for(int i = 0; i < diziBoyutu; ++i){
        int min = i;
        for(int j = i; j < diziBoyutu; ++j){
            if(dizi[j] < dizi[min]){
                min = j;
            }
        }
        yerDegistir(dizi, min, i);
    }
}

int matriseAta(int boyut, int* dizi){
    int* yeniDizi = (int*)malloc(sizeof(int)*boyut);
    int matris[boyut][boyut];
    int index = 0;
    int diziIndex = 0;
    for(int i = 0; i < boyut; i++){
        for(int j = 0; j < boyut; ++j){
            matris[i][j] = 1;
            for(int k = 0; k < i; k++){
                matris[i][k] = 0;
            }
            if(matris[i][j] == 1){
                matris[i][j] = dizi[index];
                index++;
                if(j == boyut - 1){
                    yeniDizi[diziIndex] = matris[i][j];
                    diziIndex++;
                }
            }
        }
    }
    printMatrix(boyut, matris);
    selectionSort(yeniDizi, boyut);
    printf("son sutundaki en buyuk eleman: %d\n", yeniDizi[boyut - 1]);

    return matris;
}
void printMatrix(int boyut, int matris[boyut][boyut]){
    for(int i = 0; i< boyut; ++i){
        for(int j = 0; j < boyut; ++j){
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int* dizi = (int*)malloc(sizeof(int)*15);
    for(int i = 15; i > 0; --i){
        dizi[15 - i] = i;
    }
    matriseAta(5, dizi);
}
