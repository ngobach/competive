// MacOS Fix
#ifndef LOCAL
#include <bits/stdc++.h>
#else

#include "../stdcpp.h"

#endif

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void solve();

int main() {
#ifdef LOCAL
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

vector<int> v[3];
int n;

inline void solve() {
    cin >> n;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        v[t - 1].push_back(i + 1);
    }
    int cnt = min(v[0].size(), min(v[1].size(), v[2].size()));
    cout << cnt << '\n';
    while (cnt--) {
        for (auto &vv : v) {
            cout << vv.back() << ' ';
            vv.pop_back();
        }
        cout << '\n';
    }
}