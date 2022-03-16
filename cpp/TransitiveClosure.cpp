#include <bits/stdc++.h>
#include "algorithm"

using namespace std;

void solve();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
#endif
    solve();
    return EXIT_SUCCESS;
}
void solve() {
    int n = 0;
    cin >> n;
    bitset<1000> dist[n];
    char c;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c;
            if (c == '1') {
                dist[i].set(j);
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if(dist[i][k]) {
                dist[i] |= dist[k];
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int val = dist[i][j] ? 1 : 0;
            cout << val;
        }
        cout << endl;
    }
}