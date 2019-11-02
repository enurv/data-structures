/*Onceden olusturulmus bir ikili agac uzerindeki elemanlarý siizn olusturacaginiz bir linked liste ekleyen bir c fonksiyonu yaziniz. */

#include <stdio.h>
#include <stdlib.h>


struct Node{
    int x;
    struct Node* next;
};
typedef struct Node node;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode nodeTree;

void bastir(node* root){
    while(root != NULL){ //iter olmadan rootu hareket ettirebiliriz. root NULL oldugunda listin sonuna gelmisiz demektir.
        printf("%d ", root->x);
        root = root->next;
    }
    printf("\n");
}

node* ekle(node* root, int x){ //bu fonksiyon yeni gelen elemanlari listin sonua ekler.
    if(root == NULL){ //listte eleman yoksa calisir.
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL; //onemli
        root = temp;
        return root;
    }else{
        node* iter = root;
        while(iter->next != NULL){ //Burada iteratorun nexti kontrol etmesi onemli cunku iteri NULL bir degere atamak istemeyiz.
            iter = iter->next;
        }//son dugume gelindi
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL;
        iter->next = temp;
        return root;
    }
}
nodeTree* createNewNode(int x){
    nodeTree* newNode = (nodeTree*)malloc(sizeof(nodeTree));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

nodeTree* insertNode(nodeTree* root, int x){
    if(root == NULL){
        nodeTree* newNode = createNewNode(x);
        printf("%d eklendi\n", newNode->data);
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

void traverse(nodeTree* root){
    if(root == NULL){
        return;
    }else{
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

void listeyeKoy(node* root, nodeTree* tree){
    if(tree == NULL){
        return;
    }else{
        traverse(tree->left);
        root = ekle(root, tree->data);
        traverse(tree->right);
    }
}

int main(){
    nodeTree* root = NULL;
    root = insertNode(root, 43);
    root = insertNode(root, 69);
    root = insertNode(root, 5);
    root = insertNode(root, 36);
    root = insertNode(root, 26);
    root = insertNode(root, 72);
    root = insertNode(root, 79);
    root = insertNode(root, 59);
    node* rootList = NULL;
    listeyeKoy(rootList, root);
    bastir(rootList);
}
