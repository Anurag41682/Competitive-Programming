#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
void solve() {
int n,k;cin>>n>>k;
vector<int>v(n);
for(int i=0;i<n;i++)cin>>v[i];
int ans=0;
for(int i=0;i<k;i++){
    if(v[i]>k)ans++;
}
cout<<ans<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
