#pragma once
#include "Student.h"
#include <vector>
#include <iostream>
using namespace std;

class Manegement {
private:
    vector<Student> Students;
    int sort_flag = 0;
public:
    /*
    添加一个student类的学生到Students中,如果Students中含有这个学生，则不进行添加操作
    */
    void Add_Student(const Student& _student);
    /*
        从Students中删除一个student类的学生，如果没有找到对应同学，则函数不执行删除操作
    */
    void Deleta_Student(const Student& _student);
    /*
        对Students进行排序，排序依据student类的<运算符
    */

    void Sort_Student();

    //查询所有学生中有科目成绩小于60的人数，且只读
    int Query_60();
    //打印所有学生的基本信息与成绩，且只读
    void Query_All_Student();

};
