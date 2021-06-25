#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double num[9] = {0.0};
    double profit = 0.65, m;
    int tmp;
    char bet[3] = {'W', 'T', 'L'};
    
    for (int i=0; i<9; i+=3) {
        cin >> num[i] >> num[i+1] >> num[i+2];
    }
    
    for (int i=0; i<9; i+=3) {
        m = 0;
        tmp = 0;
        for (int j=i; j<i+3; j++) {
            if (m < num[j]) {
                m = num[j];
                tmp = j;
            }
        }
        profit *= m;
        cout << bet[tmp%3] << " ";
    }
    
    cout << fixed << setprecision(2) << (profit - 1) * 2 << endl;
    
    return 0;
}
