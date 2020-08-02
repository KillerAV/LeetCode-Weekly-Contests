#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int minSwaps(vector<vector<int>>& grid) {
    int n=grid.size();
    int pos[n];
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=n-1;j>=0 && grid[i][j]==0;j--,count++);
        pos[i]=count;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int index=-1;
        for(int j=i;j<n;j++)
            if(pos[j]>=n-i-1)
            {
                index=j;
                break;
            }
        if(index==-1)
            return -1;
        
        ans+=index-i;
        int temp=pos[index];
        for(int j=index;j>i;j--)
            pos[j]=pos[j-1];
        pos[i]=temp;
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
    	int n,m;
    	cin>>n>>m;
    	vector<vector<int>> grid(n);
    	for(int i=0;i<n;i++)
    	{
    		vector<int> temp(m);
    		for(int j=0;j<m;j++)
    			cin>>temp[j];
    		grid[i]=temp;
    	}
    	cout<<minSwaps(grid)<<endl;
    }
}
