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
    添加一门科目到当前学生的成绩表中，如果已经有相同的科目被记录，则不进行添加操作
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
    修改学生成绩表中的一门科目成绩，如果成绩表中没有所查询科目，则不进行修改操作
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
    删除学生成绩表中的一门科目成绩，如果成绩表中没有所查询科目，则不进行删除操作
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
    out << "该同学姓名为" << this->name << " 生日为" << this->birthday;
    out << " 性别为" << this->gender << "\n";
    out << "该同学的各科成绩如下" << "\n";
    for (int i = 0; i < this->grade.size(); ++i) {
        out << "该同学" << this->grade[i].second << "学科的成绩为";
        out << ": " << this->grade[i].first << "\n";
    }
    out << "该同学的平均分为" << this->sum / this->gender.size();
}

ostream& operator <<(ostream& out, Student& _student) {
    _student.print(out);
    return out;
}

int Student::res_pass_60() {
    return sun_pass;
}