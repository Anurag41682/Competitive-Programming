#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    if(s[0]==s[1])
    {
        string ts(2,s[0]);
        cout<<ts<<endl;
    }
    else
    {
        int i=1;
        while(s[i]<=s[i-1] && i<s.size())
        {
            // cout<<s[i]<<" "<<s[i-1]<<endl;
            i++;
        }
        int t=i;
        string temp;
        for(int i=0;i<t;i++)
        {
            temp+=s[i];
        }
        string temp2=temp;
        //cout<<temp2<<endl;
        reverse(temp2.begin(),temp2.end());
        temp+=temp2;
        cout<<temp<<endl;
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
