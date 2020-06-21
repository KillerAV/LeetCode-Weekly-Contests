#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool check(vector<int> *arr, int n)
{
    bool mark[n];
    for(int i=0;i<n;i++)
        mark[i]=0;
    mark[0]=1;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty())
    {
        int temp=Q.front();
        Q.pop();
        for(auto it=arr[temp].begin();it!=arr[temp].end();it++)
            if(!mark[*it])
            {
                mark[*it]=1;
                Q.push(*it);
            }
    }
    for(int i=0;i<n;i++)
        if(!mark[i])
            return false;
    return true;
}
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    vector<pair<int,pair<int,int>>> arr[n];
    vector<int> weight[1001];
    for(int i=0;i<edges.size();i++)
    {
        arr[edges[i][0]].push_back({edges[i][1],{edges[i][2],i}});
        arr[edges[i][1]].push_back({edges[i][0],{edges[i][2],i}}); 
        weight[edges[i][2]].push_back(i);
    }
    vector<pair<int,pair<int,int>>> MST;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> Q;
    Q.push({0,{0,-1}});
    bool mark[n];
    for(int i=0;i<n;i++)
        mark[i]=0;
    while(!Q.empty())
    {
        pair<int,pair<int,int>> temp=Q.top();
        Q.pop();
        int node=temp.second.first,par=temp.second.second;
        if(mark[node])
            continue;
        mark[node]=1;
        MST.push_back(temp);
        for(auto it=arr[node].begin();it!=arr[node].end();it++)
            if(!mark[it->first])
                Q.push({it->second.first,{it->first,node}});
    }
    set<int> critical,pseudo;
    for(int j=0;j<MST.size();j++)
    {
        int w=MST[j].first;
        vector<int> options;
        vector<int> temp[n];
        for(int i=0;i<MST.size();i++)   
        {
            if(MST[i].second.second==-1 || i==j)
                continue;
            temp[MST[i].second.second].push_back(MST[i].second.first);
            temp[MST[i].second.first].push_back(MST[i].second.second);
        }
        for(int i=0;i<weight[w].size();i++)
        {
            int index=weight[w][i];
            int u=edges[index][0],v=edges[index][1],w=edges[index][2];
            temp[u].push_back(v);
            temp[v].push_back(u);
            if(check(temp,n))
                options.push_back(index);
            temp[u].pop_back();
            temp[v].pop_back();   
        }
        if(options.size()==1)
            critical.insert(options[0]);
        else
            for(auto it=options.begin();it!=options.end();it++)
                pseudo.insert(*it);
    }
    vector<int> a,b;
    for(auto it:critical)
        a.push_back(it);
    for(auto it:pseudo)
        b.push_back(it);
    vector<vector<int>> ans;
    ans.push_back(a);
    ans.push_back(b);
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
    		vector<int> temp(3);
    		cin>>temp[0]>>temp[1]>>temp[2];
    		edges[i]=temp;
    	}
    	vector<vector<int>> ans=findCriticalAndPseudoCriticalEdges(N,edges);
    	for(int i=0;i<ans[0].size();i++)
    		cout<<ans[0][i]<<" ";
    	cout<<endl;
    	for(int i=0;i<ans[1].size();i++)
    		cout<<ans[1][i]<<" ";
    	cout<<endl;
    }
    
}
