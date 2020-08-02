#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int getWinner(vector<int>& arr, int k) {
    int n=arr.size();
    for(int i=0;i<n;)
    {
        int j=i,count=0;
        for(j=i+1;j<n && arr[i]>arr[j];j++,count++);
        
        if((count>=k-1 && i!=0) || (count>=k && i==0) || j==n)
            return arr[i];
        i=j;
    }
    return -1;
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
    	int n,k;
    	cin>>n>>k;
    	vector<int> arr(n);
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	cout<<getWinner(arr,k)<<endl;
    }
}
