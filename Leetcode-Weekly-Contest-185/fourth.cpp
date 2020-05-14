#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

ll dp[51][101][51];
ll func(int N, int M, int K, int prevMax)
{
    if(K<0)
        return 0;
    if(N==0)
        if(K==0)
            return 1;
        else
            return 0;
    
    if(dp[N][prevMax][K]!=-1)
        return dp[N][prevMax][K];
    ll ans=0;
    
    for(int i=1;i<=prevMax;i++)
        ans=(ans+func(N-1,M,K,prevMax))%mod;  
    for(int i=prevMax+1;i<=M;i++)
        ans=(ans+func(N-1,M,K-1,i))%mod;
    dp[N][prevMax][K]=ans;
    return ans;
}
int numOfArrays(int n, int m, int k) {
    ll ans=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=n;k++)
                dp[i][j][k]=-1;
    for(int i=1;i<=m;i++)
        ans=(ans+func(n-1,m,k-1,i))%mod;
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
    	int n,m,k;
    	cin>>n>>m>>k;
    	cout<<numOfArrays(n,m,k)<<endl;
    }
}