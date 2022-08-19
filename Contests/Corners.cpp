#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
bool zeroes = false;
int fun(vector<string>& v) {
    int n = v.size(), cnt = 0;
    int m = v[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '1') {
                cnt++;
            } else {
                zeroes = true;
            }
        }
    }
    return cnt;
}
bool check(vector<string>& v) {
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '0') {
                // up

                if (i - 1 >= 0 && v[i - 1][j] == '0') {
                    return true;
                }
                // down
                if (i + 1 < n && v[i + 1][j] == '0') {
                    return true;
                }
                // left
                if (j - 1 >= 0 && v[i][j - 1] == '0') {
                    return true;
                }
                // right
                if (j + 1 < m && v[i][j + 1] == '0') {
                    return true;
                }
            }
            if (v[i][j] == '1') {
                // up

                if (i - 1 >= 0 && v[i - 1][j] == '0') {
                    // left
                    if (j - 1 >= 0 && v[i][j - 1] == '0') {
                        return true;
                    }
                    // right
                    if (j + 1 < m && v[i][j + 1] == '0') {
                        return true;
                    }
                }
                // down
                if (i + 1 < n && v[i + 1][j] == '0') {
                    // left
                    if (j - 1 >= 0 && v[i][j - 1] == '0') {
                        return true;
                    }
                    // right
                    if (j + 1 < m && v[i][j + 1] == '0') {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int cnt1 = fun(v);
    if (check(v)) {
        cout << cnt1 << endl;
    } else {
        if (zeroes) {
            cout << max(0LL, cnt1 - 1) << endl;
        } else {
            cout << cnt1 - 2 << endl;
        }
    }
    zeroes = false;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
