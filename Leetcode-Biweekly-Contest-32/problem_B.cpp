#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool canConvertString(string s, string t, int k) {
    if(s.size()!=t.size())
        return false;
    int free[26];
    for(int i=0;i<26;i++)
        free[i]=i;
    for(int i=0;i<s.size();i++)
    {
        int c=(t[i]-s[i]+26)%26;
        if(c==0)
            continue;
        
        if(free[c]<=k)
        
            free[c]+=26;
        else
            return false;
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
    	string s,t;
    	int k;
    	cin>>s>>t>>k;
    	cout<<canConvertString(s,t,k)<<endl;
    }
}
