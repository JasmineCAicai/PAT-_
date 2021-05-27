#include <iostream>

using namespace std;

char sum[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int origin;

void print(int s) {
    if (s < 10) {
        cout << sum[s] << ' ';
        return;
    }
    int a = s%10;
    print(s/10);
    if(s == origin) cout << sum[a] << endl;
    else {
        cout << sum[a] << ' ';
        return;
    }
}

int main() {
    int i = 0, s = 0;
    char num[10000];
    cin >> num;
    while(num[i]!='\0'){
        s  += num[i] - 48;
        i++;
    }
    origin = s;
    print(s);
    return 0;
}
