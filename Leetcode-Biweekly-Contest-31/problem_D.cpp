#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

pair<int,int> tree[400000];
void build(int *arr,int start,int end,int node=1)
{
    if(start>end)
    {
        tree[node]={INT_MAX,-1};
        return;
    }
    if(start==end)
    {
        tree[node]={arr[start],start};
        return;
    }
    int mid=(start+end)/2;
    build(arr,start,mid,2*node);
    build(arr,mid+1,end,2*node+1);
    if(tree[2*node].first<=tree[2*node+1].first)
        tree[node]=tree[2*node];
    else
        tree[node]=tree[2*node+1];
}
pair<int,int> query(int start,int end,int L,int R,int node=1)
{
    if(L<=start && R>=end)
        return tree[node];
    if(L>end || R<start)
        return {INT_MAX,-1};
    int mid=(start+end)/2;
    pair<int,int> ans1=query(start,mid,L,R,2*node);
    pair<int,int> ans2=query(mid+1,end,L,R,2*node+1);
    if(ans1.first<=ans2.first)
        return ans1;
    else
        return ans2;
}

int func(int *arr, int N, int s, int e, int sub=0)
{
    if(s>e)
        return 0;
    
    pair<int,int> temp=query(0,N-1,s,e);
    return func(arr,N,s,temp.second-1,temp.first)+func(arr,N,temp.second+1,e,temp.first)+temp.first-sub;
}
int minNumberOperations(vector<int>& target) {
    
    int N=target.size();
    int arr[N];
    for(int i=0;i<N;i++)
        arr[i]=target[i];
    
    build(arr,0,N-1);
    
    return func(arr,N,0,N-1);
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
    	vector<int> target(N);
    	for(int i=0;i<N;i++)
    		cin>>target[i];
    	cout<<minNumberOperations(target)<<endl;
    }
}
