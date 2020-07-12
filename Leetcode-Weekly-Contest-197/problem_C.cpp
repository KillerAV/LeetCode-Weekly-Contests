#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<pair<int,double>> arr[n];
    for(int i=0;i<edges.size();i++)
    {
        arr[edges[i][0]].push_back({edges[i][1],succProb[i]});
        arr[edges[i][1]].push_back({edges[i][0],succProb[i]});
    }
    
    set<pair<int,double>> S;
    S.insert({0,start});
    double dist[n];
    for(int i=0;i<n;i++)
        dist[i]=0;
    dist[start]=1;
    while(!S.empty())
    {
        auto it=S.begin();
        int node=it->second;
        
        for(auto it=arr[node].begin();it!=arr[node].end();it++)
            if(dist[it->first]<dist[node]*it->second)
            {
                auto jt=S.find({dist[it->first],it->first});
                if(jt!=S.end())
                    S.erase(jt);
                dist[it->first]=dist[node]*it->second;
                S.insert({dist[it->first],it->first});
            }
        S.erase(it);
    }
    return dist[end];
}
int main() 
{
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
    	vector<double> succProb(M);
    	for(int i=0;i<M;i++)
    		cin>>succProb[i];
    	int start,end;
    	cin>>start>>end;
    	printf("%0.5lf\n", maxProbability(N,edges,succProb,start,end));
    }    
}
