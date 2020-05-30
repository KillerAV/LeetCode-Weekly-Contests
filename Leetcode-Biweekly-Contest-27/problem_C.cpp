#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

void dfs(vector<int> *arr, bool *mark, bool ans[101][101], int node,int src)
{
    if(mark[node])
        return;
    mark[node]=1;
    ans[src][node]=1;
    for(auto it=arr[node].begin();it!=arr[node].end();it++)
        dfs(arr,mark,ans,*it,src);
}
vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    
    vector<bool> fans;
    vector<int> arr[n];
    for(int i=0;i< prerequisites.size();i++)
    {
        arr[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    bool ans[101][101];
    for(int i=0;i<n;i++)
    {
        bool mark[n];
        for(int j=0;j<n;j++)
            mark[j]=ans[i][j]=0;
        dfs(arr,mark,ans,i,i);
    }
    
    for(int i=0;i<queries.size();i++)
    {
        int x=queries[i][0],y=queries[i][1];
        fans.push_back(ans[x][y]);
    }
    return fans;
    
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
    	int N,M,Q;
    	cin>>N>>M>>Q;
    	vector<vector<int>> prerequisites(M),queries(Q);
    	for(int i=0;i<M;i++)
    	{
    		int x,y;
    		cin>>x>>y;
    		prerequisites[i].push_back(x);
    		prerequisites[i].push_back(y);
    	}

    	for(int i=0;i<Q;i++)
    	{
    		int x,y;
    		cin>>x>>y;
    		queries[i].push_back(x);
    		queries[i].push_back(y);
    	}

    	vector<bool> ans=checkIfPrerequisite(N,prerequisites,queries);
    	for(int i=0;i<Q;i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
}