//
// Created by xukexin on 2019/4/4.
//

#include "csvProcess.h"

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void printCSV(char filename[50])
{
    // 测试是否正常写入csv文件 来自 "https://blog.csdn.net/u012234115/article/details/64465398"
    ifstream inFile(filename, ios::in);
    string lineStr;
    vector<vector<string>> strArray;
    while (getline(inFile, lineStr))
    {
    // 打印整行字符串
    cout << lineStr << endl;

    // 存成二维表结构
    stringstream ss(lineStr);
    string str;
    vector<string> lineArray;

    // 按照逗号分隔
    while (getline(ss, str, ','))
        lineArray.push_back(str);
    strArray.push_back(lineArray);
    }

}

