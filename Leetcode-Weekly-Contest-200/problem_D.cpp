#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

ll dp[100000][2][2];
unordered_map<int,int> P1,P2;
ll func(vector<int> &num1, vector<int> &num2, int a, int i=0, bool flag=false)
{
    if(a==0 && i==num1.size())
        return 0;
    if(a==1 && i==num2.size())
        return 0;
    if(dp[i][a][flag]==-1)
    {
        long long ans=0;
        if(a==0)
        {
            ll opt1=func(num1,num2,a,i+1,1)+num1[i],opt2=0;
            auto it=P2.find(num1[i]);
            if(it!=P2.end() && flag)
                opt2=func(num1,num2,1,it->second,0);
            ans=max(opt1,opt2);
        }
        else
        {
            ll opt1=func(num1,num2,a,i+1,1)+num2[i],opt2=0;
            auto it=P1.find(num2[i]);
            if(it!=P1.end() && flag)
                opt2=func(num1,num2,0,it->second,0);
            ans=max(opt1,opt2);
        }
        dp[i][a][flag]=ans;
    }
    return dp[i][a][flag];
}
int maxSum(vector<int>& num1, vector<int>& num2) {
    
    P1.clear();
    P2.clear();
    for(int i=0;i<num1.size();i++)
        P1[num1[i]]=i;
    for(int i=0;i<num2.size();i++)
        P2[num2[i]]=i;
    
    for(int i=0;i<max(num1.size(),num2.size());i++)
        for(int j=0;j<2;j++)
            dp[i][j][0]=dp[i][j][1]=-1;
    return max(func(num1, num2, 0), func(num1, num2, 1))%mod;
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
    	int n;
    	cin>>n;
    	vector<int> num1(n);
    	for(int i=0;i<n;i++)
    		cin>>num1[i];
    	int m;
    	cin>>m;
    	vector<int> num2(m);
    	for(int i=0;i<m;i++)
    		cin>>num2[i];

    	cout<<maxSum(num1,num2)<<endl;
    }
}
