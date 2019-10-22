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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

typedef pair<int, int> pii;

const int N = 2005;
const int M = 1 << 9;
const int MASK = M - 1;
int n, dd[N][M];
pii A[N];

inline pii getAt(int idx) {
    if (idx < 0) {
        return pii(0, 0);
    }
    return A[idx];
}

inline void solve() {
    cin >> n;
    map<int, int> mp;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        mp[t]++;
    }
    t = 0;
    for (const auto &p : mp) {
        A[t++] = p;
    }
    memset(dd, 0, sizeof(dd));
    int ans = 0;
    int bl = 0; // blacklist
    int k;
    for (int i = 0; i < t; i++) {
        #ifdef LOCAL
        cerr << "** i = " << i << " " << "A[i] (" << A[i].first << ", " << A[i].second << ")\n";
        #endif
        if (!i) {
            // First iteration
            dd[i][1] = A[0].second;
            continue;
        }
        bl = 0;
        for (int j = 1; j <= 9; j++) {
            auto x = getAt(i - j);
            if (!x.second) {
                continue;
            }
            auto diff = A[i].first - x.first;
            if (diff == 1 || diff == 9 || diff == 8) {
                bl |= 1 << j;
            }
        }
        for (int j = 0; j < M; j++) {
            k = (j<<1) & MASK;
            dd[i][k] = max(dd[i-1][j], dd[i][k]);
            ans = max(ans, dd[i][k]);
        }
        for (int j = 0; j < M; j++) {
            if ((j << 1) & bl) {
                continue;
            }
            k = (j<<1 | 1) & MASK;
            dd[i][k] = max(dd[i-1][j] + A[i].second, dd[i][k]);
            ans = max(ans, dd[i][k]);
        }
        #ifdef LOCAL
        cerr << "Ans at " << i << " = " << ans << "\n";
        #endif
    }
    cout << n - ans;
}
