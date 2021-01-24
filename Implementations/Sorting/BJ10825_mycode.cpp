#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct student{
    int korean;
    int english;
    int math;
    string name;
};

bool cmp_func(student u, student v){
    if(u.korean>v.korean){
        return true;
    }
    else if(u.korean==v.korean){
        if(u.english<v.english){
            return true;
        }
        else if(u.english==v.english){
            if(u.math>v.math){
                return true;
            }
            else if(u.math==v.math){
                if(u.name<v.name){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){

    int num;
    cin >> num;

    vector<student>student_list(num);
    for(int k=0;k<num;k++){
        cin >> student_list[k].name >> student_list[k].korean >> student_list[k].english >> student_list[k].math;
    }

    sort(student_list.begin(),student_list.end(),cmp_func);

    for(int k=0;k<num;k++){
        cout << student_list[k].name << '\n';
    }

    return 0;
}