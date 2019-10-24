#include <stdio.h>
#include <stdlib.h>

struct Node{
    int x;
    struct Node* next;
};
typedef struct Node node;

node* push(node* top, int x){ //root degeri yerine top kelimesini kullaniyoruz.
    if(top == NULL){ //Bos olmasi durumunu kontrol ediyoruz.
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL;
        return temp;
    }
    else{ //sona eklemektense basa eklemek (algoritma analizine gore) daha avantajlidir.
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = top;
        return temp;
    }
}

node* pop(node* top){
    if(top == NULL){
        printf("bos yigin.\n");
    }
    node* temp; //free() fonksiyonunu calistirmak icin silinen dugumun adresi gecici bir sure icin saklanmalý.
    printf("%d silindi.\n", top->x);
    temp = top;
    top = top->next;
    free(temp);
    return top;

}

void bastir(node* top){//tersten yazdirmaliyiz.
    node* iter = top; //burada tek bagli listenin ziddi olarak (top==root) bastirmaya listenin sonundan baslariz.
    int sayac = 0;
    if(iter == NULL){
        printf("bos yigin\n");
        return;
    }
    while(iter != NULL){
        sayac++;
        iter = iter->next;
    }
    int* degerler = (int*)malloc(sizeof(int)* sayac);
    iter = top;
    int i = 0;
    while(iter != NULL){
        degerler[i] = iter->x;
        i++;
        iter = iter->next;
    }
    for(int j = sayac - 1; j >= 0; --j){
        printf("%d ", degerler[j]);
    }

    printf("\n");
}

int main(){
    node* top = NULL;
    bastir(top);
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = push(top, 50);
    bastir(top);
    top = pop(top);
    bastir(top);
    top = pop(top);
    bastir(top);
    top = pop(top);
    bastir(top);
    top = pop(top);
    bastir(top);
    top = pop(top);
    bastir(top);
    top = pop(top);
    bastir(top);
    top = pop(top);

}
