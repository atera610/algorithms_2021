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
    string s;
    getline(cin, s);
    auto beginning = -1;
    auto end = -1;
    auto i = 0;

    while(beginning == -1 and i < s.length()) {
        if(s[i] != ' ') {
            beginning = i - 1;
        }
        i++;
    }
    i = s.length() - 1;
    while(end == -1 and i > -1) {
        if(s[i] != ' ') {
            end = i;
        }
        i--;
    }
    beginning = beginning == -1 ? 0 : beginning;
    end = end == -1 ? s.length() - 1 : end;

    auto prev_char = s[beginning];
    string result;
    for(i = beginning; i <= end; i++) {
        if(s[i] == ' ' and prev_char == ' '){
            continue;
        }
        prev_char = s[i];
        result.push_back(s[i]);
    }
    cout << result;
}