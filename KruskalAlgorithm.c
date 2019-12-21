#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void yerDegistir(int dizi[], int x, int y) {
    int temp = dizi[x];
    dizi[x] = dizi[y];
    dizi[y] = temp;
}

void bubbleSort(int dizi[], int diziBoyutu){
    for(int i = 0; i < diziBoyutu; ++i){
        for(int j = 0; j < diziBoyutu - 1; ++j){
            if(dizi[j] > dizi[j+1]){
                yerDegistir(dizi, j, j+1);
            }
        }
    }
}

struct Baglanti{
    int src;
    int dst;
    int weight;
};
typedef struct Baglanti baglanti;

struct Graph{
    int dugumSayisi;
    int baglantiSayisi;
    baglanti* baglantiListesi;
};
typedef struct Graph graph;

graph* graphOlustur(int v, int e){
    graph* yeniGraph = (graph*)malloc(sizeof(graph));
    yeniGraph->baglantiSayisi = e;
    yeniGraph->baglantiListesi = (baglanti*)malloc(sizeof(baglanti)*e);
    return yeniGraph;
}

void printBaglanti(graph* taranacak){
    printf("Source Destination Weight\n");
    for(int i = 0; i < taranacak->baglantiSayisi; i++){
        printf("%d  %d  %d\n", taranacak->baglantiListesi[i].src, taranacak->baglantiListesi[i].dst, taranacak->baglantiListesi[i].weight);
    }
}

int* baglantiAgirligiSirala(graph* Graph){
    int* siralanmisAgirlik = (int*)malloc(sizeof(int)* Graph->baglantiSayisi);
    for(int i = 0; i < Graph->baglantiSayisi; ++i){
        siralanmisAgirlik[i] = Graph->baglantiListesi[i].weight;
    }
    bubbleSort(siralanmisAgirlik, Graph->baglantiSayisi);
    /*printf("Siralanmis agirlik: \n");
    for(int i = 0; i < Graph->baglantiSayisi; ++i){
        printf("%d ", siralanmisAgirlik[i]);
    }*/
    return siralanmisAgirlik;
}

baglanti find(graph* Graph, int weight){
    for(int i = 0; i < Graph->baglantiSayisi; ++i){
        if(Graph->baglantiListesi[i].weight == weight){
            return Graph->baglantiListesi[i];
        }
    }
    return;
}

void Kruskal(graph* taranacakGraph){
    int* siralanmisAgirlik = baglantiAgirligiSirala(taranacakGraph);
    int* visited = (int*)malloc(sizeof(int)*taranacakGraph->dugumSayisi);
    printf("Minimum Spanning Tree\nSRC DST WGT\n");
    int visitedIndex = 0;
    for(int i = 0; i < taranacakGraph->baglantiSayisi; ++i){
        if(i == 0){
            baglanti eklenecek = find(taranacakGraph, siralanmisAgirlik[i]);
            visited[0] = eklenecek.src;
            visited[1] = eklenecek.dst;
            printf("%d  %d  %d\n", visited[0], visited[1], eklenecek.weight);
            visitedIndex = 2;
        }else{
            baglanti eklenecek = find(taranacakGraph, siralanmisAgirlik[i]);
            bool ziyaretEdildi = false;
            for(int j = 0; j < visitedIndex; ++j){
                if(visited[j] == eklenecek.dst){
                    for(int k = 0; k < visitedIndex; ++k){
                        if(visited[k] == eklenecek.src){
                            ziyaretEdildi = true;
                            break;
                        }
                    }
                }
            }
            if(!ziyaretEdildi){
                visited[visitedIndex] = eklenecek.src;
                visitedIndex++;
                visited[visitedIndex] = eklenecek.dst;
                printf("%d  %d  %d\n", eklenecek.src, eklenecek.dst, eklenecek.weight);
                visitedIndex++;
                /*printf("visited: ");
                for(int k = 0; k < visitedIndex; ++k){
                    printf("%d ", visited[k]);
                }
                printf("\n");*/
            }
        }
    }
}

int main(){

    graph* Graph = graphOlustur(4, 5);

    Graph->baglantiListesi[0].src = 0;
    Graph->baglantiListesi[0].dst = 1;
    Graph->baglantiListesi[0].weight = 10;

    Graph->baglantiListesi[1].src = 0;
    Graph->baglantiListesi[1].dst = 2;
    Graph->baglantiListesi[1].weight = 6;

    Graph->baglantiListesi[2].src = 0;
    Graph->baglantiListesi[2].dst = 3;
    Graph->baglantiListesi[2].weight = 5;

    Graph->baglantiListesi[3].src = 1;
    Graph->baglantiListesi[3].dst = 3;
    Graph->baglantiListesi[3].weight = 15;

    Graph->baglantiListesi[4].src = 2;
    Graph->baglantiListesi[4].dst = 3;
    Graph->baglantiListesi[4].weight = 4;

    printBaglanti(Graph);

    Kruskal(Graph);


}
