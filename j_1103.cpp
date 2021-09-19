#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    
    vector<int> factors(k);
    vector<long long> total(k,0);
    long long avg = n / k;
    long long max_base = 0;
    
    while (pow(max_base,p) < avg) {
        max_base++;
    }
    
    for (int i = 0; i < k; i++) {
        factors[i] = max_base;
        if (i == 0) total[i] = pow(factors[i], p);
        else total[i] = total[i-1] + pow(factors[i], p);
    }
    
    if (total[k-1] > n) {
        for (int i = k - 1; i >= 0; i--) {
            int prev;
            while (factors[i] > 0 && total[k-1] > n) {
                prev = factors[i];
                factors[i]--;
                total[k-1] = total[k-1] - (pow(prev, p) - pow(factors[i], p));
            }
            if (factors[i] == 0 && total[k-1] != n) {
                factors[i]++;
                total[k-1] = total[k-1] + pow(factors[i], p);
            }
            else if (total[k-1] == n) break;
            if (i == 0 && total[k-1] != n) {
                cout << "Impossible";
                break;
            }
            factors[i] = prev;
        }
    }
    else if (total[k-1] < n) {
        for (int i = 0; i < k; i++) {
            int prev;
            while (factors[i] < n && total[k-1] < n) {
                prev = factors[i];
                factors[i]++;
                total[k-1] = total[k-1] + (pow(factors[i], p) - pow(prev, p));
            }
            if (total[k-1] > n) {
                prev = factors[i];
                factors[i]--;
                total[k-1] = total[k-1] - (pow(prev, p) - pow(factors[i], p));
            }
            else if (total[k-1] == n) break;
            if (i == k - 1 && total[k-1] != n) {
                cout << "Impossible";
                break;
            }
            factors[i] = prev;
        }
    }
    
    if (total[k-1] == n) {
        cout << n << " = ";
        for (int j = 0; j < k; j++) {
            cout << factors[j] << "^" << p;
            if (j != k - 1) cout << " + ";
        }
    }
    
    cout << endl;
    return 0;
}
