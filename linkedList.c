#include <stdio.h>
#include <stdlib.h>

struct Node{
    int x;
    struct Node* next;
};
typedef struct Node node;

void bastir(node* root){
    while(root != NULL){
        printf("%d ", root->x);
        root = root->next;
    }
    printf("\n");
}

void ekle(node* root, int x){
    if(root == NULL){
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL;
        root = temp;
    }else{
        while(root->next != NULL){
            root = root->next;
        }
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL;
        root->next = temp;
    }
}

node* siraliEkle(node* root, int x){
    if(root == NULL){
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL;
        return temp;
    }
    if(x < root->x){
            node* temp = (node*)malloc(sizeof(node));
            temp->x = x;
            temp->next = root;
            return temp;
    }else{
        node* iter = root;
        while(iter->next != NULL && iter->next->x < x){
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
