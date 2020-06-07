#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> arr(2*n);
    for(int i=0,j=n,k=0;j<2*n;j++,i++,k+=2)
    {
        arr[k]=nums[i];
        arr[k+1]=nums[j];
    }
    return arr;
    
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
    	vector<int> arr(2*N);
    	for(int i=0;i<2*N;i++)
    		cin>>arr[i];
    	vector<int> ans=shuffle(arr,N);
    	for(int i=0;i<2*N;i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
    

}