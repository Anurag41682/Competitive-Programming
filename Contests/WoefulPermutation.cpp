#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
void solve() {
    int n;cin>>n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n & 1) {
        cout << 1 << " " << 3 << " ";
        int a = 2, b = 5;
        for (int i = 3; i <= n; i++) {
            if (i & 1) {
                cout << a << " ";
                a += 2;
            } else {
                cout << b << " ";
                b += 2;
            }
        }
        cout << endl;
    } else {
        int a = 1, b = 2;
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                cout << b << " ";
                b += 2;
            } else {
                cout << a << " ";
                a += 2;
            }
        }
        cout << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
