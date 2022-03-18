#pragma once
#include <vector>
#include <iostream>
using namespace std;


class Student {
private:
    vector<pair<double, string>> grade; //double�洢�ɼ� stirng�洢��Ŀ
    double sum = 0; //�洢���гɼ����ܺͣ�ͨ��sum / grade.size() ���õ�ƽ���ɼ�
    int sun_pass = 0; //�洢���ѧ���ж����ſ�Ŀ�ɼ�С��60��
    string name;
    string birthday;
    string gender;
public:
    Student(string _name, string _birthday, string _gender);
    Student(string _name, string _birthday, string _gender, vector<pair<double, string> >_grade);

    /*
        ���һ�ſ�Ŀ����ǰѧ���ĳɼ����У�����Ѿ�����ͬ�Ŀ�Ŀ����¼���򲻽�����Ӳ���
    */
    void Add_Subjects(const string& subjects, const double& _grade);

    /*
        �޸�ѧ���ɼ����е�һ�ſ�Ŀ�ɼ�������ɼ�����û������ѯ��Ŀ���򲻽����޸Ĳ���
    */

    void Modify_Subjects(const string& subjects, const double& _grade);

    /*
        ɾ��ѧ���ɼ����е�һ�ſ�Ŀ�ɼ�������ɼ�����û������ѯ��Ŀ���򲻽���ɾ������
    */
    void Delete_Subjects(const string& subjects);
    bool operator ==(const Student& a);
    bool operator <(const Student& b);
    //�����ṩ��ӡ˽����Դ�Ľӿ�
    void print(ostream& out);
    //�����ṩpass_60˽�����ԵĽӿ�
    int res_pass_60();
};
ostream& operator <<(ostream& out, Student& _student);