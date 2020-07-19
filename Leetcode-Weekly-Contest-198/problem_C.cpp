#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

pair<int,int> func(string &s, int *start, int *end, int a, int b)
{
    if(a>b)
        return {1000000,-1};
    int x=a,y=b;
    for(int j=a;j<=y;j++)
    {
        x=min(x,start[s[j]-'a']);
        y=max(y,end[s[j]-'a']);
    }
    
    pair<int,int> temp=func(s,start,end,x,a-1);
    x=min(x,temp.first);
    y=max(y,temp.second);
    return {x,y};
}
vector<string> maxNumOfSubstrings(string s) {
    
    int N=s.size();
    int start[26],end[26];
    for(int i=0;i<26;i++)
    {
        start[i]=-1;
        end[i]=N;
    }
    
    for(int i=0;i<N;i++)
    {
        int j=s[i]-'a';
        if(start[j]==-1)
            start[j]=i;
        end[j]=i;
    }
    vector<pair<int,int>> arr;
    for(int i=0;i<26;i++)
    {
        if(start[i]==-1)
            continue;
        
        pair<int,int> a = func(s,start,end,start[i],end[i]);
        arr.push_back({a.second,a.first});
    }
   
    sort(arr.begin(),arr.end());
    
    int index=0;
    vector<string> ans;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i].second>arr[index].first)
        {
            string temp;
            for(int j=arr[index].second;j<=arr[index].first;j++)
                temp+=s[j];
            ans.push_back(temp);
            index=i;
        }
    }
    string temp;
    for(int j=arr[index].second;j<=arr[index].first;j++)
        temp+=s[j];
    ans.push_back(temp);
  
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
    	vector<string> ans=maxNumOfSubstrings(s);
    	for(int i=0;i<ans.size();i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
}
