#include <iostream>
#include <memory>

using namespace std;

int main() {
    int k, p=0, b=0, e=0, sum=-1, tmp=0;
    cin >> k;
    int* nums;
    nums = (int*)malloc(sizeof(int)*k);
    for (int i=0; i<k; i++) {
        cin >> nums[i];
    }
    for (int i=0; i<k; i++) {
        tmp += nums[i];
        if(tmp < 0) {
            tmp = 0;
            p = i+1;
        }
        else if(tmp > sum) {
            sum = tmp;
            b = p;
            e = i;
        }
    }
    if(sum<0) sum=0;
    cout << sum << ' ' << nums[b] << ' ' << nums[e] << endl;
    free(nums);
    return 0;
}
