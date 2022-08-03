#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve()
{
    int n,k;cin>>n>>k;
    int cnt=k;
    if(k*2-1<=n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i&1)==0 && i==j && cnt>0)
                   { cout<<"R";cnt--;}
                else
                    cout<<".";
            }cout<<endl;
        }
    }
    else
        cout<<-1<<endl;
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
