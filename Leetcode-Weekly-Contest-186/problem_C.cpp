#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    map<int,vector<int>> M;
    for(int i=0;i<nums.size();i++)
        for(int j=0;j<nums[i].size();j++)
            M[i+j].push_back(nums[i][j]);
    vector<int> ans;
    for(auto it=M.begin();it!=M.end();it++)
    {
        vector<int> temp=it->second;
        for(int i=temp.size()-1;i>=0;i--)
            ans.push_back(temp[i]);
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
        int N;
        cin>>N;
        vector<vector<int>> arr(N);
        for(int i=0;i<N;i++)
        {
            int x;
            cin>>x;
            for(int j=0;j<x;j++)
            {
                int temp;
                cin>>temp;
                arr[i].push_back(temp);
            }
        }
        vector<int> ans=findDiagonalOrder(arr);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;

    }
}