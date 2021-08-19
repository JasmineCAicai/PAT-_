#include <iostream>

using namespace std;

const char sign[3] = {'A', 'B', 'C'};

string convert (int dec) {
    string ans = "00";
    ans[1] = (dec % 13) > 9 ? sign[(dec % 13) % 10] : (dec % 13) + '0';
    ans[0] = (dec / 13) > 9 ? sign[(dec / 13) % 10] : (dec / 13) + '0';
    return ans;
}

int main() {
    int r, g, b;
    string ans = "#000000", tmp;
    int color[3];
    cin >> color[0] >> color[1] >> color[2];
    
    int i = 2;
    while (i <= 6) {
        tmp = convert (color[i/2-1]);
        ans[i] = tmp[1];
        ans[i-1] = tmp[0];
        i+=2;
    }
    
    cout << ans << endl;
    
    return 0;
}
