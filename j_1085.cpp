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
    
    int ans = 0;
    
    sort(nums.begin(), nums.end());
    
    i = 0;
    while (i < n) {
        limit = nums[i] * p;
        int total = ans + i;
        while (total < n && nums[total] <= limit) {
            ans = ans < (total - i + 1) ? total - i + 1 : ans;
            total++;
        }
        
        i++;
    }
    
    cout << ans << endl;
    
    return 0;
}
