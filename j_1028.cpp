#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student {
    char id[10], name[10];
    int grade;
};

bool cmp1(Student a, Student b) {
    return strcmp(a.id, b.id) <= 0;
}

bool cmp2(Student a, Student b) {
    if (strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
    else return strcmp(a.id, b.id) <= 0;
}

bool cmp3(Student a, Student b) {
    if (a.grade != b.grade) return a.grade < b.grade;
    else return strcmp(a.id, b.id) <= 0;
}

int main() {
    vector<Student> students;
    Student s;
    
    int N, option;
    
    cin >> N >> option;
    
    int tmp = N;
    
    while (tmp > 0) {
        cin >> s.id >> s.name >> s.grade;
        students.push_back(s);
        tmp--;
    }
    
    if (option == 1) sort(students.begin(), students.end(), cmp1);
    else if (option == 2) sort(students.begin(), students.end(), cmp2);
    else sort(students.begin(), students.end(), cmp3);
    
    for (int i = 0; i < N; i++) {
        cout << students[i].id << " " << students[i].name << " " << students[i].grade << endl;
    }
    
    return 0;
}
