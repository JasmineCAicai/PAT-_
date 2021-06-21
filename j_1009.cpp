#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int * n1;
    int *n2;
    double * a1;
    double * a2;
    int k1, k2;
    double result[2001] = {0};
    
    // Input line 1
    cin >> k1;
    n1 = (int*)malloc(sizeof(int)*k1);
    a1 = (double*)malloc(sizeof(double)*k1);
    for (int i=0; i<k1; i++) {
        cin >> n1[i] >> a1[i];
    }
    
    // Input line 2
    cin >> k2;
    n2 = (int*)malloc(sizeof(int)*k2);
    a2 = (double*)malloc(sizeof(double)*k2);
    for (int i=0; i<k2; i++) {
        cin >> n2[i] >> a2[i];
    }
    
    // Compute values
    for (int i=0; i<k1; i++) {
        for (int j=0; j<k2; j++) {
            result[n1[i]+n2[j]] += (a1[i]*a2[j]);
        }
    }
    
    int count = 0;
    for (int i=2000; i>0; i--) {
        if (result[i]!=0) count++;
    }
    cout << count;
    for (int i=2000; i>0; i--) {
        if (result[i]==0) continue;
        cout << " " << i << " " << fixed << setprecision(1) << result[i];
    }
    cout << endl;
    
    return 0;
}
