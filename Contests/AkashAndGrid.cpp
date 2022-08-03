#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve()
{
    int n,x,y;cin>>n>>x>>y;
    if(((x&1)==1 && (y&1==1))) 
        cout<<0<<endl;
    else if( (x&1)==0 && (y&1)==0)
        cout<<0<<endl;
    else
        cout<<1<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
}
