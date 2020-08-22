#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool mark[500][500], rev[500][500];
bool dfs(vector<vector<char>>& grid, int i, int j, int parx=-1, int pary=-1)
{
    if(rev[i][j])  
        return 1;
    if(mark[i][j])
        return 0;
    
    mark[i][j]=1;
    rev[i][j]=1;
    if(i+1<grid.size() && grid[i][j]==grid[i+1][j] && (i+1!=parx || j!=pary) && dfs(grid,i+1,j,i,j))
        return 1;
    if(i-1>=0 && grid[i][j]==grid[i-1][j] && (i-1!=parx || j!=pary) && dfs(grid,i-1,j,i,j))
        return 1;
    if(j+1<grid[i].size() && grid[i][j]==grid[i][j+1] && (i!=parx || j+1!=pary) && dfs(grid,i,j+1,i,j))
        return 1;
    if(j-1>=0 && grid[i][j]==grid[i][j-1] && (i!=parx || j-1!=pary) && dfs(grid,i,j-1,i,j))
        return 1;
    rev[i][j]=0;
    
    return 0;
}
bool containsCycle(vector<vector<char>>& grid) {
    
    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[i].size();j++)
            mark[i][j]=rev[i][j]=0;
    
    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[i].size();j++)
            if(!mark[i][j] && dfs(grid,i,j))
                return 1;
    return 0;        
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
    	int n,m;
    	cin>>n>>m;
    	vector<vector<char>> grid(n);
    	for(int i=0;i<n;i++)
    	{
    		vector<char> arr(m);
    		for(int i=0;i<m;i++)
    			cin>>arr[i];
    		grid[i]=arr;
    	}
    	cout<<containsCycle(grid)<<endl;
    }
}
