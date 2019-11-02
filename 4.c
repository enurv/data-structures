//Olusturulmus bir tek bagli listeyi tersine ceviren bir c fonksiyonu yaziniz.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int x;
    struct Node* next;
};
typedef struct Node node;

node* reverse(node* root){
    node* prev = NULL;
    node* dugum = root;
    node* iter = NULL;
    while(dugum->next != NULL){
        iter = dugum->next;
        dugum->next = prev;
        prev = dugum;
        dugum = iter;
    }
    dugum->next = prev;
    return dugum;
}
