#include <stdio.h>
#include <stdlib.h>

void yerDegistir(int dizi[], int x, int y) {
    int temp = dizi[x];
    dizi[x] = dizi[y];
    dizi[y] = temp;
}

void selectionSort(int dizi[], int diziBoyutu, int index){
    for(int i = index; i < diziBoyutu; ++i){
        int min = i;
        for(int j = i; j < diziBoyutu; ++j){
            if(dizi[j] < dizi[min]){
                min = j;
            }
        }
        yerDegistir(dizi, min, i);
    }
}

int* diziyeAta(int boyut, int matris[boyut][boyut]){
    int* dizi = (int*)malloc(sizeof(int)*boyut*boyut);
    for(int i = 0; i < boyut; ++i){
        for(int j = 0; j < boyut; ++j){
            int k = (boyut*i) + j;
            dizi[k] = matris[i][j];
        }
    }
    return dizi;
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int matris[5][5] =   {{0, 3, 2,1,8},
                          {1, 2, 3,9,8},
                          {5, 6, 7,2,1},
                          {1, 2, 3,9,8},
                          {1, 2, 3,9,8}};

    int* dizi = diziyeAta(5, matris);
    printArray(dizi, 25);
    int index = 2*5;
    int to = index + 5;
    selectionSort(dizi, to, index);
    printArray(dizi, 25);

}
