//
// Created by xukexin on 2019/4/4.
//

#include "testSort.h"

#include <iostream>
using namespace std;

int * aux = new int[50000];

void t_selSort(int * data, int N){
    int min =  0;
    for (int i = 0 ; i < N-1; i++) {
        min = i;
        for (int j = i+1; j < N; j++)
            if ( data[j] < data[min] ) min = j;
        if(min != i)
            std::swap(data[min], data[i]);
    }
}

void t_bubSort(int * data, int N){
    bool flag = false;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 1 - i; j++){
            if(data[j] > data[j+1]){
                flag = true;
                std::swap(data[j], data[j+1]);
            }
        }
        if(flag == false) break;
    }
}

void merge (int * data, int lo, int mid, int hi){

    int i = lo, j = mid + 1;

    for (int k = lo; k <= hi; k++)
        aux[k] = data[k];

    for (int k = lo; k <= hi; k++){
        if      (i > mid)           data[k] = aux[j++];
        else if (j > hi)            data[k] = aux[i++];
        else if (aux[i] < aux[j])   data[k] = aux[i++];
        else                        data[k] = aux[j++];
    }
}

void merRec (int * data, int lo, int hi){
    if (hi <= lo) return;
    int mid = (hi - lo) / 2 + lo;
    merRec (data, lo, mid);
    merRec (data, mid + 1, hi);
    merge (data, lo, mid, hi);
}

void t_merSort (int * data, int N){
    merRec (data, 0, N-1);
}


int partition (int * data, int lo, int hi){
    int i = lo, j = hi + 1;
    int v = data[lo];
    while(true){
        while(data[++i] < v) if (i == hi) break;
        while(data[--j] > v) if (j == lo) break;
        if(i >= j) break;
        std::swap(data[i], data[j]);
    }
    std::swap(data[lo], data[j]);
    return j;
}

void quiRec (int * data, int lo, int hi){
    if(hi <= lo) return;
    int j = partition (data, lo, hi);
    quiRec (data, lo, j-1);
    quiRec (data, j+1, hi);
}

void t_quiSort(int * data, int N){
    std::random_shuffle(data, data + N - 1);
    quiRec (data, 0, N-1);
}

void t_insSort(int * data, int N){
    for(int i = 1; i < N; i++){
        for(int j = i-1; j > 0 && (data[j] < data[j-1]); j--)
            std::swap(data[j], data[j-1]);
    }
}


