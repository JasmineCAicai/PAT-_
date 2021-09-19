#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    string shop, buy;
    cin >> shop >> buy;
    
    vector<int> digits(10,0);
    map<char, int> lowerAlpha;
    map<char, int> upperAlpha;
    
    char lower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char upper[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    for (int i = 0; i < 26; i++) {
        lowerAlpha[lower[i]] = 0;
        upperAlpha[upper[i]] = 0;
    }
    
    for (int i = 0; i < buy.length(); i++) {
        if (isdigit(buy[i])) digits[buy[i] - '0']++;
        else {
            if (isupper(buy[i])) upperAlpha[buy[i]]++;
            else lowerAlpha[buy[i]]++;
        }
    }
    
    int remain = 0;
    int len = 0;
    
    for (int i = 0; i < shop.length(); i++) {
        if (isdigit(shop[i]) && digits[shop[i] - '0'] != 0) {
            digits[shop[i] - '0']--;
            len++;
        }
        else if (isupper(shop[i]) && upperAlpha[shop[i]] != 0) {
            upperAlpha[shop[i]]--;
            len++;
        }
        else if (lowerAlpha[shop[i]] != 0) {
            lowerAlpha[shop[i]]--;
            len++;
        }
        if (len == buy.length()) break;
    }
    
    remain = buy.length() - len;
    if (remain == 0) cout << "Yes " << shop.length() - len << endl;
    else cout << "No " << remain << endl;
    
    return 0;
}
