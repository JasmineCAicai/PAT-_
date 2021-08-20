#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, tmp;
    string A, B;
    char a[100] = {'a'};
    char b[100] = {'a'};
    cin >> N >> A >> B;
    
    tmp = N;
    
    bool flag = true;
    
    int fla = -1, la = 0;
    int flb = -1, lb = 0;
    for (int i=0, j=0; i < A.length(); i++) {
        if (A[i] == '.') {
            fla = i;
        }
        else {
            a[j] = A[i];
            j++;
            la++;
        }
    }
    
    for (int i=0, j=0; i < B.length(); i++) {
        if (B[i] == '.') {
            flb = i;
        }
        else {
            b[j] = B[i];
            j++;
            lb++;
        }
    }
    
    if (fla != flb && fla != -1 && flb != -1) flag = false;
    else {
        for (int i = 0; i < N; i++) {
            if (a[i] != b[i]) {
                flag = false;
                break;
            }
        }
    }
    
    if (flag) {
        cout << "YES ";
        if (A.length() == 1 && A[0] == '0') cout << "0" << endl;
        else {
            cout << "0.";
            for (int i=0; i<N; i++) {
                cout << a[i];
            }
            cout << "*10^";
            if (fla != -1 || flb !=-1) cout << max(fla,flb) << endl;
            else cout << max(la,lb) << endl;
        }
    }
    else {
        cout << "NO ";
        if (A.length() == 1 && A[0] == '0') cout << "0";
        else {
            cout << "0.";
            for (int i=0; i<N; i++) {
                cout << a[i];
            }
            cout << "*10^";
            if (fla != -1) cout << fla;
            else cout << la;
        }
        
        if (B.length() == 1 && B[0] == '0') cout << "0" << endl;
        else {
            cout << " 0.";
            for (int i=0; i<N; i++) {
                cout << b[i];
            }
            cout << "*10^";
            if (flb != -1) cout << flb << endl;
            else cout << lb << endl;
        }
    }
    
    return 0;
}
