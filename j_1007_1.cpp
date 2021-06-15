#include <iostream>
#include <memory>

using namespace std;

int main() {
    int k, b=0, e=0, sum=0, tmp, count=0;
    cin >> k;
    int* nums;
    nums = (int*)malloc(sizeof(int)*k);
    for (int i=0; i<k; i++) {
        cin >> nums[i];
        if (nums[i]<0) count++;
    }
    if (count==k) cout << "0 " << nums[0] << ' ' << nums[k-1] << endl;
    else {
        for (int i=0; i<k; i++) {
            tmp=0;
            for (int j=i; j<k; j++) {
                tmp+=nums[j];
                if (tmp>sum) {
                    sum = tmp;
                    b = nums[i];
                    e = nums[j];
                }
                else {
                    break;
                }
            }
        }
        cout << sum << ' ' << b << ' ' << e << endl;
    }
    free(nums);
    return 0;
}
