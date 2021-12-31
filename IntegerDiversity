#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve()
{
    int n;cin>>n;
    int ans=0;
    int arrp[101]={};
    int arrn[101]={};
    int arr[n];
    for(int i=0;i<n;i++)
    {   
        int temp;cin>>temp ;   
        if(temp>=0)
            arrp[temp]++;
        if(temp<0)
            arrn[-temp]++;
    }
    for(int i=1;i<101;i++)
    {
        if(arrp[i]+arrn[i]==1)
            ans++;
        else if(arrp[i]+arrn[i]>1)
            ans+=2;
    }
    if(arrp[0]>=1)
        ans++;
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
