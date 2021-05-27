#include <iostream>
#include <memory.h>

using namespace std;

void arrInsertDegress(int* arr, int num, int value) {
    int i=0, j;
    if(num==0) arr[0] = value;
    else {
        while(i<num) {
            if(arr[i] < value) {
                for(j=num-1; j>=i; j--){
                    arr[j+1] = arr[j];
                }
                arr[i] = value;
                return;
            }
            i++;
        }
        arr[i] = value;
    }
}

int main() {
    int num=0, i, j;
    cin >> num;
    int* arr = (int*)malloc(sizeof(int)*num);
    int* nonKey = (int*)malloc(sizeof(int)*num);
    memset(nonKey, 0, sizeof(int)*num);
    for(i=0; i!=num; i++) {
        cin >> arr[i];
    }
    int value;
    int nonKeyCnt = 0;
    for(i=0; i!=num; i++) {
        if(nonKey[i]==0) {
            value = arr[i];
            while(value!=1) {
                value = (value%2 == 0) ? value/2 : (value*3+1)/2;
                for(j=0; j!=num; j++) {
                    if(nonKey[j]==0 && arr[j]==value) {
                        nonKey[j] = 1;
                        nonKeyCnt++;
                    }
                }
            }
        }
    }
    int* key = (int*)malloc(sizeof(int)*(num-nonKeyCnt));
    for(i=0,j=0; i!=num; i++) {
        if(nonKey[i]==0) arrInsertDegress(key,j++,arr[i]);
    }
    for(i=0; i!=j; i++) {
        cout << key[i];
        if(i!=j-1) cout << " ";
    }
    cout << endl;
    return 0;
}
