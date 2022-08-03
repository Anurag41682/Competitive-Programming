#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
void solve() {
    vector<int> v(3);
    for (int i = 0; i < 3; i++) cin >> v[i];
    if (v[0] != v[1] && v[1] != v[2] && v[0] != v[2]) {
        cout << "NO" << endl;
    } else {
        int minn = min({v[0], v[1], v[2]});
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            if (v[i] == minn) cnt++;
        }
        if (cnt > 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
