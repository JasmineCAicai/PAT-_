#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    int id;
    int virtue;
    int talent;
};

bool compare(const Person& p1, const Person& p2) {
    int t1 = p1.virtue + p1.talent;
    int t2 = p2.virtue + p2.talent;
    
    if (t1 != t2) return t1 > t2;
    if (p1.virtue != p2.virtue) return p1.virtue > p2.virtue;
    return p1.id < p2.id;
}

int main() {
    int total, filtered, bound1, bound2;
    vector<Person> sage;
    vector<Person> noblemen;
    vector<Person> foolmen;
    vector<Person> restmen;
    
    cin >> total >> bound1 >> bound2;
    
    filtered = 0;
    while (total > 0) {
        int id, virtue, talent;
        cin >> id >> virtue >> talent;
        
        if (virtue >= bound1 && talent >= bound1) {
            Person person;
            person.id = id;
            person.virtue = virtue;
            person.talent = talent;
            if (virtue >= bound2 && talent >= bound2) sage.push_back(person);
            else if (virtue >= bound2 && talent < bound2) noblemen.push_back(person);
            else if (virtue < bound2 && talent < bound2 && virtue >= talent) foolmen.push_back(person);
            else restmen.push_back(person);
            filtered++;
        }
        total--;
    }
    
    cout << filtered << endl;
    
    sort(sage.begin(), sage.end(), compare);
    sort(noblemen.begin(), noblemen.end(), compare);
    sort(foolmen.begin(), foolmen.end(), compare);
    sort(restmen.begin(), restmen.end(), compare);
    
    for (const Person& p : sage) {
        cout << p.id << " " << p.virtue << " " << p.talent << endl;
    }
    
    for (const Person& p : noblemen) {
        cout << p.id << " " << p.virtue << " " << p.talent << endl;
    }
    
    for (const Person& p : foolmen) {
        cout << p.id << " " << p.virtue << " " << p.talent << endl;
    }
    
    for (const Person& p : restmen) {
        cout << p.id << " " << p.virtue << " " << p.talent << endl;
    }
    
    return 0;
}
