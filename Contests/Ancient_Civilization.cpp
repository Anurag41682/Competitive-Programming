#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve()
{
    int n,l;cin>>n>>l;
    vector<vector<bool>>vec(n,vector<bool>(l,0));
    for(int i=0;i<n;i++)
    {
        int temp;cin>>temp;int j=l-1;
        while(temp!=0)
        {
            if((temp&1)==1)
                vec[i][j]=1;
            temp=temp>>1;
            j--;
        }
    }  
    vector<int>sum(l,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<l;j++)
        {
            sum[j]+=vec[i][j];
        }
    }
    for(int i=0;i<l;i++)
    {
        if((n-sum[i])<sum[i])
        {
            sum[i]=1;
        }
        else
        {
            sum[i]=0;
        }
    }
    int ans=0;
    for(int i=0;i<l;i++)
    {
        ans+=sum[i]*pow(2,l-i-1);
    }
    cout<<ans<<endl;
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
