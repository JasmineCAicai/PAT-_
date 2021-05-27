#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int n, grade, gGrade = 0, lGrade = 1000, i;
    char name[15], id[15], gName[15], gID[15], lName[15], lID[15];
    cin >> n;
    while(n>0){
        cin >> name >> id >> grade;
        if (grade >= gGrade){
            i = 0;
            while(name[i]!='\0'){
                gName[i] = name[i];
                i++;
                gName[i] = '\0';
            }
            i = 0;
            while(id[i]!='\0'){
                gID[i] = id[i];
                i++;
                gID[i] = '\0';
            }
            gGrade = grade;
        }
        
        if (grade < lGrade){
            i = 0;
            while(name[i]!='\0'){
                lName[i] = name[i];
                i++;
                lName[i] = '\0';
            }
            i = 0;
            while(id[i]!='\0'){
                lID[i] = id[i];
                i++;
                lID[i] = '\0';
            }
            lGrade = grade;
        }
        n--;
    }
    
    cout << gName << " " << gID << endl;
    cout << lName << " " << lID << endl;
    return 0;
}
