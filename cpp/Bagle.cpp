#include <bits/stdc++.h>
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
    int n, w;
    cin >> n >> w;
    int coins[n];
    int coin_count = 0;
    std::map<int,int> coins_to_count;
    for(int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    std::sort(coins, coins + n);
    int i = n - 1;
    while(w != 0 && i > -1) {
        if(w >= coins[i]) {
            coins_to_count[coins[i]] = w / coins[i];
            coin_count += w / coins[i];
            w = w % coins[i];
        }
        --i;
    }
    cout << coin_count << endl;
    for (auto pair : coins_to_count) {
        for(int i = 0; i < pair.second; ++i) {
            cout << pair.first << " ";
        }
    }
}