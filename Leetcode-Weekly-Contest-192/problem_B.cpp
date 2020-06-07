#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<int> getStrongest(vector<int>& arr, int k) {
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int mid=arr[(n-1)/2];
    int i,j;
    vector<int> ans(k);
    for(i=0,j=n-1;k>0;k--)
    {
        if(abs(arr[i]-mid)>abs(arr[j]-mid))
        {
            ans[k-1]=arr[i];
            i++;
        }
            
        else if(abs(arr[i]-mid)<=abs(arr[j]-mid))
        {
            ans[k-1]=arr[j];
            j--;
        }
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
    	vector<int> ans=getStrongest(arr,K);
    	for(int i=0;i<K;i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
    

}