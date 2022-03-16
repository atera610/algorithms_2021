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
    int mask = pow(2, 30) - 1;
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int first_index = 0;
    int last_index = n - 1;
    for(int i = 0; i < k; ++i) {
        if(a[first_index] < a[last_index]) {
            a[first_index] = (a[first_index] + a[last_index]) & mask;
            last_index = first_index;
            first_index = first_index == n - 1 ? 0 : first_index + 1;
        } else {
            a[last_index] = (-a[first_index] + a[last_index]) & mask;
            first_index = last_index;
            last_index = last_index == 0 ? n - 1 : last_index - 1;
        }
    }
    for(int i = first_index; i < n; ++i) {
        cout << a[i] << " ";
    }
    if (last_index < first_index) {
        for (int i = 0; i <= last_index; ++i) {
            cout << a[i] << " ";
        }
    }
}