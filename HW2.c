#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void yerDegistir(int dizi[], int x, int y) {
    int temp = dizi[x];
    dizi[x] = dizi[y];
    dizi[y] = temp;
}

void insertionSort(int dizi[], int diziBoyutu){
    for(int i = 0; i < diziBoyutu; ++i){
        for(int j = i; j > 0; j--){
            if(dizi[j] < dizi[j-1]){
                yerDegistir(dizi, j, j-1);
            }
        }
    }

      /*for(int loop = 0; loop < diziBoyutu; loop++)
      printf("%d ", dizi[loop]);
      printf("\n");*/
}

void straightInsertionSort(int dizi[], int diziBoyutu){
    for(int i = 0; i < diziBoyutu; ++i){
        int T = dizi[i];
        int j = i;
        while(j > 0 && dizi[j-1] > T){
            dizi[j] = dizi[j - 1];
            j--;
        }
        dizi[j] = T;
    }
    /*for(int loop = 0; loop < diziBoyutu; loop++)
      printf("%d ", dizi[loop]);
    printf("\n");*/
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
            dizi[alt] = x;
        }
    }
    /*for(int loop = 0; loop < diziBoyutu; loop++)
      printf("%d ", dizi[loop]);
    printf("\n");*/

}

void selectionSort(int dizi[], int diziBoyutu){
    for(int i = 0; i < diziBoyutu - 1; i++){
        int min = i;
        for(int j = i + 1; j < diziBoyutu; j++){
            if(dizi[j] < dizi[min]){
                min = j;
                yerDegistir(dizi, i, min);
            }
        }
    }
    /*for(int loop = 0; loop < diziBoyutu; loop++)
      printf("%d ", dizi[loop]);
    printf("\n");*/
}

void bubbleSort(int dizi[], int diziBoyutu){
    for(int i = 0; i < diziBoyutu - 1; i++){
        for(int j = 0; j < diziBoyutu - i - 1; j++){
            if(dizi[j] > dizi[j + 1]){
                yerDegistir(dizi, j+1, j);
            }
        }
    }
    /*for(int loop = 0; loop < diziBoyutu; loop++)
      printf("%d ", dizi[loop]);
    printf("\n");*/
}


int main(){
    int dizi[10000];
    for(int i = 0; i < 10000; i++){
        dizi[i] = (rand() % 500) + 1;
    }
    //insertionSort
    clock_t begin = clock();
    insertionSort(dizi, 10000);
    clock_t end = clock();
    double harcananZaman = (double)(end - begin) / CLOCKS_PER_SEC;
    int harcananDakika = 0;
    int harcananSaniye = harcananZaman;
    int harcananSalise = (harcananZaman - harcananSaniye)*100;
    harcananSaniye = harcananZaman;
    if(harcananSaniye >= 60){
        harcananDakika += harcananSaniye / 60;
        harcananSaniye = harcananSaniye % 60;
    }
    if(harcananSalise >= 60){
        harcananSaniye += harcananSalise / 60;
        harcananSalise = harcananSalise % 60;
    }
	printf("Insertion Sort için harcanan zaman: %d:%d:%d\n", harcananDakika, harcananSaniye, harcananSalise);

	//straightInsertionSort
	begin = clock();
    straightInsertionSort(dizi, 10000);
    end = clock();
    harcananZaman = (double)(end - begin) / CLOCKS_PER_SEC;
    harcananDakika = 0;
    harcananSaniye = harcananZaman;
    harcananSalise = (harcananZaman - harcananSaniye)*100;
    harcananSaniye = harcananZaman;
    if(harcananSaniye >= 60){
        harcananDakika += harcananSaniye / 60;
        harcananSaniye = harcananSaniye % 60;
    }
    if(harcananSalise >= 60){
        harcananSaniye += harcananSalise / 60;
        harcananSalise = harcananSalise % 60;
    }
	printf("Straight Insertion Sort için harcanan zaman: %d:%d:%d\n", harcananDakika, harcananSaniye, harcananSalise);

	//binaryInsertionSort
	begin = clock();
    binaryInsertionSort(dizi, 10000);
    end = clock();
    harcananZaman = (double)(end - begin) / CLOCKS_PER_SEC;
    harcananDakika = 0;
    harcananSaniye = harcananZaman;
    harcananSalise = (harcananZaman - harcananSaniye)*100;
    harcananSaniye = harcananZaman;
    if(harcananSaniye >= 60){
        harcananDakika += harcananSaniye / 60;
        harcananSaniye = harcananSaniye % 60;
    }
    if(harcananSalise >= 60){
        harcananSaniye += harcananSalise / 60;
        harcananSalise = harcananSalise % 60;
    }
	printf("Binary Insertion Sort için harcanan zaman: %d:%d:%d\n", harcananDakika, harcananSaniye, harcananSalise);

	//selectionSort
	begin = clock();
    selectionSort(dizi, 10000);
    end = clock();
    harcananZaman = (double)(end - begin) / CLOCKS_PER_SEC;
    harcananDakika = 0;
    harcananSaniye = harcananZaman;
    harcananSalise = (harcananZaman - harcananSaniye)*100;
    harcananSaniye = harcananZaman;
    if(harcananSaniye >= 60){
        harcananDakika += harcananSaniye / 60;
        harcananSaniye = harcananSaniye % 60;
    }
    if(harcananSalise >= 60){
        harcananSaniye += harcananSalise / 60;
        harcananSalise = harcananSalise % 60;
    }
	printf("Selection Sort için harcanan zaman: %d:%d:%d\n", harcananDakika, harcananSaniye, harcananSalise);

	//bubbleSort
	begin = clock();
    bubbleSort(dizi, 10000);
    end = clock();
    harcananZaman = (double)(end - begin) / CLOCKS_PER_SEC;
    harcananDakika = 0;
    harcananSaniye = harcananZaman;
    harcananSalise = (harcananZaman - harcananSaniye)*100;
    harcananSaniye = harcananZaman;
    if(harcananSaniye >= 60){
        harcananDakika += harcananSaniye / 60;
        harcananSaniye = harcananSaniye % 60;
    }
    if(harcananSalise >= 60){
        harcananSaniye += harcananSalise / 60;
        harcananSalise = harcananSalise % 60;
    }
	printf("Bubble Sort icin harcanan zaman: %d:%d:%d\n", harcananDakika, harcananSaniye, harcananSalise);

}
