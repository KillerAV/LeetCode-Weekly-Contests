#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int ans=0;
    for(int i=0;i<arr.size();i++)
        for(int j=i+1;j<arr.size();j++)
            for(int k=j+1;k<arr.size();k++)
                if(abs(arr[i]-arr[j])<=a && abs(arr[j]-arr[k])<=b && abs(arr[k]-arr[i])<=c)
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
    	int n,a,b,c;
    	cin>>n>>a>>b>>c;
    	vector<int> arr(n);
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	cout<<countGoodTriplets(arr,a,b,c)<<endl;
    }
}
