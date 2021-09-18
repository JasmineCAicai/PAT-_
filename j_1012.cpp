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
    
    int r;
    
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2){ return s1.a > s2.a; });
    vector<vector<int>> a_ranking(n, vector<int>(2));
    i = 0;
    r = 1;
    while (i < n) {
        int tmp = i + 1, next = 1;
        a_ranking[i][0] = students[i].id;
        a_ranking[i][1] = r;
        while (tmp < n && students[i].a == students[tmp].a) {
            a_ranking[tmp][0] = students[tmp].id;
            a_ranking[tmp][1] = r;
            tmp++;
            next++;
        }
        r += next;
        i = tmp;
    }
    
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2){ return s1.c > s2.c; });
    vector<vector<int>> c_ranking(n, vector<int>(2));
    i = 0;
    r = 1;
    while (i < n) {
        int tmp = i + 1, next = 1;
        c_ranking[i][0] = students[i].id;
        c_ranking[i][1] = r;
        while (tmp < n && students[i].c == students[tmp].c) {
            c_ranking[tmp][0] = students[tmp].id;
            c_ranking[tmp][1] = r;
            tmp++;
            next++;
        }
        r += next;
        i = tmp;
    }
    
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2){ return s1.m > s2.m; });
    vector<vector<int>> m_ranking(n, vector<int>(2));
    i = 0;
    r = 1;
    while (i < n) {
        int tmp = i + 1, next = 1;
        m_ranking[i][0] = students[i].id;
        m_ranking[i][1] = r;
        while (tmp < n && students[i].m == students[tmp].m) {
            m_ranking[tmp][0] = students[tmp].id;
            m_ranking[tmp][1] = r;
            tmp++;
            next++;
        }
        r += next;
        i = tmp;
    }
    
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2){ return s1.e > s2.e; });
    vector<vector<int>> e_ranking(n, vector<int>(2));
    i = 0;
    r = 1;
    while (i < n) {
        int tmp = i + 1, next = 1;
        e_ranking[i][0] = students[i].id;
        e_ranking[i][1] = r;
        while (tmp < n && students[i].e == students[tmp].e) {
            e_ranking[tmp][0] = students[tmp].id;
            e_ranking[tmp][1] = r;
            tmp++;
            next++;
        }
        r += next;
        i = tmp;
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
        int j = 0;
        while (j < n && ids[i] != a_ranking[j][0] && ids[i] != c_ranking[j][0] && ids[i] != m_ranking[j][0] && ids[i] != e_ranking[j][0]) {
            j++;
        }
        if (j == n) cout << "N/A" << endl;
        else {
            if (a_ranking[j][0] == ids[i]) 
                cout << a_ranking[j][1] << " A" << endl;
            else if (c_ranking[j][0] == ids[i])
                cout << c_ranking[j][1] << " C" << endl;
            else if (m_ranking[j][0] == ids[i])
                cout << m_ranking[j][1] << " M" << endl;
            else
                cout << e_ranking[j][1] << " E" << endl;
        }
    }
    
    return 0;
}
