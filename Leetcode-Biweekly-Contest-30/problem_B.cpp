#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<int> sums;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=nums[j];
            sums.push_back(sum);
        }
    }
    
    sort(sums.begin(),sums.end());
    
    int ans=0;
    for(int i=left-1;i<right;i++)
        ans+=sums[i];
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
    	int left,right;
    	cin>>left>>right;
    	cout<<rangeSum(nums,N,left,right)<<endl;
    }
}
