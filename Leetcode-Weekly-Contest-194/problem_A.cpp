#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int xorOperation(int n, int start) {
    vector<int> nums(n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        nums[i]=start+2*i;
        ans=(ans^nums[i]);
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
    	int N,start;
    	cin>>N>>start;
    	cout<<xorOperation(N,start)<<endl;
    }
}
