#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int minInsertions(string s) { 
    int ans=0;
    int count=0;
    for(int i=0;i<s.size();i++)
        if(s[i]=='(')
            count++;
        else if(s[i]==')')
        {
            if(count==0)
            {
                ans++;
                count++;
            }
            if(i+1<s.size() && s[i+1]==')')
            {
                count--;
                i++;
            }
            else
            {
                ans++;
                count--;
            }
        }
    while(count--)
        ans+=2;
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
    	cout<<minInsertions(s)<<endl;
    }
}
