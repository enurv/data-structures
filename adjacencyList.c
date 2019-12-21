#include <stdio.h>
#include <stdlib.h>

struct adjacencyListNode{
    int dest;
    struct adjacencyListNode *next;
};

typedef struct adjacencyListNode baglantiDugumu;

struct adjacencyList{
    baglantiDugumu* baslangic;
};

typedef struct adjacencyList list;

struct Graph{
    int dugumSayisi;
    list* baglantilar;
};

typedef struct Graph graf;

graf* yeniGrafOlustur(int dugum){
    graf* yeniGraph = (graf*)malloc(sizeof(graf));
    yeniGraph->dugumSayisi = dugum;
    yeniGraph->baglantilar = (list*)malloc(sizeof(list)* dugum);
    for(int i = 0; i < dugum; i++){
        yeniGraph->baglantilar[i].baslangic = NULL;
    }
    return yeniGraph;
}

baglantiDugumu* baglantiDugumuOlustur(int varis){
    baglantiDugumu* yeniBaglanti = (baglantiDugumu*)malloc(sizeof(baglantiDugumu));
    yeniBaglanti->dest = varis;
    yeniBaglanti->next = NULL;
    return yeniBaglanti;
}

void baglantiOlustur(graf* baglantiEklenecekGraf, int kaynak, int varis){
    baglantiDugumu* yeniDugum = baglantiDugumuOlustur(varis);
    yeniDugum->next = baglantiEklenecekGraf->baglantilar[kaynak].baslangic;
    baglantiEklenecekGraf->baglantilar[kaynak].baslangic = yeniDugum;
}

void printGraph(graf* ciktialinacakGraph){
    for(int i = 0; i < ciktialinacakGraph->dugumSayisi; i++){
        printf("%d. dugumun bagli oldugu dugumler (yonlu):\n", i);
        baglantiDugumu* iter = ciktialinacakGraph->baglantilar[i].baslangic;
        if(iter == NULL){
            printf("%d. dugumden giden bir baglanti yoktur\n", i);
        }
        while(iter != NULL){
            printf("%d\n", iter->dest);
            iter = iter->next;
        }

    }
}

