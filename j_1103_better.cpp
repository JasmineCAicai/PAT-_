#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, k, p, msum = 0;

vector<int> ans, tmp;

void dfs(int last, int sum, int size) {
    if (size > k) return;
    if (size == k && last != 0) return;
    if (size == k && last == 0) {
        if (sum > msum) {
            msum = sum;
            ans = tmp;
            return;
        }
        if (sum < msum) return;
        if (sum == msum) {
            for (int i = 0; i < tmp.size(); i++) {
                if (ans[i] > tmp[i]) break;
                else if (ans[i] < tmp[i]) {
                    ans = tmp;
                    break;
                }
            }
        }
        return;
    }
    
    int now = floor(sqrt(last));
    for (int i = now; i > 0; i--) {
        if (size == 0 || i <= tmp.back()) {
            tmp.push_back(i);
            dfs(last - pow(i, p), sum + i, size + 1);
            tmp.pop_back();
        }
    }
}

int main() {
    cin >> n >> k >> p;
    
    dfs(n, 0, 0);
    
    if (ans.size() == 0) cout << "Impossible";
    else {
        cout << n << " = ";
        for (int j = 0; j < k; j++) {
            cout << ans[j] << "^" << p;
            if (j != k - 1) cout << " + ";
        }
    }
    
    cout << endl;
    return 0;
}
