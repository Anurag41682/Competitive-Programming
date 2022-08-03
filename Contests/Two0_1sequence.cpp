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
    string a, b;
    cin >> a >> b;
    int szb = b.size(), sza = a.size();
    if (szb > sza) {
        cout << "NO" << endl;
        return;
    }
    bool flag = true;
    for (int i = sza - 1; i > sza - szb; i--) {
        if (a[i] != b[i - (sza - szb)]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        if (a[sza - szb] != b[0]) {
            flag = false;
            for (int i = 0; i < sza - szb; i++) {
                if (a[i] == b[0]) flag = true;
            }
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    } else {
        cout << "NO" << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
