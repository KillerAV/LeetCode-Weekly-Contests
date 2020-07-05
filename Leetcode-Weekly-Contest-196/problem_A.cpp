#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    set<int> S;
    for(int i=1;i<arr.size();i++)
        S.insert(arr[i]-arr[i-1]);
    return S.size()==1;
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
    	cout<<canMakeArithmeticProgression(arr)<<endl;
    }    
}
