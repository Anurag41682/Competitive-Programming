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
        cin >> v[i];
    }
    vector<int> rm(n + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (rm[v[i]] == -1) {
            rm[v[i]] = i;
        }
    }
    int ans = 0;
    int maxr = INT_MIN;
    vector<bool> check(n + 1, false);
    for (int i = n - 1; i > 0; i--) {
        if (v[i] < v[i - 1]) {
            i--;
            for (; i >= 0; i--) {
                maxr = max(rm[v[i]], maxr);
            }
        }
    }
    for (int i = maxr; i >= 0; i--) {
        if (!check[v[i]]) {
            ans++;
            check[v[i]] = true;
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
