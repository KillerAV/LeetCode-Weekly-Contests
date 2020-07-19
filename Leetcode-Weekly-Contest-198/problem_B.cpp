#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<int> func(vector<int> *arr, vector<int> &mark, string &labels, vector<int> &ans, int node=0)
{
    vector<int> count(26);
    for(int i=0;i<26;i++)
        count[i]=0;
    if(mark[node])
        return count;
    
    mark[node]=1;
    count[labels[node]-'a']++;
    for(auto it=arr[node].begin();it!=arr[node].end();it++)
    {
        vector<int> temp=func(arr,mark,labels,ans,*it);
        for(int i=0;i<26;i++)
            count[i]+=temp[i];
    }
    ans[node]=count[labels[node]-'a'];
    return count;
}
vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<int> ans(n),mark(n);
    for(int i=0;i<n;i++)
        ans[i]=mark[i]=0;
    
    vector<int> arr[n];
    for(int i=0;i<edges.size();i++)
    {
        arr[edges[i][0]].push_back(edges[i][1]);
        arr[edges[i][1]].push_back(edges[i][0]);
    }
    
    func(arr,mark,labels,ans);
    
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
    	string labels;
    	cin>>labels;

    	vector<int> ans = countSubTrees(N,edges,labels);
    	for(int i=0;i<N;i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
}
