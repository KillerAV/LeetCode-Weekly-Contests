#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int kthFactor(int n, int k) {
    vector<int> arr;
    for(int i=1;i*i<=n;i++)
        if(n%i==0)
        {
            arr.push_back(i);
            if(n/i!=i)
                arr.push_back(n/i);
        }
    sort(arr.begin(),arr.end());
    if(k>arr.size())
        return -1;
    return arr[k-1];
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
   
    	cout<<kthFactor(N,K)<<endl;	
    }
    
}
