#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int N,M,dp[70][70][70];
int func(vector<vector<int>> &grid, int x1, int y1, int y2)
{
    if(y1<0 || y2<0 || y1==M ||  y2==M)
        return -1000000;
    if(x1==N)
        return 0;
    

    if(dp[x1][y1][y2]==-1)
    {
        int ans;
        int opt1=func(grid,x1+1,y1,y2);
        int opt2=func(grid,x1+1,y1+1,y2);
        int opt3=func(grid,x1+1,y1-1,y2);
        int opt4=func(grid,x1+1,y1,y2-1);
        int opt5=func(grid,x1+1,y1+1,y2-1);
        int opt6=func(grid,x1+1,y1-1,y2-1);
        int opt7=func(grid,x1+1,y1,y2+1);
        int opt8=func(grid,x1+1,y1+1,y2+1);
        int opt9=func(grid,x1+1,y1-1,y2+1);
        if(y1==y2)
            ans=grid[x1][y1];
        else
            ans=grid[x1][y1]+grid[x1][y2];
        
        dp[x1][y1][y2]=ans+max(opt1,max(opt2,max(opt3,max(opt4,max(opt5,max(opt6,max(opt7,max(opt8,opt9))))))));
    
    }
    return dp[x1][y1][y2];
}
int cherryPickup(vector<vector<int>>& grid) {
    N=grid.size();
    M=grid[0].size();
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            for(int l=0;l<M;l++)
                dp[i][j][l]=-1;
    
    return func(grid,0,0,M-1);
    
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
    	vector<vector<int>> arr(N);
    	for(int i=0;i<N;i++)
    	{
    		vector<int> temp(M);
    		for(int j=0;j<M;j++)
    			cin>>temp[j];
    		arr[i]=temp;
    	}
    	cout<<cherryPickup(arr)<<endl;
    }
}