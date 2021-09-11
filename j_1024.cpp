#include <iostream>
#include <queue>

using namespace std;

long long reverseNumber(long long n) {
    long long ans;
    vector<long long> nums;
    while (n > 0) {
        nums.push_back(n%10);
        n /= 10;
    }
    long long s = nums.size();
    ans = nums[0];
    int i = 1;
    while (i < s) {
        ans *= 10;
        ans += nums[i];
        i++;
    }
    return ans;
}

bool isPalindromicNumber(long long n) {
    string str = to_string(n);

    long long lo = 0, hi = str.size() - 1;
    
    while (str[lo] == str[hi] && lo < hi) {
        lo++;
        hi--;
    }
    return lo >= hi;
}

int main() {
    long long base, step, maxSteps;
    cin >> base >> maxSteps;
    
    step = 0;
    while (base >= 10 && step <= maxSteps) {
        if (isPalindromicNumber(base)) break;
        long long tmp = base;
        base = reverseNumber(tmp);
        base += tmp;
        step++;
    }
    
    cout << base << endl;
    if (step > maxSteps) step--;
    cout << step << endl;
    
    return 0;
}
