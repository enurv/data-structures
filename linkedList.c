#include <stdio.h>
#include <stdlib.h>

struct Node{
    int x;
    struct Node* next;
};
typedef struct Node node;


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

node* siraliEkle(node* root, int x){ //root degeri degisebilecegi icin node* degeri dondurur.
    if(root == NULL){ //yine bos olmasi durumunu kontrol ediyoruz.
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL;
        return temp;
    }
    if(x < root->x){ //eleman ilk dugumumuzden kucukse bu ozel bir durumdur.
            node* temp = (node*)malloc(sizeof(node));
            temp->x = x;
            temp->next = root;
            return temp;
    }else{
        node* iter = root; //root degerini kaybetmemek icin iterator kullanmak önemli.
        while(iter->next != NULL && iter->next->x < x){
                iter = iter->next;
        }//iterator istenen dugume geldi.
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = iter->next;
        iter->next = temp;
        return root;
    }
}

node* sil(node* root, int x){//root degeri degisebilecegi icin yine node* gonderiyoruz.
    node* temp; //free() fonksiyonunu calistirmak icin silinen dugumun adresi gecici bir sure icin saklanmalý.
    node* iter = root;
    if(x == root -> x){ //eger aranan deger ilk root dugumundeyse
        temp = root;
        root = root->next;
        free(temp);
        return root;
    }else{
        while(iter->next != NULL && iter->next->x != x){
            iter = iter->next;
        }
        if(iter->next == NULL){//listenin sonuna gelindiyse ve deger bulunmadiysa. (cunku iter silinecek elemanýn bir onunde durmali)
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
    root = ekle(root, 1);
    root = ekle(root, 35);
    root = ekle(root, 20);
    root = ekle(root, 356);
    bastir(root);
    root = reverse(root);
    bastir(root);
}
