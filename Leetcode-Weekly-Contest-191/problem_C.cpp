#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int minReorder(int n, vector<vector<int>>& connections) {
    vector<int> arr[n],other[n];
    for(int i=0;i<n-1;i++)
    {
        arr[connections[i][0]].push_back(connections[i][1]);
        other[connections[i][1]].push_back(connections[i][0]);
    }
    queue<int> Q;
    Q.push(0);
    int ans=0;
    bool mark[n];
    for(int i=0;i<n;i++)
        mark[i]=0;
    mark[0]=1;
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
        for(auto it=other[temp].begin();it!=other[temp].end();it++)
            if(!mark[*it])
            {
                mark[*it]=1;
                ans++;
                Q.push(*it);
            }
            
    }
    return (n-1)-ans;
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
    	cout<<minReorder(N,edges)<<endl;
    }
}