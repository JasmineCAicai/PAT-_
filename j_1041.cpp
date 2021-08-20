#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int *arr;
    int *tmp;
    arr = (int*)malloc(sizeof(int) * N);
    tmp = (int*)malloc(sizeof(int) * 10 * 10 * 10 * 10 * 2);
    
    int i = 0;
    while (i < 20000) {
        tmp[i] = 0;
        i++;
    }
    
    i = 0;
    while (i < N) {
        cin >> arr[i];
        tmp[arr[i]]++;
        i++;
    }
    
    i = 0;
    
    while (i < N) {
        if (tmp[arr[i]] == 1) break;
        i++;
    }
    
    if (i < N) cout << arr[i] << endl;
    else cout << "None" << endl;
        
    return 0;
}
