#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int minStartValue(vector<int>& nums) {
    int sum=0,ans=0;
    for(int i=0;i<nums.size();i++)
    {
        sum=sum+nums[i];
        ans=min(ans,sum);
    }
    ans=abs(ans);
    ans++;
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
        vector<int> arr(N);
        for(int i=0;i<N;i++)
            cin>>arr[i];
        cout<<minStartValue(arr)<<endl;
    }
    
}