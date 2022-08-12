#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }
    int l = 0, r = n - 1;
    bool f = true;
    while (l <= r) {
        if (f) {
            cout << v[r] << " ";
            r--;
        } else {
            cout << v[l] << " ";
            l++;
        }
        f = !f;
    }
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
