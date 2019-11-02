#include <stdio.h>
#include <stdlib.h> //malloc kullanabilmek icin kullanmak gerek
#include <string.h>

struct Node{
    char harf;
    struct Node* next;
};

typedef struct Node node;

node* nodeOlustur(char eklenecek){
      node* yeniNode = (node*)malloc(sizeof(node));
      yeniNode->harf = eklenecek;
      yeniNode->next = NULL;
      return yeniNode;
}

node* sonaEkle(node*root, char eklenecek){
    if(root == NULL){ //listte eleman yoksa calisir.
        node* temp = nodeOlustur(eklenecek);
        return temp;
    }
    node* iter = root;
    while(iter->next != NULL){
        iter = iter->next;
    }
    node* yeniNode = nodeOlustur(eklenecek);
    iter->next = yeniNode;
    return root;
}

void bastir(node* root){
    while(root != NULL){
        printf("%c", root->harf);
        root = root->next;
    }
    printf("\n");
}

node* birlestir(node* root1, node* root2){
    node* iter1 = root1;
    while(iter1->next != NULL){
        iter1 = iter1->next;
    }
    iter1->next = root2;
    return root1;
}

int main(){
  char* kelime1 = (char*)malloc(sizeof(char)*256);
  char* kelime2 = (char*)malloc(sizeof(char)*256);
  printf("Birinci kelimeyi giriniz: ");
  scanf("%s", kelime1);
  printf("Ikinci kelimeyi giriniz: ");
  scanf("%s", kelime2);
  node* root1 = NULL;
  node* root2 = NULL;
  for(int i = 0; i < strlen(kelime1); ++i){
    root1 = sonaEkle(root1, kelime1[i]);
  }
  for(int j = 0; j < strlen(kelime2); ++j){
    root2 = sonaEkle(root2, kelime2[j]);
  }
  node* birlesik = birlestir(root1, root2);
  bastir(birlesik);

}





