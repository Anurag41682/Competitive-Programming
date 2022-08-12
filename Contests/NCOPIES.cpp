#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string t(n, '0');
    if (s == t) {
        cout << n * m << endl;
        return;
    }
    if (m & 1) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cnt++;
        }
        if (cnt & 1) {
            cout << 0 << endl;
            return;
        }
        int mid = cnt / 2;
        cnt = 0;
        int idx = 0;
        while (idx < n && cnt != mid) {
            if (s[idx] == '1') cnt++;
            idx++;
        }
        int ans = 1;
        while (idx < n && s[idx] != '1') {
            ans++;
            idx++;
        }
        cout << ans << endl;
    } else {
        int ans = 1;
        int idx = n - 1;
        while (s[idx] != '1') {
            idx--;
            ans++;
        }
        idx = 0;
        while (s[idx] != '1') {
            idx++;
            ans++;
        }
        cout << ans << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
