#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    int k;
    cin >> k;
    vector<int> colorings(n);
    vector<string> ans(k, "No");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> colorings[j];
        }
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (colorings[edges[j][0]] == colorings[edges[j][1]]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            sort(colorings.begin(), colorings.end());
            int len = 0, cur = 0;
            for (int j = 0; j < n; j++) {
                cur = j;
                while (cur < n && colorings[cur] == colorings[j]) {
                    cur++;
                }
                len++;
                j = cur - 1;
            }
            ans[i] = len + '0';
            ans[i].append("-coloring");
        }
    }
    
    for (int i = 0; i < k; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}
