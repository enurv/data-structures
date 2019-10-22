#include <stdio.h>
#include <stdlib.h>

struct Node{
    int x;
    struct Node* next;
};
typedef struct Node node;

void bastir(node* root){
    node* iter = root; //loopa girmemek icin iter kullaniyoruz.
    printf("%d ", iter->x); //ilk degeri elle bastiriyoruz
    iter = iter->next; //ve iteri ilerletiyoruz yoksa while dongusune girmez.
    while(iter != root){//basa dondugunde durur
        printf("%d ", iter->x);
        iter = iter->next;
    }
    printf("\n");
}

node* ekle(node* root, int x){
    node* iter;
    if(root == NULL){ //liste bossa
        root = (node*)malloc(sizeof(node));
        root->next = root;
        root->x = x; //circular oldugu icin kendine baglanir
        return root;
    }else{
        iter = root;
        while(iter->next != root){ //sona ekleneceginden ve liste bos olmadiginden ilk dugumu kontole gerek yok.
            iter = iter->next;
        }
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = root;
        iter->next = temp;
        return root;

    }
}

node* siraliEkle(node* root, int x){
    if(root == NULL){
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = temp;
        return temp;
    }
    if(x < root->x){
            node* temp = (node*)malloc(sizeof(node));
            temp->x = x;
            temp->next = root;
            node* iter = root;
            while(iter->next != root){ //listenin sonunu yeni eklenen dugume baglamak icin
                iter = iter->next;
            }
            iter->next = temp;
            return temp;
    }else{
        node* iter = root;
        while(iter->next != root && iter->next->x < x){
                iter = iter->next;
        }
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = iter->next;
        iter->next = temp;
        return root;
    }
}

node* sil(node* root, int x){
    node* temp;
    node* iter = root;
    if(x == root -> x){ //aranan deger root ise
        while(iter->next != root){//listin sonuna gider
            iter = iter->next;
        }
        temp = root;
        iter -> next = root ->next; //rootu listeden cikarmis olur
        free(temp);
        return iter->next; //sonraki dugumu root atar
    }else{
        while(iter->next != root && iter->next->x != x){ //listenin sonuna gider
            iter = iter->next;
        }
        if(iter->next == root){
            printf("sayi bulunamadi\n");
            return root;
        }else if(iter->next->x == x){
            temp = iter->next;
            iter->next = temp->next;
            free(temp);
            return root;
        }
    }

}

int main(){
    node* root = NULL;
    node* iter;
    iter = root;
}
