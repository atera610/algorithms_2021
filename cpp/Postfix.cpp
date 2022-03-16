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
    vector<int> numbers;
    int first, second;
    while(cin >> s) {
        if(s == "*" or s == "+" or s == "-") {
            second = numbers.back();
            numbers.pop_back();
            first = numbers.back();
            numbers.pop_back();
            switch (s[0]) {
                case '*':
                    numbers.push_back(first * second);
                    break;
                case '+':
                    numbers.push_back(first + second);
                    break;
                case '-':
                    numbers.push_back(first - second);
                    break;
            }
        }
        else {
            numbers.push_back(stoi(s));
        }
    }
    cout << numbers.back();
}