#include <bits/stdc++.h>
using namespace std;

class Student{
    friend class Management;
    friend class Query;
    friend ostream& operator <<(ostream& out, Student& _strudent);
    friend bool operator ==(const Student &a,const Student &b);
    friend bool operator <(const Student &a,const Student &b);
private:
    vector<pair<double,string>> grade; //double存储成绩 stirng存储科目
    double sum = 0; //存储所有成绩的总和，通过sum / grade.size() 来得到平均成绩
    int sun_pass = 0; //存储这个学生有多少门科目成绩小于60分
    string name;
    string birthday;
    string gender;
public:
    /*
        通过学生基本信息来构造Student类
    */
    Student(string _name,string _birthday,string _gender){
        name = _name;
        birthday = _birthday;
        gender = _gender;
    }
    /*
        通过学生基本信息与成绩来构造Student成员
    */

    Student(string _name,string _birthday,string _gender,vector<pair<double,string> >_grade):
        Student(_name,_birthday,_gender){
        grade = _grade;
        for(int i = 0; i < grade.size(); ++ i) sum += grade[i].first,sun_pass += grade[i].first < 60;
    }

    /*
        添加一门科目到当前学生的成绩表中，如果已经有相同的科目被记录，则不进行添加操作
    */
    void Add_Subjects(const string &subjects,const double &_grade){
        int flag = 0;
        for(int i = 0; i < grade.size(); ++ i){
            if(grade[i].second == subjects) flag = 1;
        }
        if(!flag){
            grade.push_back(pair<double,string>(_grade,subjects));
            sum += _grade;
            sun_pass += _grade < 60;
        }
    }

    /*
        修改学生成绩表中的一门科目成绩，如果成绩表中没有所查询科目，则不进行修改操作
    */

    void Modify_Subjects(const string &subjects,const double &_grade){
        double res = 0;
        for(int i = 0; i < grade.size(); ++ i){
            if(grade[i].second == subjects){
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

    void Delete_Subjects(const string &subjects){
        for(int i = 0; i < grade.size(); ++ i){
            if(grade[i].second == subjects){
                sum -= grade[i].first;
                sun_pass -= grade[i].first < 60;
                grade.erase(grade.begin() + i);
            }
        }
    }
};

class Manegement{
    friend class Query;
private:
    vector<Student> Students;
    int sort_flag = 0;
public:
    /*
    添加一个student类的学生到Students中,如果Students中含有这个学生，则不进行添加操作
    */
    void Add_Student(const Student &_student){
        int flag = 0;
        for(int i = 0; i < Students.size(); ++ i){
            if(_student == Students[i]) flag = 1;
        }
        if(!flag){
            Students.push_back(_student);
            sort_flag = 0;
        }
    }
    /*
        从Students中删除一个student类的学生，如果没有找到对应同学，则函数不执行删除操作
    */
    void Deleta_Student(const Student &_student){
        for(int i = 0; i < Students.size(); ++ i){
            if(_student == Students[i]){
                Students.erase(Students.begin() + i);
            }
        }
    }
    /*
        对Students进行排序，排序依据student类的<运算符
    */

    void Sort_Student(){
        if(sort_flag) return;
        sort(Students.begin(),Students.end());
        sort_flag = 1;
    }


};

class Query{
public:
    int Query_60(Manegement &_manegement)const{//查询所有学生中有科目成绩小于60的人数，且只读
        int pass_Sum = 0;
        for(int i = 0; i < _manegement.Students.size(); ++ i){
            if(_manegement.Students[i].sun_pass) pass_Sum ++;
        }
        return pass_Sum;
    }

    void Query_All_Student(Manegement &_manegement)const{ //打印所有学生的基本信息与成绩，且只读
        for(int i = 0; i < _manegement.Students.size(); ++ i){
            cout << _manegement.Students[i];
        }
    }

};




int main(){
    return 0;
}

/*student类的运算符重载*/

ostream& operator <<(ostream& out, Student& _student){
    out << "该同学姓名为" << _student.name << " 生日为" << _student.birthday;
    out <<" 性别为" << _student.gender << "\n";
    out << "该同学的各科成绩如下" << "\n";
    for(int i = 0; i < _student.grade.size(); ++ i){
        out << "该同学"  << _student.grade[i].second << "学科的成绩为";
        out << ": " << _student.grade[i].first << "\n";
    }
    out << "该同学的平均分为" << _student.sum / _student.gender.size();
    return out;
}

bool operator ==(const Student& a,const Student& b){
    if(a.name == b.name && a.birthday == b.birthday && a.gender == b.gender) return true;
    return false;
}

bool operator <(const Student &a,const Student &b){
    return a.sum < b.sum;
}
