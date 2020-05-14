#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int constrainedSubsetSum(vector<int>& nums, int k) {
    int N=nums.size();
    int dp[N+1];
    dp[0]=0;
    set<pair<int,int>> S;
    S.insert({0,0});
    int ans=INT_MIN;
    for(int i=1;i<=N;i++)
    {
        auto it=S.rbegin();
        dp[i]=max(nums[i-1],it->first+nums[i-1]);
        S.insert({dp[i],i});
        int x=S.size();
        if(x>k)
        {
            auto it=S.find({dp[i-k],i-k});
            S.erase(it);
        }
        ans=max(ans,dp[i]);
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
        vector<int> arr(N);
        for(int i=0;i<N;i++)
            cin>>arr[i];
        cout<<constrainedSubsetSum(arr,K)<<endl;

    }
}