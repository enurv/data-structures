#include <math.h>
#include <stdio.h>

void yerDegistir(int dizi[], int x, int y) {
    int temp = dizi[x];
    dizi[x] = dizi[y];
    dizi[y] = temp;
}

void insertionSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        int degistirilecekSayi = arr[i];
        for(j = i - 1; j >= 0; --j){
            if(arr[j] > degistirilecekSayi){
                arr[j+1] = arr[j];
                arr[j] = degistirilecekSayi;
            }else{
                break;
            }
        }
    }
}

void binaryInsertionSort(int dizi[], int diziBoyutu){
    for(int i = 1; i < diziBoyutu; i++){
        int x = dizi[i];
        int alt = 0;
        int ust = i - 1;
        while(alt <= ust){
            int pivot = (alt + ust) / 2;
            if(x < dizi[pivot]){
                ust = pivot - 1;
            }else{
                alt = pivot + 1;
            }
        }
        for(int j = i - 1; j >= alt; --j){
            dizi[j + 1] = dizi[j];
        }
        dizi[alt] = x;
    }
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

void bubbleSort(int dizi[], int diziBoyutu){
    for(int i = 0; i < diziBoyutu; ++i){
        for(int j = 0; j < diziBoyutu - 1; ++j){
            if(dizi[j] > dizi[j+1]){
                yerDegistir(dizi, j, j+1);
            }
        }
    }
}

int ayir(int dizi[], int basla, int son){
    int baslangicPivot = dizi[son];
    int pIndex = basla;
    for(int i = basla; i < son; ++i){
        if(dizi[i] <= baslangicPivot){
            yerDegistir(dizi, i, pIndex);
            pIndex++;
        }
    }
    yerDegistir(dizi, pIndex, son);
    return pIndex;
}

void quickSort(int dizi[], int  basla, int son){

    if(basla < son){
        int pIndex = ayir(dizi, basla, son);

        quickSort(dizi, basla, pIndex - 1);
        quickSort(dizi, pIndex + 1, son);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 11, 99, 1, 13, 5, 6};
    int end = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, end);
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Quick sort: ");
    printArray(arr, n);

    return 0;
}


