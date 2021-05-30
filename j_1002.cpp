#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int k1, k2, e, i, t;
    double c;
    double n[1001]={0};
    cin >> k1;
    for(i=0; i<k1; i++){
        cin >> e >> c;
        n[e] += c;
    }
    cin >> k2;
    for(i=0; i<k2; i++){
        cin >> e >> c;
        n[e] += c;
    }
    t=0;
    for(i=0; i<1001; i++){
        if(n[i]>0) t++;
    }
    cout << t;
    for(i=1000; i>=0; i--){
        if(n[i]>0) cout << " " << i << " " << fixed << setprecision(1) << n[i];
    }
    cout << endl;
    return 0;
}
