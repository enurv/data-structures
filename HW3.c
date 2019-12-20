#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    FILE *fp;
    char* buff = malloc(sizeof(char)*255);

    fp = fopen("matrisler.txt", "r");
    fscanf(fp, "%s", buff);
    char *boyutString;
    boyutString = strtok(buff, "x");
    int boyut;
    sscanf(boyutString, "%d", &boyut);
    int* tekDizi = (int*)malloc(sizeof(int)*boyut*boyut*2);
    int** mat1=malloc(boyut*sizeof(int*));
    for(int i=0;i<boyut;++i)
        mat1[i]=malloc(boyut*sizeof(int));
    for(int i = 0; i < boyut; ++i){
        for(int j = 0; j < boyut; ++j){
            if (!fscanf(fp, "%d", &mat1[i][j])){
                break;
            }
            tekDizi[i*boyut + j] = mat1[i][j];
          }
    }
    int** mat2=malloc(boyut*sizeof(int*));
    for(int i=0;i<boyut;++i)
        mat2[i]=malloc(boyut*sizeof(int));
    for(int i = 0; i < boyut; ++i){
        for(int j = 0; j < boyut; ++j){
            if (!fscanf(fp, "%d", &mat2[i][j])){
                break;
            }
            tekDizi[(j+boyut)*boyut + i] = mat2[i][j];
          }
    }
    fclose(fp);


    FILE *yaz;
    yaz = fopen("sonuc.txt", "w");

    for(int i = 0; i < boyut*boyut; i += boyut){
        for(int j = boyut*boyut; j < boyut*boyut*2; j += boyut){
            int temp = 0;
            for(int k = 0; k < boyut; k++){
                temp += tekDizi[i+k]*tekDizi[j+k];
            }
            fprintf(yaz, "%d ", temp);
        }
        fputs("\n", yaz);
    }

}
