#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int maxx=max(a,max(b,c));
    int minn=min(a,min(b,c));
    int mid=a+b+c-maxx-minn;
    if(a==b)
    {
        if((c&1)==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else if(b==c)
    {
        if((a&1)==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else if(a==c)
    {
        if((b&1)==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
    {
        int maxx=max(a,max(b,c));
        int minn=min(a,min(b,c));
        int mid=a+b+c-maxx-minn;
        if(maxx-mid==minn)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
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
