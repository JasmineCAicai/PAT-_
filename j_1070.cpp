#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Mooncake {
    int d;
    double p;
    double k;
};

int main() {
    int n, max_demand;
    cin >> n >> max_demand;
    
    vector<Mooncake> mooncakes(n);
    
    int i = 0;
    while (i < n) {
        cin >> mooncakes[i].d;
        i++;
    }
    i = 0;
    while (i < n) {
        cin >> mooncakes[i].p;
        mooncakes[i].k = mooncakes[i].p / mooncakes[i].d;
        i++;
    }
    
    sort(mooncakes.begin(), mooncakes.end(), [](const Mooncake& m1, const Mooncake& m2){ return m1.k > m2.k; });
    
    double total = 0.00;
    i = 0;
    while (max_demand > 0) {
        if (max_demand >= mooncakes[i].d) {
            total += mooncakes[i].p;
            max_demand -= mooncakes[i].d;
        }
        else {
            total += (mooncakes[i].k * max_demand);
            max_demand -= (((mooncakes[i].k * max_demand) / mooncakes[i].p) * mooncakes[i].d);
        }
        i++;
    }
    
    cout << fixed << setprecision(2) << total << endl;
    
    return 0;
}
