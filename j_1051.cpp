#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    
    vector<string> ans;
    
    while (k > 0) {
        stack<int> tmp;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        string s;
        int j = 0;
        for (int i = 1; i <= n; i++) {
            tmp.push(i);
            if (tmp.size() > m) {
                s = "NO";
                break;
            }
            while (!tmp.empty() && tmp.top() == nums[j]) {
                tmp.pop();
                j++;
            }
        }
        if (j == n) s = "YES";
        else s = "NO";
        ans.push_back(s);
        k--;
    }
    
    for (auto &elm : ans) {
        cout << elm << endl;
    }
    
    return 0;
}
