//
// Created by xukexin on 2019/4/4.
//

#ifndef INC_8SORT_TESTCLASS_H
#define INC_8SORT_TESTCLASS_H


class Sort {
protected:
    int *data;
    int dataCnt;
protected:
    int partition (int lo, int hi);
    void quiRec (int lo, int hi);
    void merge (int lo, int mid, int hi);
    void merRec (int lo, int hi);
public:
    Sort(int *data_value, int dataCnt_value);
    void show();
    void quiSort();
    void selSort();
    void insSort();
    void bubSort();
    void merSort();
    void (*sortFun)();
};

#endif //INC_8SORT_TESTCLASS_H
