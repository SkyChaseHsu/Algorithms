//
// Created by xukexin on 2019/4/4.
//

#include "sortClass.h"

#include <iostream>
#include <vector>
using namespace std;

Sort::Sort(int *data_value, int dataCnt_value)
{
    data = data_value;
    dataCnt = dataCnt_value;
}

//  Show the whole array in line
void Sort::show()
{
    for (int i = 0; i < dataCnt; i++)
        cout<<data[i]<<" ";
    cout<<endl;
}

//  set the partition point
int Sort::partition (int lo, int hi){
    int i = lo,  j = hi + 1;
    int v = data[lo];
    while (1){
        while (data[++i] < v);
        while (v < data[--j]);
        if (i >= j) break;
        std::swap(data[i], data[j]);
    }
    std::swap(data[lo], data[j]);
    return j;
}

//  quick sort recrusion
void Sort::quiRec (int lo, int hi)
{
    if (hi <= lo) return;
    int j = partition (lo, hi);
    quiRec (lo, j-1);
    quiRec (j+1, hi);
}

//  interface of quick sort
void Sort::quiSort()
{
    int lo = 0;
    int hi = dataCnt - 1;
//    std::random_shuffle(data,data+dataCnt);
    quiRec (lo, hi);
}

//  interface of selection sort
void Sort::selSort()
{
    int min =  0;
    for (int i = 0 ; i < dataCnt-1; i++) {
        min = i;
        for (int j = i+1; j < dataCnt; j++)
            if (data[j] < data[min]) min = j;
        if(min != i) std::swap(data[min], data[i]);
    }
}

//  interface of insert sort
void Sort::insSort()
{
    for (int i = 1; i < dataCnt; i++){
        for(int j = i; j > 0 && data[j] < data[j-1]; j--){
            std::swap(data[i], data[j]);
        }
    }
}

//  interface of buble sort
void Sort::bubSort()
{
    bool flag = 0;
    for(int i = 0; i < dataCnt; i++){
        for(int j = 0; j < dataCnt - 1 - i; j++){
            if(data[j+1] < data[j]){
                flag = 1;
                std::swap(data[j], data[j+1]);
            }
        }
        if(!flag) break;
    }

}

void Sort::merge (int lo, int mid, int hi)
{
    int i = lo;
    int j = mid+1;
    int cnt = hi-lo+1;
    auto * aux = new int[cnt];

    for (int k = lo; k <= hi; k++)
        aux[k] = data[k];

    for (int k = lo; k <= hi; k++){
        if (i > mid)                        data[k] = aux[j++];
        else if (j > hi)                    data[k] = aux[i++];
        else if (aux[i] < aux[j])           data[k] = aux[i++];
        else                                data[k] = aux[j++];
    }

    delete []aux;
}

void Sort::merRec (int lo, int hi)
{
    if (hi < lo) return;
    int mid = (hi - lo) / 2 + lo;
    merRec(lo, mid);
    merRec(mid + 1, hi);
    merge(lo, mid, hi);
}

void Sort::merSort ()
{
    cout<<"Good day, mate!";
    merRec(0, dataCnt-1);
}
