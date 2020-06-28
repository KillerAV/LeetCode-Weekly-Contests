#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int tree[400001];
void build_max(int *arr,int start,int end,int node=1)
{
    if(start>end)
    {
        tree[node]=INT_MIN;
        return;
    }
    if(start==end)
    {
        tree[node]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    build_max(arr,start,mid,2*node);
    build_max(arr,mid+1,end,2*node+1);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}

int query_max(int start,int end,int L,int R,int node=1)
{
    if(L<=start && R>=end)
        return tree[node];
    
    if(L>end || R<start)
        return INT_MIN;
    
    int mid=(start+end)/2;
    int ans1=query_max(start,mid,L,R,2*node);
    int ans2=query_max(mid+1,end,L,R,2*node+1);
    return max(ans1,ans2);
}

int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int N=points.size();
    int arr[N];
    vector<int> temp;
    for(int i=0;i<N;i++)
    {
        arr[i]=points[i][0]+points[i][1];
        temp.push_back(points[i][0]);
    }
    
    build_max(arr,0,N-1);
    int ans=INT_MIN;
    for(int i=0;i<N;i++)
    {
        int index=upper_bound(temp.begin(),temp.end(),k+temp[i])-temp.begin();
        index--;
        if(index>i)
            ans=max(ans,points[i][1]-points[i][0]+query_max(0,N-1,i+1,index));
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
    	int N,K;
    	cin>>N>>K;
    	vector<vector<int>> points(N);
    	for(int i=0;i<N;i++)
    	{
    		vector<int> temp(2);
    		cin>>temp[0]>>temp[1];
    		points[i]=temp;
    	}
    	cout<<findMaxValueOfEquation(points,K)<<endl;    	
    }
    
}
