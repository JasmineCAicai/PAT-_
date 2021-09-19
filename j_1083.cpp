#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name, id;
    int grade;
};

int main() {
    int n;
    cin >> n;
    
    vector<Student> students(n);
    int i = 0;
    while (i < n) {
        Student s;
        cin >> s.name >> s.id >> s.grade;
        students[i] = s;
        i++;
    }
    
    int lower, upper;
    cin >> lower >> upper;
    
    sort(students.begin(), students.end(), [](Student s1, Student s2){ return s1.grade > s2.grade; });
    int start = -1, end = -1;
    for (i = 0; i < n; i++) {
        if (students[i].grade >= lower && students[i].grade <= upper) {
            if (start == -1) start = i;
            end = i;
        }
    }
    
    if (start == -1) cout << "NONE" << endl;
    else {
        for (i = start; i <= end; i++) {
            cout << students[i].name << " " << students[i].id << endl;
        }
    }
    return 0;
}
