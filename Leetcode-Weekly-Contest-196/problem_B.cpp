#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int ans=0;
    for(int i=0;i<left.size();i++)
        ans=max(ans,left[i]);
    for(int i=0;i<right.size();i++)
        ans=max(ans,n-right[i]);
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
    	int n,l,r;
    	cin>>n>>l>>r;
    	vector<int> left(l),right(r);
    	for(int i=0;i<l;i++)
    		cin>>left[i];
    	for(int i=0;i<r;i++)
    		cin>>right[i];
    	cout<<getLastMoment(n,left,right)<<endl;
    }    
}
