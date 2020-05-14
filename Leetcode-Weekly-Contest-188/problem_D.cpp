#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool check(vector<string> &arr, int si, int sj, int ei, int ej)
{
    for(int i=si;i<=ei;i++)
        for(int j=sj;j<=ej;j++)
            if(arr[i][j]=='A')
                return 1;
    return 0;
}
map<pair<pair<int,int>,pair<int,int>>,int> dp[10];
ll func(vector<string> &arr, int k, int si, int sj, int ei, int ej)
{
    if(k==0)
        return 1;
    
    auto it=dp[k].find({{si,sj},{ei,ej}});
    
    if(it!=dp[k].end())
        return it->second;
    ll ans=0;
    for(int i=si+1;i<=ei;i++)
        if(check(arr,si,sj,i-1,ej) && check(arr,i,sj,ei,ej))
            ans=(ans+func(arr,k-1,i,sj,ei,ej))%mod;
    
    for(int i=sj+1;i<=ej;i++)
        if(check(arr,si,sj,ei,i-1) && check(arr,si,i,ei,ej))
            ans=(ans+func(arr,k-1,si,i,ei,ej))%mod;
    dp[k][{{si,sj},{ei,ej}}]=ans;
    return ans;
    
    
}
int ways(vector<string>& pizza, int k) {
    
    int N=pizza.size();
    int M=pizza[0].size();
    
    return func(pizza,k-1,0,0,N-1,M-1);
    
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
    	int N,M;
    	cin>>N>>M;
    	vector<string> pizza(N);
    	for(int i=0;i<N;i++)
    		cin>>pizza[i];
    	int K;
    	cin>>K;
    	cout<<ways(pizza,K)<<endl;
    }
}