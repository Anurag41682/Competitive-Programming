#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (!(a % b)) {
        a = a / b;
        b = 1;
    }
    if (!(c % d)) {
        c = c / d;
        d = 1;
    }
    int first = c * b;
    int second = d * a;
    int maxx = max(first, second);
    int minn = min(first, second);
    if (maxx == minn) {
        cout << 0 << endl;
    } else if (maxx == 0 || minn == 0) {
        cout << 1 << endl;
    } else if (maxx % minn == 0) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
