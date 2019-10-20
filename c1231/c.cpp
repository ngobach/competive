// MacOS Fix
#ifndef LOCAL
#include <bits/stdc++.h>
#else
#include "stdcpp.h"
#endif

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int solve();

int main() {
#ifdef LOCAL
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return solve();
}

const int N = 505;
int n, m, a[N][N];

inline int solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = n - 2; i > 0; i--) {
        for (int j = m - 2; j > 0; j--) {
            if (!a[i][j]) {
                a[i][j] = min(a[i + 1][j], a[i][j + 1]) - 1;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] <= a[i][j - 1] || a[i][j] <= a[i - 1][j]) {
                cout << -1;
                return 0;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += a[i][j];
        }
    }
#ifdef LOCAL
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
#endif
    cout << ans;
    return 0;
}