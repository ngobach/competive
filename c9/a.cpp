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

template <typename T> T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}

int a, b;
inline void solve() {
    cin >> a >> b;
    a = 7 - max(a, b);
    if (!a) {
        cout << "1/1";
        return;
    }
    b = gcd(a, 6);
    cout << a / b << '/' << 6 / b;
}