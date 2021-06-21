#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, sum = 0, tmp = 0;
    int * num;
    cin >> N;
    num = (int*)malloc(sizeof(int)*N);
    for (int i=0; i<N; i++) {
        cin >> num[i];
    }
    sum = sum + N*5;
    sum = sum + num[0]*6;
    for (int i=1; i<N; i++){
        tmp = num[i] - num[i-1];
        if (tmp >= 0) {
            sum = sum + tmp * 6;
        }
        else {
            sum = sum + abs(tmp)*4;
        }
    }
    cout << sum << endl;
    return 0;
}
