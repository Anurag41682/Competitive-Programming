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
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        mp[t]++;
    }
    int sz = mp.size();
    if (sz == 1) {
        cout << mp.begin()->second / 2 + (mp.begin()->second & 1) << endl;
    } else {
        int firstcnt = 0, secondcnt = 0;
        vector<int> temp;
        for (auto it : mp) {
            temp.push_back(it.second);
        }
        sort(temp.begin(), temp.end(), greater<int>());
        firstcnt = temp[0], secondcnt = temp[1];
        if (firstcnt / 2 < secondcnt) {
            cout << secondcnt << endl;
        } else {
            cout << firstcnt / 2 + (firstcnt & 1) << endl;
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
