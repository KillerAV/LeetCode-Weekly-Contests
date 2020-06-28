#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool canArrange(vector<int>& arr, int k) {
    map<int,int> M;
    for(int i=0;i<arr.size();i++)
        M[(arr[i]%k+k)%k]++;
    
    for(auto it=M.begin();it!=M.end();it++)
    {
        int x=it->first;
        int y=(k-x)%k;
        if(M[x]!=M[y] && x!=y)
            return 0;
        if(x==y && M[x]%2!=0)
            return 0;
    }
    return 1;
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
    	cout<<canArrange(arr,K)<<endl; 	
    }
    
}
