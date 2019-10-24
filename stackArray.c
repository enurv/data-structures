#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int boyut;
    int* yigin;
};
typedef struct Stack stack;

/*void initialize(stack* s){ //initiliazer olusturmayi beceremedim.
    s->top = 0;
    s->boyut = 2;
    s->yigin = (int*)malloc(sizeof(int) * s->boyut);
}*/

void pop(stack* s){
    if(s->top == -1){ //bos olma durumunu kontrol eder
        printf("Bu yigit bostur.\n");
        return;
    }

    if(s->top <= (s->boyut)/4){ //eleman sayisi boyutundortte biri kadarsa boyutu yarisina azaltir
        int* yeniYigin = (int*)malloc(sizeof(int) * s->boyut / 2);
        for(int i = 0; i < s->boyut; ++i){
            yeniYigin[i] = s->yigin[i];
        }
        free(s->yigin); //free yapmak programin efektifligi icin onemlidir.
        s->yigin = yeniYigin;
        s->boyut /= 2;
    }
    printf("Stackden cikarildi: %d\n", s->yigin[s->top]);
    s->top--;
}

int top(stack* s){ //en ustteki sayiyi dondurur.
    return s->yigin[s->top];
}

void push(stack* s, int x){
    if(s->top + 1 == (s->boyut)){ //eger boyutu doldurduysak boyutu iki katýna cikarir.
        int* yeniYigin = (int*)malloc(sizeof(int) * s->boyut * 2);
        for(int i = 0; i < s->boyut; ++i){
            yeniYigin[i] = s->yigin[i];
        }
        free(s->yigin);
        s->yigin = yeniYigin;
        s->boyut *= 2;

    }
    s->top++;
    s->yigin[s->top] = x;
}

void bastir(stack* s){
    for(int i = 0; i < s->top + 1; ++i){
        printf("%d ", s->yigin[i]);
    }
    printf("\n");
}

void icineBak(stack* s){ //stackin degerlerini ekrana bastirir. (initiliazer fonksiyonunu ve boyutu kontrol etmek icin yazdim.)
    printf("top: %d\n", s->top);
    printf("boyut: %d\n", s->boyut);
}

int main(){
    stack yigin1 = {-1, 2, (int*)malloc(sizeof(int) * 2)}; //struct yaoisinda constructor olmadigi icin boyle initialize ediyoruz.
                                                           //top degerinin -1 olmasina dikkat edin.
    push(&yigin1, 10);
    push(&yigin1, 20);
    push(&yigin1, 30);
    push(&yigin1, 40);
    push(&yigin1, 50);
    push(&yigin1, 60);
    push(&yigin1, 70);
    push(&yigin1, 80);
    pop(&yigin1);
    pop(&yigin1);
    pop(&yigin1);
    pop(&yigin1);
    pop(&yigin1);
    //pop(&yigin1);
    //pop(&yigin1);
    bastir(&yigin1);
    printf("top: %d\n", top(&yigin1));
    icineBak(&yigin1);

}
