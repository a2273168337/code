#pragma once
#include "Student.h"

Student::Student(string _name, string _birthday, string _gender) {
    name = _name;
    birthday = _birthday;
    gender = _gender;
}
Student::Student(string _name, string _birthday, string _gender, vector<pair<double, string> >_grade) :
    Student(_name, _birthday, _gender) {
    grade = _grade;
    for (int i = 0; i < grade.size(); ++i) sum += grade[i].first, sun_pass += grade[i].first < 60;
}

/*
    ���һ�ſ�Ŀ����ǰѧ���ĳɼ����У�����Ѿ�����ͬ�Ŀ�Ŀ����¼���򲻽�����Ӳ���
*/
void Student::Add_Subjects(const string& subjects, const double& _grade) {
    int flag = 0;
    for (int i = 0; i < grade.size(); ++i) {
        if (grade[i].second == subjects) flag = 1;
    }
    if (!flag) {
        grade.push_back(pair<double, string>(_grade, subjects));
        sum += _grade;
        sun_pass += _grade < 60;
    }
}

/*
    �޸�ѧ���ɼ����е�һ�ſ�Ŀ�ɼ�������ɼ�����û������ѯ��Ŀ���򲻽����޸Ĳ���
*/

void Student::Modify_Subjects(const string& subjects, const double& _grade) {
    double res = 0;
    for (int i = 0; i < grade.size(); ++i) {
        if (grade[i].second == subjects) {
            sun_pass -= grade[i].first < 60;
            sum -= grade[i].first;
            sum += _grade;
            grade[i].first = _grade;
            sun_pass += _grade < 60;
        }
    }
}

/*
    ɾ��ѧ���ɼ����е�һ�ſ�Ŀ�ɼ�������ɼ�����û������ѯ��Ŀ���򲻽���ɾ������
*/

void Student::Delete_Subjects(const string& subjects) {
    for (int i = 0; i < grade.size(); ++i) {
        if (grade[i].second == subjects) {
            sum -= grade[i].first;
            sun_pass -= grade[i].first < 60;
            grade.erase(grade.begin() + i);
        }
    }
}
bool Student::operator ==(const Student& a) {
    if (this->name == a.name && this->birthday == a.birthday && this->gender == a.gender) return true;
    return false;
}

bool Student::operator <(const Student& b) {
    return this->sum < b.sum;
}

void  Student::print(ostream& out) {
    out << "��ͬѧ����Ϊ" << this->name << " ����Ϊ" << this->birthday;
    out << " �Ա�Ϊ" << this->gender << "\n";
    out << "��ͬѧ�ĸ��Ƴɼ�����" << "\n";
    for (int i = 0; i < this->grade.size(); ++i) {
        out << "��ͬѧ" << this->grade[i].second << "ѧ�Ƶĳɼ�Ϊ";
        out << ": " << this->grade[i].first << "\n";
    }
    out << "��ͬѧ��ƽ����Ϊ" << this->sum / this->gender.size();
}

ostream& operator <<(ostream& out, Student& _student) {
    _student.print(out);
    return out;
}

int Student::res_pass_60() {
    return sun_pass;
}