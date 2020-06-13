#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int dp[100][101][101];
int func(vector<int> &houses, int k, int i=0, int prev=-1)
{
    if(k<0)
        return 100000000;
    
    if(i==houses.size())
    {
        int sum=0;
        if(k!=0)
            return 100000000;
        else
            for(int j=prev+1;j<i;j++)
                sum+=houses[j]-houses[prev];
        return sum;
    }
    if(dp[i][prev+1][k]==-1)
    {
        int sum=0;
        if(prev==-1)
            for(int j=0;j<i;j++)
                sum+=houses[i]-houses[j];
        else 
            for(int j=prev+1;j<i;j++)
                sum+=min(houses[i]-houses[j],houses[j]-houses[prev]);
    
        int opt1=func(houses,k-1,i+1,i)+sum;
        int opt2=func(houses,k,i+1,prev);
        dp[i][prev+1][k]=min(opt1,opt2);
    }
    return dp[i][prev+1][k];
}
int minDistance(vector<int>& houses, int k) {
    sort(houses.begin(),houses.end());
    int n=houses.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                dp[i][j][k]=-1;
    return func(houses,k);
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
    	int N,K;
    	cin>>N>>K;
    	vector<int> houses(N);
    	for(int i=0;i<N;i++)
    		cin>>houses[i];
    	cout<<minDistance(houses,K)<<endl;
    }
    
}
