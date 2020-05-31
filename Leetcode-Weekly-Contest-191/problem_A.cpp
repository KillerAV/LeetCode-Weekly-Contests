#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int maxProduct(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    return (nums[nums.size()-1]-1)*(nums[nums.size()-2]-1);
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
    	vector<int> arr(N);
    	for(int i=0;i<N;i++)
    		cin>>arr[i];
    	cout<<maxProduct(arr)<<endl;
    }
}