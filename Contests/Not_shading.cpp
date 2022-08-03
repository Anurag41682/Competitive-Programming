#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
bool check(vector<vector<char>>&arr,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='B')
                return false;
        }        
    }
    return true;
}
void solve()
{
    int n,m,l,r;cin>>n>>m>>l>>r;
    vector<vector<char>>arr(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    if(check(arr,n,m))
    {
        cout<<"-1"<<endl;
    }
    else
    {
        if(arr[l-1][r-1]=='B')
            cout<<"0"<<endl;
        else 
        {
            bool f=false;
            for(int i=0;i<n;i++)
            {
                if(arr[i][r-1]=='B')
                    f=true;
            }
            for(int i=0;i<m;i++)
            {
                if(arr[l-1][i]=='B')
                    f=true;
            }
            if(f)
                cout<<"1"<<endl;
            else
                cout<<"2"<<endl;
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
