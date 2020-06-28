#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

ll expo(ll X, ll N)
{
    if(N<0)
        return 0;
    if(N==0)
        return 1;
    if(N%2==0)
        return expo((X*X)%mod,N/2);
    return (X*expo(X,N-1))%mod;
}
int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
        int index=upper_bound(nums.begin(),nums.end(),target-nums[i])-nums.begin();
        index--;
        
        ans=(ans+expo(2,index-i))%mod;
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
    	int N,target;
    	cin>>N>>target;
    	vector<int> arr(N);
    	for(int i=0;i<N;i++)
    		cin>>arr[i];
    	cout<<numSubseq(arr,target)<<endl; 	
    }
    
}
