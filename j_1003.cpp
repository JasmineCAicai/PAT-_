#include <iostream>
#define Maxn 10000

using namespace std;

int map[500][500] = {0};

int main() {
    int N, M, C1, C2;
    cin >> N >> M >> C1 >> C2;
    int rescue[N], Point[N] = {0}, value[N], line[N] = {0};
    bool S[N] = {false};
    for(int i=0; i<N; i++) {
        cin >> rescue[i];
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i==j) map[i][j] = 0;
            else map[i][j] = Maxn;
        }
        if(i==C1) {
            line[i] = 1;
            value[i] = 0;
            Point[i] = rescue[i];
        }
        else value[i] = Maxn;
    }
    for(int i=0; i<M; i++) {
        int c1, c2, l;
        cin >> c1 >> c2 >> l;
        map[c1][c2] = l;
        map[c2][c1] = l;
    }
    while(1) {
        int t = Maxn, temp = -1;
        for(int i=0; i<M; i++) {
            if(S[i]==true) continue;
            if(value[i]<t) {
                t = value[i];
                temp = i;
            }
        }
        if(t==Maxn || temp==C2) break;
        S[temp] = true;
        for(int i=0; i<N; i++) {
            if(S[i]==true) continue;
            if(value[i]>(value[temp]+map[temp][i])) {
                value[i] = value[temp]+map[temp][i];
                Point[i] = Point[temp]+rescue[i];
                line[i] = line[temp];
            }
            else if(value[i]==(value[temp]+map[temp][i])) {
                if(Point[i]<Point[temp]+rescue[i]) {
                    Point[i] = Point[temp]+rescue[i];
                }
                line[i] = line[i]+line[temp];
            }
        }
    }
    cout << line[C2] << " " << Point[C2] << endl;
    return 0;
}
