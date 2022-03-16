#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return EXIT_SUCCESS;
}


void solve() {
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a + N);
    int K;
    cin >> K;
    int left, right;
    int left_index, right_index = -1;

    for(int i = 0; i < K; ++i) {
        cin >> left >> right;
        left_index = right_index = -1;
        left_index = lower_bound(a, a + N, left) - a;
        right_index = upper_bound(a, a + N, right) - a;
        cout << right_index - left_index << ' ';

    }
}