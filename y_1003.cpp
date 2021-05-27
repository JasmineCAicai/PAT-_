#include <iostream>
#include <cstring>

using namespace std;

int findChar(char c, char s[], int l, int r) {
    int i = l;
    while(s[i]!=c && i<r) {
        i++;
    }
    if(i==r) i=-1;
    return i;
}

int main() {
    int n, p, t, x, y, z, length;
    char s[102];
    cin >> n;
    while(n>0){
        cin >> s;
        length = strlen(s);
        p = findChar('P', s, 0, length);
        t = findChar('T', s, p+1, length);
        if(p==-1 || t==-1 || t==p+1 || t>=p+4) {
            if(n-1==0) cout << "NO";
            else cout << "NO" << endl;
            n--;
            continue;
        }
        x = -1;
        y = -1;
        z = -1;
        for(char i='B'; i<='Z'; i++){
            x = findChar(i, s, 0, p);
            y = findChar(i, s, p+1, t);
            z = findChar(i, s, t+1, length);
            if(x!=-1 || y!=-1 || z!=-1){
                if(n-1==0) cout << "NO";
                else cout << "NO" << endl;
                n--;
                break;
            }
        }
        if(x!=-1 || y!=-1 || z!=-1) continue;
        x = -1;
        y = -1;
        z = -1;
        for(char i='a'; i<='z'; i++){
            x = findChar(i, s, 0, p);
            y = findChar(i, s, p+1, t);
            z = findChar(i, s, t+1, length);
            if(x!=-1 || y!=-1 || z!=-1){
                if(n-1==0) cout << "NO";
                else cout << "NO" << endl;
                n--;
                break;
            }
        }
        if(x!=-1 || y!=-1 || z!=-1) continue;
        if(x==-1 || y==-1 || z==-1){
            if(n-1==0) cout << "YES";
            else cout << "YES" << endl;
            n--;
        }
    }
    return 0;
}
