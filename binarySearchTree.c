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
        newNode->data = x;
        newNode->left = NULL;
        newNode->right = NULL;
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

void traverse(node* root){
    if(root == NULL){
        return;
    }else{
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int search(node* root, int x){
    if(root == NULL){
        printf("Bos agac.\n");
        return -1;
    }else if(root->data == x){
        printf("Bulundu.\n");
        return 0;
    }else{
        if(x < root->data){
            return search(root->left, x);
        }else if(x > root->data){
            return search(root->right, x);
        }
    }
}

int findMin(node* root){
    if(root->left == NULL){
        return root->data;
    }
    return findMin(root->left);
}

int findMax(node* root){
    if(root->right == NULL){
        return root->data;
    }
    return findMin(root->right);
}

int height(node* root){
    if(root == NULL){
        return 0;
    }else{
        int rHeight = height(root->right);
        int lHeight = height(root->left);

        if(rHeight > lHeight){
            return rHeight++;
        }else{
            return lHeight++;
        }
    }
}

node* sil(node* root, int x){
    if(root == NULL){
        printf("Bu agac bos\n");
        return root;
    }
    if(x < root->data){
        root->left = sil(root->left, x);
        return root;
    }
    if(x > root->data){
        root->right = sil(root->right, x);
        return root;
    }
    if(x == root->data){
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }else if(root->left != NULL){
            root->data = findMax(root->left);
            root->left = sil(root->left, findMax(root->left));
            return root;
        }else{
            root->data = findMin(root->right);
            root->right = sil(root->right, findMin(root->right));
            return root;
        }
    }
}

int main(){
    node* root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 25);
    root = insertNode(root, 8);
    root = insertNode(root, 12);
    search(root, 15);
    printf("max: %d\n", findMax(root));
    printf("min: %d\n", findMin(root));
    traverse(root);printf("\n");
    root = sil(root, 8);
    root = sil(root, 15);
    traverse(root);

}
