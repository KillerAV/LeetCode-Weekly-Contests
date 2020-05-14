#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    vector<vector<string>> ans;
    map<int,map<string,int>> M;
    set<string> distinct;
    for(int i=0;i<orders.size();i++)
    {
        M[stoi(orders[i][1])][orders[i][2]]++;
        distinct.insert(orders[i][2]);
    }
    
    vector<string> temp;
    temp.push_back("Table");
    for(auto it=distinct.begin();it!=distinct.end();it++)
        temp.push_back(*it);
    ans.push_back(temp);
    
    for(auto it=M.begin();it!=M.end();it++)
    {
        vector<string> temp;
        string x;
        int a=it->first;
        while(a)
        {
            x+=a%10+'0';
            a/=10;
        }
        reverse(x.begin(),x.end());
        temp.push_back(x);
        for(auto jt=distinct.begin();jt!=distinct.end();jt++)
        {
            int count=it->second[*jt];
            string x;
            if(count==0)
                x="0";
            while(count)
            {
                x+=count%10+'0';
                count/=10;
            }
            reverse(x.begin(),x.end());
            temp.push_back(x);
        }
        ans.push_back(temp);
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
    	vector<vector<string>> arr(N);
    	for(int i=0;i<N;i++)
    	{
    		vector<string> temp(3);
    		cin>>temp[0]>>temp[1]>>temp[2];
    		arr[i]=temp;
    	}
    	vector<vector<string>> result=displayTable(arr);
    	for(int i=0;i<result.size();i++)
    	{
    		for(int j=0;j<result[i].size();j++)
    			cout<<result[i][j]<<" ";
    		cout<<endl;
    	}
    }
}