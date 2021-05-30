#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, s, n, t, i=0;
    char sum[20];
    cin >> a >> b;
    s = a + b;
    if(s==0) cout << s << endl;
    if(s<0) cout << "-";
    if((s<0 && s>-1000)|| (s>0 && s<1000)) cout << s << endl;
    if(s<=-1000 || s>=1000){
        n = abs(s);
        while(n!=0) {
            if(i!=3 && i!=7){
                t = n % 10;
                sum[i] = t+'0';
                n = n / 10;
            }
            else sum[i] = ',';
            i++;
        }
        for(int j=i-1; j>=0; j--) {
            cout << sum[j];
        }
    }
    
    cout << endl;
    
    return 0;
}
