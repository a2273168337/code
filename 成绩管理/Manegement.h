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
    ���һ��student���ѧ����Students��,���Students�к������ѧ�����򲻽�����Ӳ���
    */
    void Add_Student(const Student& _student);
    /*
        ��Students��ɾ��һ��student���ѧ�������û���ҵ���Ӧͬѧ��������ִ��ɾ������
    */
    void Deleta_Student(const Student& _student);
    /*
        ��Students����������������student���<�����
    */

    void Sort_Student();

    //��ѯ����ѧ�����п�Ŀ�ɼ�С��60����������ֻ��
    int Query_60();
    //��ӡ����ѧ���Ļ�����Ϣ��ɼ�����ֻ��
    void Query_All_Student();

};
