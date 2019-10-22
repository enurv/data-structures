#include <stdio.h>
#include <stdlib.h>

struct Node{
    int x;
    struct Node* next;
    struct Node* prev;
};
typedef struct Node node;

void bastir(node* root){ //bu fonksiyon sorunsuz calisir.
    while(root != NULL){
        printf("%d ", root->x);
        root = root->next;
    }
    printf("\n");
}

node* ekle(node* root, int x){
    if(root == NULL){
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL;
        temp->prev = NULL; //ilk elemanýn prev degeri de NULL a esittir.
        root = temp;
        return root;
    }else{ //iceride eleman varsa sona ekler
        node* iter = root;
        while(iter->next != NULL){
            iter = iter->next;
        }
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL; //next i NULL degerine atamak onemli
        temp->prev = iter; //diger kodlardan farklý olarak prev degeri atanmalý.
        iter->next = temp;
        return root;
    }
}

node* siraliEkle(node* root, int x){
    if(root == NULL){ //liste bossa
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL;
		temp->prev = NULL; //revin de NULL olmasi onemli
        return temp;
    }
    if(x < root->x){ //eklenecek dugum rootdan kucukse basa eklenmeli
            node* temp = (node*)malloc(sizeof(node));
            temp->x = x;
            temp->next = root;
            root->prev = temp;
            return temp;
    }else{
        node* iter = root;
        while(iter->next != NULL && iter->next->x < x){
                iter = iter->next;
        }//iter listenin sonuna goturulur.
        if(iter->next == NULL){ //eger sondayse NULL degerine bir kutu gibi davranýp prev degeri atayamayýz.
            node* temp = (node*)malloc(sizeof(node));
            temp->x = x;
            temp->next = NULL;
            temp->prev = iter;
            iter->next = temp;
            return root;
        }else{ //aradaysa bir sorun olmadan ekleyebiliriz.
            node* temp = (node*)malloc(sizeof(node));
            temp->x = x;
            temp->next = iter->next;
            iter->next->prev = temp;
            temp->prev = iter;
            iter->next = temp;
            return root;
        }
    }
}

node* sil(node* root, int x){
    node* temp;
    node* iter = root;
    if(x == root -> x){
        temp = root;
        root = root->next;
        free(temp);
        return root;
    }else{
        while(iter->next != NULL && iter->next->x != x){
            iter = iter->next;
        }
        if(iter->next == NULL){
            printf("sayi bulunamadi\n");
            return root;
        }else if(iter->next->x == x){
            if(iter->next->next != NULL){
                temp = iter->next;
                iter->next = temp->next;
                temp->next->prev = iter;
                free(temp);
                return root;
            }else{//sondaki dugumun nexti NULL oldugu o zaman onun prev degeri atanamaz
                temp = iter->next;
                iter->next = temp->next;
                free(temp);
                return root;
            }

        }
    }

}

int main(){
    node* root = NULL;
    root = siraliEkle(root, 400);
    root = siraliEkle(root, 40);
    root = siraliEkle(root, 4);
    root = siraliEkle(root, 450);
    root = siraliEkle(root, 50);
    bastir(root);
     root = sil( root, 50);
 bastir(root);
 root = sil( root, 999);
 bastir(root);
 root = sil( root, 4);
 bastir(root);
 root = sil( root, 450);
 bastir(root);
}
