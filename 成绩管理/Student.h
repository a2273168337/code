#pragma once
#include <vector>
#include <iostream>
using namespace std;


class Student {
private:
    vector<pair<double, string>> grade; //double存储成绩 stirng存储科目
    double sum = 0; //存储所有成绩的总和，通过sum / grade.size() 来得到平均成绩
    int sun_pass = 0; //存储这个学生有多少门科目成绩小于60分
    string name;
    string birthday;
    string gender;
public:
    Student(string _name, string _birthday, string _gender);
    Student(string _name, string _birthday, string _gender, vector<pair<double, string> >_grade);

    /*
        添加一门科目到当前学生的成绩表中，如果已经有相同的科目被记录，则不进行添加操作
    */
    void Add_Subjects(const string& subjects, const double& _grade);

    /*
        修改学生成绩表中的一门科目成绩，如果成绩表中没有所查询科目，则不进行修改操作
    */

    void Modify_Subjects(const string& subjects, const double& _grade);

    /*
        删除学生成绩表中的一门科目成绩，如果成绩表中没有所查询科目，则不进行删除操作
    */
    void Delete_Subjects(const string& subjects);
    bool operator ==(const Student& a);
    bool operator <(const Student& b);
    //对外提供打印私有资源的接口
    void print(ostream& out);
    //对外提供pass_60私有属性的接口
    int res_pass_60();
};
ostream& operator <<(ostream& out, Student& _student);