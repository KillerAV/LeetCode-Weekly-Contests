#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int maxPower(string s) {
    int ans=1;
    for(int i=0;i<s.size();)
    {
        int j=i;
        int size=0;
        for(;j<s.size() && s[i]==s[j];j++,size++);
        ans=max(ans,size);
        i=j;
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
    	cout<<maxPower(s)<<endl;
    }

}