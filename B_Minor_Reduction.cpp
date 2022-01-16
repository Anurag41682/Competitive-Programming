#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
bool check(string &s,int i,int j)
{
    char a,b;
    a=s[i];b=s[j];
    int aa,bb;
    aa=a-'0';
    bb=b-'0';
    if(aa+bb>9)
    {
        string start=s.substr(0,j);
        string end="";
        if(i<s.size()-1)
        {
            end=s.substr(i+1,(s.size()-1-i));
        }
        string temp=to_string(aa+bb);
        start+=temp;
        start+=end;
        s=start;
        return true;
    }
    return false;
}
void solve()
{
    bool flag=false;
    string s;cin>>s;
    for(int i=s.size()-1;i>0;i--)
    {
        if(check(s,i,i-1))
        {
            flag=true;break;
        }
    }
    if(flag)
        cout<<s<<endl;
    else
    {
        int aa=s[0]-'0';
        int bb=s[1]-'0';
        string temp=to_string(aa+bb);
        string end=s.substr(2,s.size()-2);
        temp+=end;
        cout<<temp<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        solve();//g7ZXt9
    }
}