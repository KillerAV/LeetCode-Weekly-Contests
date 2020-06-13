#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    for(int i=0;i<prices.size();i++)
    {
        int diff=0;
        for(int j=i+1;j<prices.size();j++)
            if(prices[j]<=prices[i])
            {
                diff=prices[j];
                break;
            }
        prices[i]-=diff;
    }
    return prices;
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
    	vector<int> ans=finalPrices(arr);
    	for(int i=0;i<ans.size();i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
}
