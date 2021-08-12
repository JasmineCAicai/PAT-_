#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct stu
{
    string name,id;
    char gender;
    int grade;
}s[10000],a,b;

int main()
{
    int n;
    cin >> n;
    
    a.grade = -1;
    b.grade = 101;
    
    for(int i = 0;i < n; i++)
    {
        cin >> s[i].name >> s[i].gender >> s[i].id >> s[i].grade;
        if(s[i].gender == 'F' && s[i].grade > a.grade) a = s[i];
        if(s[i].gender == 'M' && s[i].grade < b.grade) b = s[i];
    }
    if(a.grade != -1) cout << a.name << ' ' << a.id << endl;
    else cout << "Absent" << endl;
    if(b.grade != 101) cout << b.name << ' ' << b.id << endl;
    else cout << "Absent" << endl;
    if(a.grade != -1 && b.grade != 101) cout << a.grade - b.grade << endl;
    else cout << "NA" << endl;
    
    return 0;
}
