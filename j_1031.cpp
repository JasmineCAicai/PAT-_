#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string str;
    cin >> str;
    
    int n = str.size();
    
    int k = 0, n2 = 3;
    
    if (n == 5) {
        cout << str[0] << " " << str[n-1] << endl;
        cout << str.substr(1, n-2) << endl;
        return 0;
    }
    
    while (n2 >= 3) {
        if (abs(n + 2 - 3 * (k + 1)) < abs(n + 2 - 3 * k) && (n + 2 - 2 * k - 3) >= 3 && (k + 1) <= (n + 2 - 2 * k - 3)) {
            k++;
            n2 = n + 2 - 2 * k;
        }
        else 
            break;
    }
    
    int ll = 0;
    int rr = str.size() - 1;
    for (int i = 0; i < k - 1; i++) {
        cout << str[ll];
        for (int j = 0; j < n2 - 2; j++) {
            cout << " ";
        }
        cout << str[rr] << endl;
        ll++;
        rr--;
    }
    
    while (ll <= rr) {
        cout << str[ll];
        ll++;
    }
    cout << endl;
    
    return 0;
}
