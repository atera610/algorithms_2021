#include <bits/stdc++.h>

using namespace std;

void solve();

struct Pair {
    int time;
    int product;

    Pair(int time, int product) : time(time), product(product) {}

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return EXIT_SUCCESS;
}

void solve() {
    int N;
    queue<Pair> people;
    map<int, int> products;
    cin >> N;
    int type, time, prod;
    for (int i = 0; i < N; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> time >> prod;
            if (!people.empty() && people.front().product == prod) {
                Pair last_person = people.front();
                people.pop();
                cout << time - last_person.time << " ";
                bool can_move = true;
                while (can_move && !people.empty() && !products.empty()) {
                    last_person = people.front();
                    int need = last_person.product;
                    if(products.find(need) != products.end()) {
                        people.pop();
                        products[need] -= 1;
                        if(products[need] == 0) {
                            products.erase(need);
                        }
                        cout << time - last_person.time << " ";
                    } else {
                        can_move = false;
                    }
                }
            } else {
                if(products.find(prod) != products.end()) {
                    products[prod] += 1;
                } else {
                    products[prod] = 1;
                }
            }
        } else {
            cin >> time >> prod;
            people.push(Pair(time, prod));
            Pair last_person = people.front();
            int need = last_person.product;
            if(products.find(need) != products.end()) {
                people.pop();
                products[need] -= 1;
                if (products[need] == 0) {
                    products.erase(need);
                }
                cout << time - last_person.time << " ";
            }
        }
    }
    while(!people.empty()) {
        people.pop();
        cout << -1 << " ";
    }
}
