#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int minSumOfLengths(vector<int>& arr, int target) {
    int N=arr.size();
    int dp1[N],dp2[N];
    for(int i=0;i<N;i++)
        dp1[i]=dp2[i]=0;
    map<int,int> M;
    int sum=0;
    M[sum]=-1;
    for(int i=0;i<N;i++)
    {
        sum+=arr[i];
        int length=1000000;
        if(M.count(sum-target))
            length=i-M[sum-target];
        M[sum]=i;
        if(i==0)
            dp1[i]=length;
        else
            dp1[i]=min(dp1[i-1],length);
    }
    M.clear();
    sum=0;
    M[sum]=N;
    for(int i=N-1;i>=0;i--)
    {
        sum+=arr[i];
        int length=1000000;
        if(M.count(sum-target))
            length=M[sum-target]-i;
        M[sum]=i;
        if(i==N-1)
            dp2[i]=length;
        else
            dp2[i]=min(dp2[i+1],length);
    }
    int ans=INT_MAX;
    for(int i=0;i<N-1;i++)
    {
        ans=min(ans,dp1[i]+dp2[i+1]);
        
    }
    if(ans>=1000000)
        return -1;
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
    	int N,target;
    	cin>>N>>target;
    	vector<int> arr(N);
    	for(int i=0;i<N;i++)
    		cin>>arr[i];
    	cout<<minSumOfLengths(arr,target)<<endl;
    }
    
}
