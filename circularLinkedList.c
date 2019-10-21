#include <stdio.h>
#include <stdlib.h>

struct Node{
    int x;
    struct Node* next;
};
typedef struct Node node;

void bastir(node* root){
    node* iter = root;
    printf("%d ", iter->x);
    iter = iter->next;
    while(iter != root){
        printf("%d ", iter->x);
        iter = iter->next;
    }
    printf("\n");
}

node* ekle(node* root, int x){
    node* iter;
    if(root == NULL){
        root = (node*)malloc(sizeof(node));
        root->next = root;
        root->x = x;
        return root;
    }else{
        iter = root;
        while(iter->next != root){
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
            while(iter->next != root){
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
    if(x == root -> x){
        while(iter->next != root){
            iter = iter->next;
        }
        temp = root;
        iter -> next = root ->next;
        free(temp);
        return iter->next;
    }else{
        while(iter->next != root && iter->next->x != x){
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
