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
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    vector<int> prefix(n + 1), suffix(n + 1);
    for (int i = 1; i <= n; i++) {  // start from 1
        prefix[i] = prefix[i - 1] + v[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {  // start from 0
        suffix[i] = suffix[i + 1] + v[i];
    }
    dbg(prefix, suffix);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (suffix[i] >= (v[i] * (n - i)) - prefix[i]) {
            break;
        }
        ans++;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
