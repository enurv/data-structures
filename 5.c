//verilen iki ikili agaci birlestiren bir c fonksiyonu yaziniz.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node node;


node* createNewNode(int x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insertNode(node* root, int x){
    if(root == NULL){
        node* newNode = createNewNode(x);
        //printf("%d eklendi\n", newNode->data);
        return newNode;
    }else{
        if(x < root->data){
            root->left = insertNode(root->left, x);
        }else if(x > root->data){
            root->right = insertNode(root->right, x);
        }else{
            printf("Bu deger zaten agacta var.\n");
        }
    }
}

void traverse(node* root){
    if(root == NULL){
        return;
    }else{
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}




node* birlestir(node* root1, node* root2){
    if(root2 == NULL){
        return root1;
    }
    root1 = birlestir(root1, root2->left);
    root1 = insertNode(root1, root2->data);
    root1 = birlestir(root1, root2->right);

}

int main(){
    node* root = NULL;
    node* root1 = NULL;
    root1 = insertNode(root1, 15);
    root1 = insertNode(root1, 10);
    root1 = insertNode(root1, 20);
    root1 = insertNode(root1, 25);
    root1 = insertNode(root1, 8);
    root1 = insertNode(root1, 12);
    root = insertNode(root, 43);
    root = insertNode(root, 69);
    root = insertNode(root, 5);
    root = insertNode(root, 36);
    root = insertNode(root, 26);
    root = insertNode(root, 72);
    root = insertNode(root, 79);
    root = insertNode(root, 59);
    root1 = birlestir(root1, root);
    traverse(root1);

}
