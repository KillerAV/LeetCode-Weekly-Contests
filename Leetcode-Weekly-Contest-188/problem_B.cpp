#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int countTriplets(vector<int>& arr) {
    int ans=0;
    int N=arr.size();
    for(int i=0;i<N;i++)
    {
        int a=arr[i];
        for(int j=i+1;j<N;j++)
        {
            
            int b=0;
            for(int k=j;k<N;k++)
            {
                b=(b^arr[k]);
                if(a==b)
                    ans++;
            }
            a=(a^arr[j]);
                
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
    	int N;
    	cin>>N;
    	vector<int> arr(N);
    	for(int i=0;i<N;i++)
    		cin>>arr[i];
    	cout<<countTriplets(arr)<<endl;
    }
}