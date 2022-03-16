#include <bits/stdc++.h>
#include "algorithm"
using namespace std;

struct Friend {
    long long  h;
    long long  l;
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
    long long  N = 0;
    long long H = 0;
    cin >> N;
    vector<Friend> friends;
    vector<bool> used(N, false);
    long long  count = 0;
    long long S = 0;
    for(long long  i = 0; i < N; ++i) {
        Friend tmp;
        cin >> tmp.h >> tmp.l;
        tmp.num = i;
        friends.push_back(tmp);
        S += tmp.h;
    }
    cin >> H;
    sort(friends.begin(), friends.end(), [](const Friend& first, const Friend& second) {
        return first.h + first.l < second.h + second.l;
    });
    auto cmp = [&](const Friend& first, const Friend& second) {
        return first.h < second.h;
    };
    priority_queue<Friend, vector<Friend>, decltype(cmp)> queue(cmp);

    for(auto &n_friend : friends) {
        if(0 <= n_friend.l + S - H) {
            used[n_friend.num] =  true;
            S -= n_friend.h;
            queue.push(n_friend);
            count ++;
        }
        else if ((!queue.empty()) && -queue.top().h < -n_friend.h &&  n_friend.l + S - H >= -queue.top().h) {
            S = S + queue.top().h - n_friend.h;
            used[queue.top().num] = false;
            used[n_friend.num] = true;
            queue.pop();
            queue.push(n_friend);
        }
    }

    cout << count << endl;
    for(Friend & el : friends) {
        if(used[el.num]) {
            cout << el.num + 1 << " ";
        }
    }
}