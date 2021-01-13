#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Merge(int* leftarray, int nL, int* rightarray, int nR, int* array){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < nL && j < nR){
        if(leftarray[i] < rightarray[j]){
            array[k] = leftarray[i];
            k++;
            i++;
        }else{
            array[k] = rightarray[j];
            k++;
            j++;
        }
    } 
    while(i < nL){
        array[k] = leftarray[i];
        k++;
        i++;
    }
    while(j < nR){
        array[k] = rightarray[j];
        k++;
        j++;
    }
};

void MergeSort(int* array, int arraysize){
    if(arraysize < 2){
        return;
    }
    else{
        int middle = (arraysize)/2;
        int* leftarray = new int[middle];
        int* rightarray = new int[arraysize - middle];
        for (int i = 0; i < middle; i++){
            leftarray[i] = array[i];
        }
        for (int i = middle; i < arraysize; i++){
            rightarray[i - middle] = array[i];
        }
        MergeSort(leftarray, middle);
        MergeSort(rightarray, arraysize - middle);
        Merge(leftarray, middle, rightarray, arraysize - middle, array);
        free(leftarray);
        free(rightarray);
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int arraysize;
    cin >> arraysize;
    int* array = new int[arraysize];
    for(int i = 0; i < arraysize; i++){
        cin>>array[i];
    }
    MergeSort(array, arraysize);
    cout<<"[";
    for(int i = 0; i < arraysize; i++){
        if(i == arraysize - 1){
            cout<<array[i]<<"]";
        }else{
            cout<<array[i]<<",";   
        }
        
    }
    cout<<endl;
    return 0;
}
