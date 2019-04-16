#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

#include "sortClass.h"
#include "testSort.h"
#include "csvProcess.h"

int main(){

    double costTime, aveCostTime;

    // 存储排序类型名称 选择排序、冒泡排序、合并排序、快速排序、插入排序
    // string sortName[4] = {"SELSORT", "BUBSORT", "QUISORT", "INSSORT", };

    // 排序函数的类成员函数指针 选择排序、冒泡排序、合并排序、快速排序、插入排序
    //void (Sort::*sortFun[])() = {&Sort::selSort, &Sort::bubSort, &Sort::quiSort,  &Sort::insSort,};

    // 排序函数的普通函数指针 选择排序、冒泡排序、合并排序、快速排序、插入排序
    string t_sortName[5] = {"SELSORT", "BUBSORT", "MERSORT", "QUISORT", "INSSORT", };
    void  (*t_sortFun[])(int *data, int N) = {&t_selSort, &t_bubSort, &t_merSort, &t_quiSort, &t_insSort};

    // 写入csv文件
    ofstream outFile01;
    outFile01.open("expriData01.csv", ios::out);
    outFile01 << "TYPE OF SORT" << ',' << "N" << ',' << "Time(ms)" << endl;

    ofstream outFile02;
    outFile02.open("expriData02.csv", ios::out);
    outFile02 << "TYPE OF SORT" << ',' << "N" << ',' << "Time(ms)" << endl;

    for(int f = 0; f < 5; f++) {
        for (int N = 10000; N <= 50000; N += 10000) {
            // 分配内存
            int *data = new int[N];

            // 初始化每趟消耗时间
            costTime = 0;

            for (int i = 1; i <= 20; i++) {

                // 文件重定向，从testdata中读入测试数据
                char filename[50];
                sprintf(filename, "./testdata/N=%d_%d.txt", N, i);
                freopen(filename, "r", stdin);
                for (int n = 0; n < N; n++)
                    cin >> data[n];

                // 定义排序对象
                Sort a(data, N);

                // 时钟计时开始
                clock_t start, finish;

                start = clock();

                // sort函数指针依次执行
                // (a.*sortFun[f])();
                (*t_sortFun[f])(data, N);

                // 时钟计时结束
                finish = clock();

                // 单次消耗时间累加
                costTime += (double) (finish - start) * 1000 / CLOCKS_PER_SEC;
            }

            // 平均消耗时间
            aveCostTime = costTime / 20;

            // shell中打印出数据
            cout << "["<<t_sortName[f]<<"]" << " \t| N = " << N << " | TIMECOST: " << setprecision(4) << aveCostTime << " \tms" << endl;

            // 将数据写入csv
            if (t_sortName[f].compare("MERSORT") == 0 || t_sortName[f].compare("QUISORT") == 0)
                outFile01 << t_sortName[f] << ',' << N << ',' << aveCostTime <<endl;
            else
                outFile02 << t_sortName[f] << ',' << N << ',' << aveCostTime <<endl;

            // 回收内存
            delete[]data;
        }
    }

    // 关闭文件写入
    outFile01.close();
    outFile02.close();

    return 0;
}