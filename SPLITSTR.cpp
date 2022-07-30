#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    int cnt1 = 0, cnt0 = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
    }
    int diff = abs(cnt1 - cnt0);
    diff = diff / k + (diff % k > 0);
    cout << diff << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
