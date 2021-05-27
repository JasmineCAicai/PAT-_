#include <iostream>

using namespace std;

int main() {
    int n, s=0;
    cin >> n;
    while(n>1){
        if(n%2==0) {
            n /= 2;
            s++;
        }
        else {
            n = (3*n+1)/2;
            s++;
        }
    }
    if(n==1) cout << s << endl;
    return 0;
}
