#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int numSplits(string s) {
    int N=s.size();
    int distinct[N];
    set<char> S;
    for(int i=N-1;i>=0;i--)
    {
        S.insert(s[i]);
        distinct[i]=S.size();
    }
    
    S.clear();
    int ans=0;
    for(int i=0;i<N-1;i++)
    {
        S.insert(s[i]);
        if(S.size()==distinct[i+1])
            ans++;
        
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
    	string s;
    	cin>>s;
    	cout<<numSplits(s)<<endl;
    }
}
