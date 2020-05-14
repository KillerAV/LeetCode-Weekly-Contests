#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
    map<int,int> M;
    int ans=0;
    int start=-1;
    for(int i=0;i<nums.size();i++)
    {
        M[nums[i]]++;
        auto it=M.begin();
        auto jt=M.rbegin();
        while(jt->first-it->first>limit)
        {
            start++;
            M[nums[start]]--;
            if(M[nums[start]]==0)
            {
                auto it=M.find(nums[start]);
                M.erase(it);
            }
            it=M.begin();jt=M.rbegin();
        }
        ans=max(ans,i-start);
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
    	vector<int> nums(N);
    	for(int i=0;i<N;i++)
    		cin>>nums[i];
    	cout<<longestSubarray(nums,K)<<endl;
    }
}