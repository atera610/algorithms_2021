#include <bits/stdc++.h>
#include "algorithm"
using namespace std;

struct Friend {
    long long  a;
    long long  b;
    long long  num;
};

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
    long long  n = 0;
    long long a0 = 0;
    cin >> n >> a0;
    vector<Friend> friends[2];
    vector<bool> used(n, false);
    long long  count = 0;
    for(long long  i = 0; i < n; ++i) {
        Friend tmp;
        cin >> tmp.a >> tmp.b;
        tmp.num = i;
        friends[int (tmp.b < 0)].push_back(tmp);
    }
    sort(friends[0].begin(), friends[0].end(), [](const Friend& first, const Friend& second) {
        return first.a < second.a;
    });

    for(auto &p_friend : friends[0]) {
        if(p_friend.a <= a0) {
            a0 += p_friend.b;
            used[p_friend.num] = true;
            count ++;
        }
        else break;

    }
    sort(friends[1].begin(), friends[1].end(), [](const Friend& first, const Friend& second) {
        return first.a + first.b > second.a + second.b;
    });
    auto cmp = [&](const Friend& first, const Friend& second) {
        return first.b > second.b;
    };
    priority_queue<Friend, vector<Friend>, decltype(cmp)> queue(cmp);

    for(auto &n_friend : friends[1]) {
        if(n_friend.a <= a0) {
            used[n_friend.num] =  true;
            a0 += n_friend.b;
            queue.push(n_friend);
            count ++;
        }
        else if ((!queue.empty()) && queue.top().b < n_friend.b && a0 - queue.top().b >= n_friend.a) {
            a0 = a0 - queue.top().b + n_friend.b;
            used[queue.top().num] = false;
            used[n_friend.num] = true;
            queue.pop();
            queue.push(n_friend);
        }
    }

    cout << count << endl;
    for(int i = 0; i < 2; ++i) {
        for(Friend & el : friends[i]) {
            if(used[el.num]) {
                cout << el.num + 1 << " ";
            }
        }
    }
}