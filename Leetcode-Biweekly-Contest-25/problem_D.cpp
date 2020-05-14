#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int dp[1024][41];
int func(vector<int> *arr, int N, int num=0, int i=0)
{
    if(i==41)
    {
        for(int i=0;i<N;i++)
        {
            if(num%2==0)
                return 0;
            num/=2;
        }
        return 1;
    }
    
    if(dp[num][i]==-1)
    {
        ll ans=func(arr,num,i+1);
        for(int j=0;j<arr[i].size();j++)
        {
            int x=arr[i][j];
            if((num&(1ll<<x))==0)
                ans=(ans+func(arr,N,(num|(1ll<<x)),i+1))%mod;
        }
        dp[num][i]=ans;
    }
    return dp[num][i];
}
int numberWays(vector<vector<int>>& hats) {
    for(int i=0;i<1024;i++)
    	for(int j=0;j<41;j++)
    		dp[i][j]=-1;
    vector<int> arr[41];
    int N=hats.size();
    for(int i=0;i<hats.size();i++)
        for(int j=0;j<hats[i].size();j++)
            arr[hats[i][j]].push_back(i);
    return func(arr,N);
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
    	vector<vector<int>> arr(N);
    	for(int i=0;i<N;i++)
    	{
    		int s;
    		cin>>s;
    		for(int j=0;j<s;j++)
    		{
    			int temp;
    			cin>>temp;
    			arr[i].push_back(temp);
    		}
    	}
    	cout<<numberWays(arr)<<endl;
    }
}