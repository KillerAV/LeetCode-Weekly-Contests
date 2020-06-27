#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int longestSubarray(vector<int>& nums) {
    int count=0;
    int N=nums.size();
    int left[N],right[N],ans=0;
    for(int i=0;i<N;i++)
    {
        if(nums[i]==1)
            count++;
        else
            count=0;
        left[i]=count;
        
    }
    count=0;
    for(int i=N-1;i>=0;i--)
    {
        if(nums[i]==1)
            count++;
        else
            count=0;
        right[i]=count;
       
    }
    
    for(int i=0;i<N;i++)
    {
        int x=0;
        if(i!=0)
            x+=left[i-1];
        if(i!=N-1)
            x+=right[i+1];
        ans=max(ans,x);
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
    	int N;
    	cin>>N;
    	vector<int> nums(N);
    	for(int i=0;i<N;i++)
    		cin>>nums[i];
    	cout<<longestSubarray(nums)<<endl;
    }
    
}
