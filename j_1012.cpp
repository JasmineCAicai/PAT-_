#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int id, c, m, e, a;
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Student> students(n);
    
    int i = 0;
    while (i < n) {
        int id, c, m, e;
        cin >> id >> c >> m >> e;
        students[i].id = id;
        students[i].c = c;
        students[i].m = m;
        students[i].e = e;
        students[i].a = (c + m + e) / 3;
        i++;
    }
    
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2){ return s1.a > s2.a; });
    vector<int> a_ranking(n);
    i = 0;
    while (i < n) {
        a_ranking[i] = students[i].id;
        i++;
    }
    
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2){ return s1.c > s2.c; });
    vector<int> c_ranking(n);
    i = 0;
    while (i < n) {
        c_ranking[i] = students[i].id;
        i++;
    }
    
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2){ return s1.m > s2.m; });
    vector<int> m_ranking(n);
    i = 0;
    while (i < n) {
        m_ranking[i] = students[i].id;
        i++;
    }
    
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2){ return s1.e > s2.e; });
    vector<int> e_ranking(n);
    i = 0;
    while (i < n) {
        e_ranking[i] = students[i].id;
        i++;
    }
    
    i = 0;
    vector<int> ids(m);
    while (i < m) {
        int id;
        cin >> id;
        ids[i] = id;
        i++;
    }
    
    for (i = 0; i < m; i++) {
        int j = 0, a1, c1, m1, e1;
        while (j < n && ids[i] != a_ranking[j] && ids[i] != c_ranking[j] && ids[i] != m_ranking[j] && ids[i] != e_ranking[j]) {
            j++;
        }
        if (j == n) cout << "N/A" << endl;
        else {
            if (a_ranking[j] == ids[i]) 
                cout << j + 1 << " A" << endl;
            else if (c_ranking[j] == ids[i])
                cout << j + 1 << " C" << endl;
            else if (m_ranking[j] == ids[i])
                cout << j + 1 << " M" << endl;
            else
                cout << j + 1 << " E" << endl;
        }
    }
    
    return 0;
}
