#pragma once
#include "Manegement.h"
#include "Student.h"
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void Manegement::Add_Student(const Student& _student) {
    int flag = 0;
    for (int i = 0; i < Students.size(); ++i) {
        if (Students[i] == _student) flag = 1;
    }
    if (!flag) {
        Students.push_back(_student);
        sort_flag = 0;
    }
}
/*
    从Students中删除一个student类的学生，如果没有找到对应同学，则函数不执行删除操作
*/
void Manegement::Deleta_Student(const Student& _student) {
    for (int i = 0; i < Students.size(); ++i) {
        if (Students[i] == _student) {
            Students.erase(Students.begin() + i);
        }
    }
}
/*
    对Students进行排序，排序依据student类的<运算符
*/

void Manegement::Sort_Student() {
    if (sort_flag) return;
    sort(Students.begin(), Students.end());
    sort_flag = 1;
}

int Manegement::Query_60(){//查询所有学生中有科目成绩小于60的人数，且只读
    int pass_Sum = 0;
    for (int i = 0; i < Students.size(); ++i) {
        if (Students[i].res_pass_60()) pass_Sum++;
    }
    return pass_Sum;
}

void Manegement::Query_All_Student(){ //打印所有学生的基本信息与成绩，且只读
    for (int i = 0; i < Students.size(); ++i) {
        cout << Students[i];
    }
}


