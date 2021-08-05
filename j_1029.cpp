#include <iostream>

using namespace std;

int main() {
    int size1, size2;
    cin >> size1;
    long int* s1 = (long int*) malloc (sizeof(long int) * size1);
    for (int i=0; i<size1; i++) 
        cin >> s1[i];
    cin >> size2;
    long int* s2 = (long int*) malloc (sizeof(long int) * size2);
    for (int i=0; i<size2; i++) 
        cin >> s2[i];
    long int* s3 = (long int*) malloc (sizeof(long int) * (size1 + size2));
    int a=0, b=0, index=-1;
    while (a < size1 && b < size2) {
        s1[a] < s2[b] ? s3[++index] = s1[a++] : s3[++index] = s2[b++];
    }
    while (a < size1) {
        s3[++index] = s1[a++];
    }
    while (b < size2) {
        s3[++index] = s2[b++];
    }
    cout << s3[index/2];
    return 0;
}
