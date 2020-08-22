#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

void dfs(vector<int> *arr, bool *mark, int node) {
    if(mark[node])
        return;
    mark[node]=1;
    for(auto i:arr[node])
        dfs(arr,mark,i);

}
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> ans;
    vector<int> arr[n];
    for(int i=0;i<edges.size();i++)
        arr[edges[i][0]].push_back(edges[i][1]);
    bool mark[n];
    pair<int,int> indegree[n];
    for(int i=0;i<n;i++)
    {
        indegree[i].first=0;
        mark[i]=0;
        indegree[i].second=i;
    }
    for(int i=0;i<n;i++)
        for(auto j:arr[i])
            indegree[j].first++;
    sort(indegree, indegree+n);
    for(int i=0;i<n;i++)
    {
        if(!mark[indegree[i].second])
        {
            ans.push_back(indegree[i].second);
            dfs(arr,mark,indegree[i].second);
        }
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
    	int N,M;
    	cin>>N>>M;
    	vector<vector<int>> edges(M);
    	for(int i=0;i<M;i++)
    	{
    		vector<int> temp(2);
    		cin>>temp[0]>>temp[1];
    		edges[i]=temp;
    	}

    	vector<int> ans=findSmallestSetOfVertices(N,edges);
    	for(int i=0;i<ans.size();i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
}
