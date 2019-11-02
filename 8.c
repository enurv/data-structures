/*Elimizde 10 elemanli bir yigit vardir. Bu yigitin icindeki elemanlari
bir tek bagli listeye aktaran c fonksiyonunu yaziniz.*/

#include <stdio.h>
#include <stdlib.h>

int silindi;

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node node;

node* push(node* root, int x){
    if(root == NULL){
        node* temp = (node*)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL;
        return temp;
    }else{
        node* temp = (node*)malloc(sizeof(node));
        temp->data = x;
        temp->next = root;
        return temp;
    }
}

node* pop(node* root){
    if(root == NULL){
        printf("Bos yigit\n");
        return root;
    }else{
        node* temp = root;
        root = root->next;
        silindi = temp->data;
        printf("%d silindi.\n", temp->data);
        free(temp);
        return root;
    }
}

void bastirStack(node* top){//tersten yazdirmaliyiz.
    node* iter = top; //burada tek bagli listenin ziddi olarak (top==root) bastirmaya listenin sonundan baslariz.
    int sayac = 0;
    if(iter == NULL){
        printf("bos yigin\n");
        return;
    }
    while(iter != NULL){
        sayac++;
        iter = iter->next;
    }
    int* degerler = (int*)malloc(sizeof(int)* sayac);
    iter = top;
    int i = 0;
    while(iter != NULL){
        degerler[i] = iter->data;
        i++;
        iter = iter->next;
    }
    for(int j = sayac - 1; j >= 0; --j){
        printf("%d ", degerler[j]);
    }

    printf("\n");
}

node* sonaEkleList(node* root, int x){ //bu fonksiyon yeni gelen elemanlari listin sonua ekler.
    if(root == NULL){ //listte eleman yoksa calisir.
        node* temp = (node*)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL; //onemli
        root = temp;
        return root;
    }else{
        node* iter = root;
        while(iter->next != NULL){ //Burada iteratorun nexti kontrol etmesi onemli cunku iteri NULL bir degere atamak istemeyiz.
            iter = iter->next;
        }//son dugume gelindi
        node* temp = (node*)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL;
        iter->next = temp;
        return root;
    }
}

void bastirList(node* root){
    while(root != NULL){ //iter olmadan rootu hareket ettirebiliriz. root NULL oldugunda listin sonuna gelmisiz demektir.
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}



int main(){
    node* top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = push(top, 50);
    top = push(top, 60);
    top = push(top, 70);
    top = push(top, 80);
    top = push(top, 90);
    top = push(top, 100);
    bastirStack(top);

    node* root = NULL;
    for(int i = 0; i < 10; ++i){
        top = pop(top);
        root = sonaEkleList(root, silindi);
    }
    bastirList(root);
}
