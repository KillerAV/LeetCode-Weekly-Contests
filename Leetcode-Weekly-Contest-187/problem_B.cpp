#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool kLengthApart(vector<int>& nums, int k) {
    int last=-k-1;
    for(int i=0;i<nums.size();i++)
        if(nums[i]==1)
        {
            if(i-last<=k)
                return 0;
            last=i;
        }
    return 1;
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
    	cout<<kLengthApart(nums,K)<<endl;
    }
}