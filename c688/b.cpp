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

char s[100005];
inline void solve() {
    cin >> s;
    cout << s;
    reverse(s, s + strlen(s));
    cout << s;
}