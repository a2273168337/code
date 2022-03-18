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
    ��Students��ɾ��һ��student���ѧ�������û���ҵ���Ӧͬѧ��������ִ��ɾ������
*/
void Manegement::Deleta_Student(const Student& _student) {
    for (int i = 0; i < Students.size(); ++i) {
        if (Students[i] == _student) {
            Students.erase(Students.begin() + i);
        }
    }
}
/*
    ��Students����������������student���<�����
*/

void Manegement::Sort_Student() {
    if (sort_flag) return;
    sort(Students.begin(), Students.end());
    sort_flag = 1;
}

int Manegement::Query_60(){//��ѯ����ѧ�����п�Ŀ�ɼ�С��60����������ֻ��
    int pass_Sum = 0;
    for (int i = 0; i < Students.size(); ++i) {
        if (Students[i].res_pass_60()) pass_Sum++;
    }
    return pass_Sum;
}

void Manegement::Query_All_Student(){ //��ӡ����ѧ���Ļ�����Ϣ��ɼ�����ֻ��
    for (int i = 0; i < Students.size(); ++i) {
        cout << Students[i];
    }
}


