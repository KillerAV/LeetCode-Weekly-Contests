#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

map<int,int> dp[100][26][100];
int func(vector<pair<int,int>> &pos, int k, int i=0, int prev=0, int prevcount=0, int already=0)
{
    if(i==pos.size()-1 || k>=pos[pos.size()-1].first-pos[i].first)  
        return 0;

    auto it=dp[i][prev][k].find(prevcount);
    if(it==dp[i][prev][k].end())
    {
        int count=pos[i+1].first-pos[i].first;
        if(pos[i].second==prev)
            count+=prevcount;

        int curr;
        if(count>=100)
            curr=4;
        else if(count>=10)
            curr=3;
        else if(count>=2)
            curr=2;
        else
            curr=1;

        int minus=0;
        if(prev==pos[i].second)
            minus=already;
        int ans=func(pos,k,i+1,pos[i].second,count,curr)+curr-minus;
        if(count>9 && k-count+9>=0)
            ans=min(ans,func(pos,k-count+9,i+1,pos[i].second,9,2)+2-minus);
        if(count>1 && k-count+1>=0)
            ans=min(ans,func(pos,k-count+1,i+1,pos[i].second,1,1)+1-minus);
        if(k-count>=0)
            ans=min(ans,func(pos,k-count,i+1,prev,prevcount,already));
        dp[i][prev][k][prevcount]=ans;
        return ans;
    }
    return it->second;
}
int getLengthOfOptimalCompression(string s, int k) {
    
    for(int i=0;i<100;i++)
    	for(int j=0;j<26;j++)
    		for(int k=0;k<100;k++)
    			dp[i][j][k].clear();
    vector<pair<int,int>> pos;
    for(int i=0;i<s.size();)
    {
        pos.push_back({i,s[i]-'a'});
        int j=i;
        for(;j<s.size() && s[i]==s[j];j++);
        i=j;
    }
    pos.push_back({s.size(),-1});
    
    return func(pos,k);
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
    	cout<<getLengthOfOptimalCompression(s,k)<<endl;
    }
}
