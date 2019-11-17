#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int boyut;
    int* yigin;
};
typedef struct Stack stack;

stack* yeniStack(){
    stack* yeni = (stack*)malloc(sizeof(stack));
    yeni->top = -1;
    yeni->boyut = 2;
    yeni->yigin = (int*)malloc(sizeof(int)*2);
}

void bastir(stack* s){
    for(int i = 0; i < s->top + 1; ++i){
        printf("%d ", s->yigin[i]);
    }
    printf("\n");
}


stack* pop(stack* s){
    if(s->top == -1){
        printf("Bu yigit bostur.\n");
        return s;
    }

    if(s->top <= (s->boyut)/4){
        int* yeniYigin = (int*)malloc(sizeof(int) * s->boyut / 2);
        for(int i = 0; i < s->boyut; ++i){
            yeniYigin[i] = s->yigin[i];
        }
        free(s->yigin);
        s->yigin = yeniYigin;
        s->boyut /= 2;
    }
    printf("Stackden cikarildi: %d\n", s->yigin[s->top]);
    s->top--;
    return s;
}

int top(stack* s){
    return s->yigin[s->top];
}

stack* push(stack* s){
    int x;
    printf("Eklemek istediginiz sayiyi giriniz: ");
    scanf("%d", &x);
    if(s->top + 1 == (s->boyut)){
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
    return s;
}




int main(){
    stack* yigin1 = yeniStack();
    int secim;
    secim = 0;
    while(secim != 4){
        printf("1: eleman ekleme\n2: eleman silme\n3: print\n4: Menuden cikis\nSeciminiz: ");
        scanf("%d", &secim);
        switch(secim) {
            case 1:
                 yigin1 = push(yigin1);
             break;
            case 2:
                 yigin1 = pop(yigin1);
             break;
            case 3:
                 bastir(yigin1);
             break;
        }
    }
}
