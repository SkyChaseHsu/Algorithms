//
// Created by xukexin on 2019/4/4.
//

#ifndef INC_8SORT_TESTSORT_H
#define INC_8SORT_TESTSORT_H

void t_selSort(int * data, int N);

void t_bubSort(int * data, int N);

void merge (int * data, int lo, int mid, int hi);
void merRec (int * data, int lo, int hi);
void t_merSort (int * data, int N);

int partition (int * data, int lo, int hi);
void quiRec (int * data, int lo, int hi);
void t_quiSort(int * data, int N);

void t_insSort(int * data, int N);

#endif //INC_8SORT_TESTSORT_H
