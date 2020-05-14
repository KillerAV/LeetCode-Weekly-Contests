#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int maxScore(string s) {
    int s1=0,s2=0;
    for(int i=0;i<s.size();i++)
        if(s[i]=='0')
            s1++;
        else
            s2++;
    int zero=0,one=0;
    int ans=0;
    int N=s.size();
    for(int i=0;i<N-1;i++)
    {
        if(s[i]=='0')
            zero++;
        else
            one++;
        ans=max(ans,zero+s2-one);
    }
    return ans;
    
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        cin>>str;
        cout<<maxScore(str)<<endl;

    }
}