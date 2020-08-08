#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int i=1,j=0;
    while(k--)
    {
        while(j<arr.size() && arr[j]==i)
        {
            j++;
            i++;
        }
        if(k!=0)
        	i++;
    }
    return i;
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
    	cout<<findKthPositive(arr,k)<<endl;
    }
}
