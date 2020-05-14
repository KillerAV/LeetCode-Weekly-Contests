#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int N=candies.size();
    vector<bool> ans(N);
    int maxElement=0;
    for(int i=0;i<N;i++)
        maxElement=max(maxElement,candies[i]);
    for(int i=0;i<N;i++)
        if(candies[i]+extraCandies>=maxElement)
            ans[i]=1;
        else
            ans[i]=0;
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
    	vector<int> candies(N);
    	for(int i=0;i<N;i++)
    		cin>>candies[i];
    	vector<bool> ans=kidsWithCandies(candies,K);
    	for(int i=0;i<N;i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
}