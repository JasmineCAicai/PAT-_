#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>
#include <map> 
#include <set>

using namespace std;

int m, n, k;
struct node {
	int v1;
	int v2;
}; 
	
int main() {
	
	cin >> n >> m;
	vector<node> no(m);
	for(int i=0; i<m; i++){
		cin >> no[i].v1 >> no[i].v2;
	}
	cin >> k;
	while (k--) {
		set<int> ans;
		int a[10009] = {0};
		bool key = true;
		for(int j=0; j<n; j++){
			cin >> a[j];
			ans.insert(a[j]);
		}
		for(int l = 0; l < m; l++){
			if (a[no[l].v1] == a[no[l].v2]) {
				key = false;
				break;
			}
		}
		if (key)
			cout << ans.size() << "-coloring" << endl;
		else
			cout << "No" << endl;
		ans.clear();
	}
	
	return 0;
} 
