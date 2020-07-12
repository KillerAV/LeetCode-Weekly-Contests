#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int numSub(string s) {
    ll ans=0,count=0;
    for(int i=0;i<s.size();i++)
        if(s[i]=='1')
            count++;
        else
        {
            ans+=count*(count+1)/2;
            count=0;
        }
    if(count)
        ans+=count*(count+1)/2;
    return ans%mod;
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
    	string s;
    	cin>>s;
    	cout<<numSub(s)<<endl;
    }    
}
