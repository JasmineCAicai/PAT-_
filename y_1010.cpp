#include <iostream>

using namespace std;

int main() {
    
    int a, b, i;
    
    i = 1;
    
    while(cin >> a >> b) {
        if (b>0) {
            if (i==1) {
                cout << a*b << " " << b-1;
                i--;
            }
            else {
                cout << " " << a*b << " " << b-1;
            }
        }
        if (i==1) {
            cout << "0 0";
        }
    }
    
    cout << endl;
    
    return 0;
}
