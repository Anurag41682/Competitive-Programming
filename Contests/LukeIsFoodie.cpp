#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
void solve() {
    int n, x;
    cin >> n >> x;
    int minn = INT_MAX, maxx = INT_MIN;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        minn = min(v[i], minn);
        maxx = max(v[i], maxx);
        int mid = (minn + maxx) / 2;
        if (abs(minn - mid) > x || abs(maxx - mid) > x) {
            minn = v[i];
            maxx = v[i];
            ans++;
        }
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
