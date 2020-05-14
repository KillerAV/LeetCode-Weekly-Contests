#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int minNumberOfFrogs(string croakOfFrogs) {
    map<char,int> M;
    int N=croakOfFrogs.size();
    string str=croakOfFrogs;
    for(int i=0;i<N;i++)
    {
        M[str[i]]++;
        if(str[i]!='c' && str[i]!='r' && str[i]!='o' && str[i]!='a' && str[i]!='k')
            return -1;
        if(M['k']>M['a'] || M['a']>M['o'] || M['o']>M['r'] || M['r']>M['c'])
            return -1;
        
    }
    int count=M['c'];
    for(auto it=M.begin();it!=M.end();it++)
        if(it->second!=count)
            return -1;
    
    
    int ans=0;
    int CCount=0;
    for(int i=0;i<N;i++)
        if(str[i]=='c')
            CCount++;
        else if(str[i]=='k')
        {
            ans=max(ans,CCount);
            CCount--;
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
    	string str;
    	cin>>str;
    	cout<<minNumberOfFrogs(str)<<endl;
    }
}