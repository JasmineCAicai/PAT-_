#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N, tmp;
    cin >> N;
    tmp = N;
    string name, pwd;
    string ans[1000] = {""};
    int j = 0, total = 0;
    while (tmp > 0) {
        cin >> name >> pwd;
        string pwdTmp = pwd;
        for (int i = 0; i < pwd.length(); i++) {
            if (pwd[i] == '1') pwd[i] = '@';
            else if (pwd[i] == '0') pwd[i] = '%';
            else if (pwd[i] == 'l') pwd[i] = 'L';
            else if (pwd[i] == 'O') pwd[i] = 'o';
        }
        if (pwd != pwdTmp) {
            ans[j++] = name + " " + pwd;
            total++;
        }
        tmp--;
    }
    j = 0;
    if (total > 0) cout << total << endl;
    else {
        if (N == 1) cout << "There is 1 account and no account is modified" << endl;
        else cout << "There are " << N << " accounts and no account is modified" << endl;
    }
    while (j < total) {
        cout << ans[j++] << endl;
    }
    return 0;
}
