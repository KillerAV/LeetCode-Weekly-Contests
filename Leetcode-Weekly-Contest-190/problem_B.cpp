#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int maxVowels(string s, int k) {
    int ans=0;
    int count[26]={0};
    for(int i=0;i<k;i++)
        count[s[i]-'a']++;
    ans=max(ans,count[0]+count['e'-'a']+count['i'-'a']+count['o'-'a']+count['u'-'a']);
    for(int i=k;i<s.size();i++)
    {
        count[s[i]-'a']++;
        count[s[i-k]-'a']--;
        ans=max(ans,count[0]+count['e'-'a']+count['i'-'a']+count['o'-'a']+count['u'-'a']);
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
    	int k;
    	cin>>k;
    	cout<<maxVowels(s,k)<<endl;
    }
}