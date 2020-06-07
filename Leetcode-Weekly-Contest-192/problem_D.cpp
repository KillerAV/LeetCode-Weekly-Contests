#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int dp[20][100][101];
int func(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target, int prev=0, int i=0)
{
    if(target<0)
        return 100000000;
    if(i==m)
        if(target==0)
            return 0;
        else
            return 100000000;
   
    if(dp[prev][i][target]==-1)
    {
        int ans;
        if(houses[i]!=0)
        {
            int diff=0;
            if(prev+1!=houses[i])
                diff++;
            ans=func(houses,cost,m,n,target-diff,houses[i]-1,i+1);
        }
        else
        {
            ans=100000000;
            for(int j=0;j<n;j++)
            {
                int diff=0;
                if(prev!=j)
                    diff++;
                ans=min(ans,func(houses,cost,m,n,target-diff,j,i+1)+cost[i][j]);
            }
        }
        dp[prev][i][target]=ans;
    }
    return dp[prev][i][target];
}
int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<=m;k++)
                dp[i][j][k]=-1;
    int ans=func(houses,cost,m,n,target);
    if(ans>=100000000)
        return -1;
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
    	int N,M;
    	cin>>N>>M;
    	vector<int> houses(M);
    	vector<vector<int>> cost(M);
    	for(int i=0;i<M;i++)
    	{
    		vector<int> temp(N);
    		for(int j=0;j<N;j++)
    			cin>>temp[j];
    		cost[i]=temp;
    	}

    	int target;
    	cin>>target;
    	cout<<minCost(houses,cost,M,N,target)<<endl;
    }
}