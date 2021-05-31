#include <iostream>

using namespace std;

int main() {
    char n[101];
    string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string ans[3] = {"none"};
    int sum = 0, r = 0, i = 0;
    cin >> n;
    for(i = 0; n[i]!='\0'; i++) {
        sum += (n[i]-48);
    }
    i = 2;
    while(sum>0) {
        r = sum % 10;
        ans[i] = num[r];
        sum /= 10;
        i--;
    }
    for (i=0; i<3; i++) {
        if(ans[i]!="none") {
            cout << ans[i];
            if(i!=2) cout << " ";
        }
    }
    cout << endl;
    return 0;
}
