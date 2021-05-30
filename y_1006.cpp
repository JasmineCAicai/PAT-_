#include <iostream>

using namespace std;

int main() {
    int n, b, s;
    cin >> n;
    b = n/100;
    n = n%100;
    for(int i=0;i<b;i++){
        cout << "B";
    }
    s = n/10;
    n = n%10;
    for(int i=0; i<s; i++){
        cout << "S";
    }
    for(int i=1; i<=n; i++){
        cout << i;
    }
    cout << endl;
    return 0;
}
