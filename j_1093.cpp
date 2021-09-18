#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string str;
    
    int p = 0, t = 0, ans = 0;
    
    cin >> str;
    
    int len = str.length();
    
    for (int i = 0; i < len; i++) {
        if (str[i] == 'T') t++;
    }
    
    for (int i = 0; i < len; i++) {
        if (str[i] == 'P') p++;
        else if (str[i] == 'T') t--;
        else ans = (ans + (p * t) % 1000000007) % 1000000007;
    }
    
    cout << ans << endl;
    
    return 0;
}
