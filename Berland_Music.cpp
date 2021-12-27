#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve()
{
    int n;cin>>n;
    vector<pair<int,int>>vec;//value position
    for(int i=1;i<=n;i++)
    {
        int temp;cin>>temp;
        vec.push_back({temp,i});
    }
    int cntliked=0;
    string s;cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
            cntliked++;
    }
    // new position liked=(n-cntliked+1)--n;
    //new postion liked =1--cntliked;
    vector<pair<int,int>>liked,disliked;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            liked.push_back(vec[i]);
        }
        else
        {
            disliked.push_back(vec[i]);
        }
    }
    sort(liked.begin(),liked.end());
    sort(disliked.begin(),disliked.end());//ok

    int to=n-cntliked;//disliked
    int from=n-cntliked+1;//liked   
    int t1=1; 
    for(auto it:disliked)
    {
        int temp=it.second;
        vec[temp-1].first=t1;
        t1++;
    }
    for(auto it:liked)
    {
        int temp=it.second;
        vec[temp-1].first=t1;
        t1++;
    }
    for(auto it:vec)
    {
        cout<<it.first<<" ";
    }cout<<endl;
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
