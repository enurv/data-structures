#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int* kuyruk;
    int boyut;
    int rear;
    int front;
};

typedef struct Queue queue;

queue* yeniQueueOlustur(int sayi){
    queue* kuyruk1;
    kuyruk1->boyut = sayi;
    kuyruk1->rear = -1;
    kuyruk1->front = -1;
    kuyruk1->kuyruk = (int*)malloc(sizeof(int)*kuyruk1->boyut);
}

void enqueue(queue* qu, int sayi){
    if(qu->front == -1 && qu->rear == -1){
        qu->front++;
        qu->kuyruk[qu->front] = sayi;
        qu->rear++;
        printf("%d eklendi \n", qu->kuyruk[qu->rear]);
        //printf("front: %d ve rear: %d\n", qu->front, qu->rear);
    }else if((qu->boyut)-1 == (qu->rear)){
        printf("bu queue doldu\n");
        qu->boyut *= 2;
        int* yeniKuyruk = (int*)malloc(sizeof(int)*(qu->boyut));
        int sayac = -1;
        for(int i = qu->front; i <= qu->rear; ++i){
            sayac++;
            yeniKuyruk[sayac] = qu->kuyruk[i];
        }
        free(qu->kuyruk);
        qu->kuyruk = yeniKuyruk;
        qu->front = 0;
        qu->rear = sayac;
        qu->rear++;
        qu->kuyruk[qu->rear] = sayi;
        printf("%d eklendi \n", qu->kuyruk[qu->rear]);
        printf("front: %d ve rear: %d, boyut: %d\n", qu->front, qu->rear, qu->boyut);
        return;
    }else{
        qu->rear++;
        qu->kuyruk[qu->rear] = sayi;
        printf("%d eklendi \n", qu->kuyruk[qu->rear]);
        printf("front: %d ve rear: %d, boyut: %d\n", qu->front, qu->rear, qu->boyut);
    }

}

void dequeue(queue* qu){
    if(qu->front == -1 && qu->rear == -1){
        printf("Bu kuyruk bos!\n");
        return;
    }else if((qu->rear - qu->front) <= (qu->boyut-1)/4){
        qu->boyut /= 2;
        int* yeniKuyruk = (int*)malloc(sizeof(int)*(qu->boyut));
        int sayac = -1;
        for(int i = qu->front; i <= qu->rear; ++i){
            sayac++;
            yeniKuyruk[sayac] = qu->kuyruk[i];
        }
        free(qu->kuyruk);
        qu->kuyruk = yeniKuyruk;
        qu->front = 0;
        qu->rear = sayac;
        printf("front: %d ve rear: %d, boyut: %d\n", qu->front, qu->rear, qu->boyut);
        return;
    }
    else{
        //printf("front: %d ve rear: %d\n", qu->front, qu->rear);
        printf("%d silindi\n", qu->kuyruk[qu->front]);
        qu->front++;
    }
}

void bastir(queue* qu){
    for(int i = qu->front; i <= qu->rear; ++i){
        printf("%d ", qu->kuyruk[i]);
    }
    printf("\n");
}

int main(){
    queue* yeniKuyruk = yeniQueueOlustur(2);
    dequeue(yeniKuyruk);
    enqueue(yeniKuyruk, 10);
    enqueue(yeniKuyruk, 20);
    enqueue(yeniKuyruk, 30);
    bastir(yeniKuyruk);
    enqueue(yeniKuyruk, 40);
    enqueue(yeniKuyruk, 50);
    enqueue(yeniKuyruk, 60);
    bastir(yeniKuyruk);
    enqueue(yeniKuyruk, 70);
    bastir(yeniKuyruk);
    enqueue(yeniKuyruk, 80);
    bastir(yeniKuyruk);
    dequeue(yeniKuyruk);
    dequeue(yeniKuyruk);
    bastir(yeniKuyruk);
    dequeue(yeniKuyruk);
    dequeue(yeniKuyruk);
    dequeue(yeniKuyruk);
    bastir(yeniKuyruk);
    dequeue(yeniKuyruk);
    dequeue(yeniKuyruk);
    bastir(yeniKuyruk);
}
