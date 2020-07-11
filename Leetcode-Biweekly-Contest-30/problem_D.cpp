#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool winnerSquareGame(int n) { 
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=0;
        for(int j=1;i-j*j>=0;j++)
            if(dp[i-j*j]==0)
            {
                dp[i]=true;
                break;
            }
    }
    return dp[n];
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
    	int N;
    	cin>>N;
    	cout<<winnerSquareGame(N)<<endl;
    }
}
