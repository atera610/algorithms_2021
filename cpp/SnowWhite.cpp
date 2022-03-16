#include <bits/stdc++.h>
#include "algorithm"
using namespace std;

void solve();
void deadlines(int* result, int* indexes, int* deadlines, int* time, int N);
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

void deadlines(int* result, int* indexes, int* deadlines, int* time, int N) {
    sort(indexes, indexes + N, [&](const int& i, const int& j) {
        return (deadlines[i] > deadlines[j]);
    });
    int current_time = deadlines[indexes[0]];
    for(int i = 0; i < N; ++i) {
        if(current_time - time[indexes[i]] < 1) {
            result[0] = -1;
            return;
        }
        current_time -= time[indexes[i]];
        result[i] = indexes[i];
    }
}

void solve() {
    int n;
    cin >> n;
    int indexes[n];
    int a[n];
    int b[n];
    for(int i = 0; i < n; ++i){
        indexes[i] = i;
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        b[i] += a[i];
    }
    int result[n];
    deadlines(result, indexes, b, a, n);
    if(result[0] == -1) {
        cout << -1;
        return;
    }

    for(int i = 0; i < n; ++i) {
        cout << result[i] + 1 << " ";
    }
}