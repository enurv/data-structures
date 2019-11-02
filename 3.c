#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node node;

int findMax(node* root){
    if(root->right == NULL){
        return root->data;
    }
    return findMin(root->right);
}
