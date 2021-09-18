#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, p, limit;
    cin >> n >> p;
    vector<long long> nums(n);
    
    int i = 0;
    while (i < n) {
        cin >> nums[i];
        i++;
    }
    
    vector<int> ans(n);
    
    sort(nums.begin(), nums.end());
    
    i = 0;
    while (i < n) {
        limit = nums[i] * p;
        int total = n - 1;
        while (total > i && nums[total] > limit) {
            total--;
        }
        ans[i] = (total - i + 1);
        i++;
    }
    
    //sort(ans.begin(), ans.end(), [](const int a, const int b){ return a > b; });
    long long max_value = -1;
    for (i = 0; i < n; i++) {
        max_value = max_value < ans[i] ? ans[i] : max_value;
    }
    
    //cout << ans[0] << endl;
    cout << max_value << endl;
    
    return 0;
}
