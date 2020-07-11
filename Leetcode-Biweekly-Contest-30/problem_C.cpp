#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int minDifference(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int size=nums.size();
    if(size<=3)
        return 0;
    int left=size-3;
    left--;
    int ans=INT_MAX;
    for(int i=0;i+left<size;i++)
            ans=min(ans,nums[i+left]-nums[i]);
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
    	cout<<minDifference(nums)<<endl;
    }
}
