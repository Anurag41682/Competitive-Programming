#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve()
{
    int n,a;cin>>n>>a;
    if(n==1)
    {
        if((a&1)==1)
            cout<<"Odd"<<endl;
        else
            cout<<"Even"<<endl;
    }
    else
    {
        if((a&1)==1)
        {
            if((n&1)==0)
            {
                cout<<"Even"<<endl;
            }
            else
            {
                cout<<"Odd"<<endl;
            }
        }
        else
        {
            cout<<"Impossible"<<endl;
        }
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
