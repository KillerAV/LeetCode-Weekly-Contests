#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int numOfSubarrays(vector<int>& arr) { 
    int even=0,odd=0,sum=0;
    ll ans=0;
    even=1;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        if(sum%2==0)
        {
            ans+=odd;
            even++;
        }
        else
        {
            ans+=even;
            odd++;
        }
        ans%=mod;
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
    	vector<int> arr(N);
    	for(int i=0;i<N;i++)
    		cin>>arr[i];
    	cout<<numOfSubarrays(arr)<<endl;
    }
}
