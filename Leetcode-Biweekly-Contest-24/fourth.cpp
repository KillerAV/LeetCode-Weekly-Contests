#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int numberOfArrays(string s, int k) {
    int N=s.size();
    long long dp[N+1];
    dp[0]=1;
    long long M=1000000007;
    for(int i=1;i<=N;i++)
    {
        long long num=0,mult=1;
        dp[i]=0;
        for(int j=i;j>0;j--,mult*=10)
        {
            num=num+mult*(s[j-1]-'0');
            if(num>k || mult>k)
                break;
            if(s[j-1]!='0')
                dp[i]=(dp[i]+dp[j-1])%M;
        }
    }
    return dp[N];
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
        string s;
        int k;
        cin>>s>>k;
        cout<<numberOfArrays(s,k)<<endl;
    }
    
}