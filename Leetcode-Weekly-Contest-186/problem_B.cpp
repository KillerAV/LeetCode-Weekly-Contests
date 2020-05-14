#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int ans=0,N=cardPoints.size();
    int sum[N+1];
    for(int i=0;i<=N;i++)
        sum[i]=0;
    for(int i=1;i<=N;i++)
    {
        sum[i]=sum[i-1]+cardPoints[i-1];
    }
    for(int i=0;i<=k;i++)
    {
        ans=max(ans,sum[i]+sum[N]-sum[N-k+i]);
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
        vector<int> arr(N);
        for(int i=0;i<N;i++)
            cin>>arr[i];
        cout<<maxScore(arr,K)<<endl;

    }
}