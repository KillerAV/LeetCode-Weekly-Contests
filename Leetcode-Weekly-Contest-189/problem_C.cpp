#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool mycompare(vector<string> A,vector<string> B)
{
    return A.size()<=B.size();
}
vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> ans;
    int N=favoriteCompanies.size();
    for(int i=0;i<N;i++)
    {
        bool a=true;
        unordered_set<string> S;
        for(int k=0;k<favoriteCompanies[i].size();k++)
            S.insert(favoriteCompanies[i][k]);
        int req=S.size();
        for(int j=0;j<N;j++)
        {
            if(i==j || favoriteCompanies[i].size()>favoriteCompanies[j].size())
                continue;
            
            
            int c=0;
            for(int k=0;k<favoriteCompanies[j].size();k++)
                if(S.count(favoriteCompanies[j][k]))
                    c++;
            
            if(c==req)
            {
                a=false;
                break;
            }
        }
        if(a)
            ans.push_back(i);
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
    		int x;
    		cin>>x;
    		vector<string> temp(x);
    		for(int j=0;j<x;j++)
    			cin>>temp[j];
    		arr[i]=temp;
    	}
    	vector<int> ans=peopleIndexes(arr);
    	for(int i=0;i<ans.size();i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
}