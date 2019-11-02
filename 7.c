//Verilen bir ikili agacýn sag ve sol kollarinin sayisini ayri ayri ekrana yazdrian c programinin yaziniz.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node node;

int sag = 0;
int sol = 0;
void sagSolSayisi(node* root){
    if(root == NULL){
        return;
    }if(root->right != NULL){
        sag++;
        sagSolSayisi(root->right);
    }if(root->left != NULL){
        sol++;
        sagSolSayisi(root->left);
    }
}

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

int main(){
    node* root = NULL;
    root = insertNode(root, 43);
    root = insertNode(root, 69);
    root = insertNode(root, 5);
    root = insertNode(root, 36);
    root = insertNode(root, 26);
    root = insertNode(root, 72);
    root = insertNode(root, 79);
    root = insertNode(root, 59);
    sagSolSayisi(root);
    printf("sag: %d\n", sag);
    printf("sol: %d\n", sol);
}
