#include <bits/stdc++.h>
#include "algorithm"
using namespace std;

void solve();
int visit(int u);

vector<bool> visited;
stack<int> result;
vector<vector<int>> adj;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    solve();
    return EXIT_SUCCESS;
}

int visit(int u) {
    visited[u] = true;
    for(auto v = adj[u].begin(); v !=adj[u].end(); ++v) {
        if (!visited[*v]) {
            visit(*v);
        }
    }
    if (result.size() > 0 && (find(adj[u].begin(), adj[u].end(), result.top()) == adj[u].end())) {
        return 1;
    }
    result.push(u);
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    visited.resize(n);
    adj.resize(n);
    int k, l;
    for(int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    for(int i = 0; i < m; ++i) {
        cin >> k >> l;
        adj[k - 1].push_back(l - 1);
    }
    for(int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int res = visit(i);
            if(res == 1) {
                cout << "NO";
                return;
            }
        }
    }
    if(result.size() != n) {
        cout <<"NO"<< endl;
        return;
    }
    cout <<"YES"<< endl;
    while(!result.empty()) {
        cout << result.top() + 1 << " ";
        result.pop();
    }
}



