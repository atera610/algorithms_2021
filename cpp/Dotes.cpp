#include <bits/stdc++.h>
#include "algorithm"
using namespace std;

void solve();
int deadlines(int* result, int* indexes, int* deadlines, int* time, int N, int  start, int current_time);
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
struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};
void solve() {
    int N;
    int inf = 100000;
    cin >> N;
    int x, y;
    double cost[N][N];
    double dist[N];
    double total_weight = 0;
    bool used[N];
    int prev[N];
    vector<Point> points;
    vector<pair<int, int>> result;
    for(int i = 0; i < N; ++i) {
        cin >> x >> y;
        points.push_back(Point(x, y));
        dist[i] = inf;
        prev[i] = -1;
        used[i] = false;
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cost[i][j] =  sqrt((points[i].x - points[j].x)*(points[i].x - points[j].x) + (points[i].y - points[j].y)*(points[i].y - points[j].y));
        }
    }
    dist[0] = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto element = q.top();
        q.pop();
        int v = element.second;
        if(used[v]) {
            continue;
        }
        for(int i = 0; i < N; ++i) {
            if(used[i] || dist[i] == 0 || i == v) {
                continue;
            }
            if(dist[i] == inf) {
                dist[i] = cost[v][i];
                q.push({cost[v][i], i});
                prev[i] = v;
            } else if (dist[i] > cost[v][i]) {
                q.push({cost[v][i], i});
                dist[i] = cost[v][i];
                prev[i] = v;
            }
        }
        if(v != 0) {
            total_weight += cost[v][prev[v]];
            result.push_back({v, prev[v]});
            used[v] = true;
            used[prev[v]] = true;
        }
    }
    cout.precision(6);
    cout << fixed << total_weight << endl;
    cout << result.size() << endl;
    for(auto v : result) {
        cout << v.first + 1 << " " << v.second + 1 << endl;
    }
}