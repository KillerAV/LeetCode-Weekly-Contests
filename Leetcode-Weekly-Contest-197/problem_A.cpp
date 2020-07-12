#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int,int> M;
    for(int i=0;i<nums.size();i++)
        M[nums[i]]++;
    
    int ans=0;
    for(auto it:M)
        ans+=it.second*(it.second-1)/2;
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
    	cout<<numIdenticalPairs(nums)<<endl;
    }    
}
