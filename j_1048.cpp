#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    sort(coins.begin(), coins.end());
    
    int l = 0, r = n - 1;
    
    while (l < r) {
        int tmp = coins[l] + coins[r];
        if (tmp == m) break;
        else if (tmp > m) r--;
        else l++;
    }
    
    if (l >= r) cout << "No Solution" << endl;
    else cout << coins[l] << " " << coins[r] << endl;
    
    return 0;
}
