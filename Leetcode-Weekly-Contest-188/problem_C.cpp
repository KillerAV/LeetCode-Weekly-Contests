#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

pair<int,bool> func(vector<int> *arr,bool *mark,vector<bool> &hasApple, int node=0)
{
    if(mark[node])
        return {0,false};
    int time=0;
    bool below=0;
    if(hasApple[node])
        below=1;
    mark[node]=1;
    //cout<<node<<" "<<below<<endl;;
    for(int i=0;i<arr[node].size();i++)
    {
        if(mark[arr[node][i]])
            continue;
        pair<int,bool> temp=func(arr,mark,hasApple,arr[node][i]);
        cout<<node<<" "<<arr[node][i]<<" "<<temp.first<<endl;
        int x=temp.first;
        below=(below||temp.second);
        if(temp.second)
            time=time+x+2;
    }
    cout<<node<<" "<<time<<endl;
    if(below)
        return {time,below};
    else
        return {0,below};
}
int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<int> arr[n];
    for(int i=0;i<edges.size();i++)
    {
        arr[edges[i][0]].push_back(edges[i][1]);
        arr[edges[i][1]].push_back(edges[i][0]);
    }
    
    bool mark[n];
    for(int i=0;i<n;i++)
        mark[i]=0;
    return func(arr,mark,hasApple).first;
    
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
    	vector<vector<int>> edges(N-1);
    	for(int i=0;i<N-1;i++)
    	{
    		int x,y;
    		cin>>x>>y;
    		edges[i].push_back(x);
    		edges[i].push_back(y);
    	}
    	vector<bool> hasApple(N);
    	for(int i=0;i<N;i++)
    	{
    		int temp;
    		cin>>temp;
    		hasApple[i]=temp;
    	}
    	cout<<minTime(N,edges,hasApple)<<endl;
    }
}