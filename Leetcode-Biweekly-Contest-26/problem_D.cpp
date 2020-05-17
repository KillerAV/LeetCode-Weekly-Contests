#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int dp[5001][5001];
bool func(vector<int> &cost, int target, string &ans, string &output, int i=0)
{
    if(target<0)
        return false;
    if(target==0)
    {
        if(output.size()>ans.size())
            ans=output;
        return true;
    }
    if(dp[i][target]!=-1)
        return dp[i][target];
    else
    {
        bool f=false;
        for(int j=9;j>=1;j--)
        {
            output+=j+'0';
            f=(func(cost,target-cost[j-1],ans,output,i+1) || f);
            output.pop_back();
        }
        dp[i][target]=f;
        return f;
    }
}
string largestNumber(vector<int>& cost, int target) {
    string ans="0";
    string output="";
    for(int i=0;i<=target;i++)
        for(int j=0;j<=target;j++)
            dp[i][j]=-1;
    func(cost,target,ans,output);
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
    	int N;
    	cin>>N;
    	vector<int> cost(N);
    	int target;
    	cin>>target;
    	for(int i=0;i<N;i++)
    		cin>>cost[i];

    	cout<<largestNumber(cost,target)<<endl;
    }

}