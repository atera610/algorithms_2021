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
    vector<pair <int, int>> cities_counts;
    int temp;
    for(int i = 1; i <= N; ++i) {
        cin >> temp;
        cities_counts.push_back(pair(i, temp));
    }
    auto comparator = [](pair<int, int> const & first, pair<int, int> const& second) {
        return first.second == second.second ? first.first < second.first : first.second < second.second;
    };
    sort(cities_counts.begin(), cities_counts.end(), comparator);
    int q;
    cin >> q;
    int left, right, x;
    for(int i = 0; i < q; ++i) {
        cin >> left >> right >> x;
        auto lower_ind = lower_bound(cities_counts.begin(), cities_counts.end(), pair(left, x), comparator);
        auto upper_ind = upper_bound(cities_counts.begin(), cities_counts.end(), pair(right, x), comparator);
        if (lower_ind->first == upper_ind->first) {
            cout << 0;
        } else {
            cout << 1;
        }
    }
}