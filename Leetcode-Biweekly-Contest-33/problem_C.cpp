#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

pair<int,int> func(int X)
{
    if(X==0)
        return {0,0};
    if(X%2==0)
    {
        pair<int,int> x=func(X/2);
        return {x.first,x.second+1};
    }
    else
    {
        pair<int,int> x=func(X-1);
        return {x.first+1,x.second};   
    }
}
int minOperations(vector<int>& nums) {
    
    int ans=0,times=0;
    for(int i=0;i<nums.size();i++)
    {
        pair<int,int> op=func(nums[i]);
        ans+=op.first;
        times=max(times,op.second);
    }
    return ans+times;
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
    	vector<int> nums(N);
    	for(int i=0;i<N;i++)
    		cin>>nums[i];
    	cout<<minOperations(nums)<<endl;
    }
}
