#include <stdio.h>
#include <stdlib.h>

struct Node{
    int x;
    struct Node* next;
};

typedef struct Node node;

node* front = NULL;
node* rear = NULL;

void dequeue(){
    node* temp = front;
    if(front == NULL){
        printf("Bu kuyruk bos\n");
        return;
    }else if(front == rear){
        front = rear = NULL;
    }else{
        front = front->next;
        free(temp);
    }
}

void enqueue(int sayi){
        node* temp = (node*)malloc(sizeof(node));
        temp->x = sayi;
        temp->next = NULL;
        if(front == NULL && rear == NULL){
            front = rear = temp;
            return;
        }else{
            rear->next = temp;
            rear = temp;
        }
}

void Print(){
    if(front == NULL){
        printf("Bos kuyruk\n");
        return;
    }else{
       node*iter = front;
       while(iter != NULL){
        printf("%d ", iter->x);
        iter = iter->next;
       }
       printf("\n");
       return;
    }

}

int main(){

}
