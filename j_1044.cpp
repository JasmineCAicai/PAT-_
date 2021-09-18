#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

int n, m;
int smallest = INT_MAX;

multimap<long long, string> table;

void chain(vector<int>& diamonds, int start) {
    long long amount = 0;
    int i = start;
    for (; i < n; i++) {
        amount += diamonds[i];
        if (amount >= m) break;
    }
    string s = to_string(start + 1);
    s.push_back('-');
    s.append(to_string(i + 1));
    table.insert(make_pair(amount, s));
    if (amount >= m && smallest > amount) smallest = amount;
}

int main() {
    cin >> n >> m;
    
    vector<int> diamonds(n);
    
    for (int i = 0; i < n; i++) {
        cin >> diamonds[i];
    }
    
    for (int i = 0; i < n; i++) {
        chain(diamonds, i);
    }
    
    for (auto elm = table.begin(); elm != table.end(); elm++) {
        if (elm->first == smallest) cout << elm->second << endl;
    }
    
    return 0;
}
