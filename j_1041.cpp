#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int *arr;
    int *tmp;
    int *origin;
    arr = (int*)malloc(sizeof(int) * N);
    origin = (int*)malloc(sizeof(int) * N);
    tmp = (int*)malloc(sizeof(int) * 10 * 10 * 10 * 10);
    
    int i = 0;
    while (i < N) {
        cin >> arr[i];
        origin[i] = arr[i];
        tmp[arr[i]] = i;
        i++;
    }
    
    sort(arr,arr+N);
    
    i = 0;
    int j = 0;
    int unique = 200000;
    
    while (i < N) {
        i++;
        while (arr[j] == arr[i]) {
            i++;
        }
        j = i;
        if (arr[j] == arr[i+1]) continue;
        if (unique > tmp[arr[i]]) unique = tmp[arr[i]];
    }
    
    cout << origin[unique] << endl;
        
    return 0;
}
