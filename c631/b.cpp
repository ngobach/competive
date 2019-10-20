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

typedef struct {
    char type;
    int id, color;
} Paint;

typedef pair<int, int> pii;
const int N = 5005;
int n, m, k, A[N][N];
pii R[N], C[N];

inline void solve() {
    cin >> n >> m >> k;
    memset(A, 0, sizeof(A));
    memset(R, 0, sizeof(R));
    memset(C, 0, sizeof(C));
    for (int i = 1; i <= k; i++) {
        int type, id;
        cin >> type >> id;
        cin >> (type == 1 ? R : C)[id].first;
        (type == 1 ? R : C)[id].second = i;
    }
    vector<pair<int, Paint>> v;
    v.reserve(n + m + 10);
    for (int i = 1; i <= n; i++) {
        if (R[i].first) {
            v.push_back({R[i].second, {1, i, R[i].first}});
        }
    }
    for (int i = 1; i <= m; i++) {
        if (C[i].first) {
            v.push_back({C[i].second, {2, i, C[i].first}});
        }
    }
    sort(v.begin(), v.end(), [](const pair<int, Paint> &u, const pair<int, Paint> &v) {
        return u.first < v.first;
    });
    for (auto x : v) {
        auto &y = x.second;
        if (y.type == 1) {
            for (int i = 1; i <= m; i++) {
                A[y.id][i] = y.color;
            }
        } else {
            for (int i = 1; i <= n; i++) {
                A[i][y.id] = y.color;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}