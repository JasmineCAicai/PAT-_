#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int maxn = 100;
vector<vector<int>> children(maxn);
vector<int> level(maxn);

void bfs(int root) {
    queue<int> family;
    family.push(root);
    level[root] = 1;
    while (!family.empty()) {
        int tmp = family.front();
        family.pop();
        if (children[tmp].size() > 0) {
            for (int i = 0; i < children[tmp].size(); i++) {
                family.push(children[tmp][i]);
                level[children[tmp][i]] = level[tmp] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int father, k;
        cin >> father >> k;
        for (int j = 0; j < k; j++) {
            int child;
            cin >> child;
            children[father].push_back(child);
        }
    }
    
    bfs(1);
    
    vector<int> hashtable(maxn, 0);
    for (int i = 1; i <= n; i++) {
        hashtable[level[i]]++;
    }
    
    int max_p = INT_MIN, max_level;
    
    for (int i = 1; i <= n; i++) {
        if (max_p < hashtable[i]) {
            max_p = hashtable[i];
            max_level = i;
        }
    }
    
    cout << max_p << " " << max_level << endl;
    
    return 0;
}
