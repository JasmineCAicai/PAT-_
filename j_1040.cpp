#include <iostream>
#include <cstring>

using namespace std;

int symmetric(string& str, int l, int r) {
    while (l >= 0 && r < str.length() && str[l] == str[r]) {
        l--;
        r++;
    }
    return r - l - 1;
}

int main() {
    string str;
    getline(cin, str);
    
    int len = 0;
    
    for (int i = 0; i < str.length(); i++) {
        int a = symmetric(str, i, i);
        int b = symmetric(str, i, i + 1);
        int tmp = a > b ? a : b;
        len = len > tmp ? len : tmp;
    }
    
    cout << len << endl;
    
    return 0;
}
