#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    int m;
    char inID[20], inTime[20]="23:59:59", outID[20], outTime[20]="00:00:00";
    char id[20], in[20], out[20];
    
    cin >> m;
    
    for (int i=0; i<m; i++) {
        cin >> id;
        cin >> in;
        cin >> out;
        if(strcmp(in,inTime) < 0) {
            strcpy(inTime,in);
            strcpy(inID,id);
        }
        if(strcmp(out,outTime) > 0) {
            strcpy(outTime,out);
            strcpy(outID,id);
        }
    }
    
    cout << inID << " " << outID << endl;
    return 0;
}
