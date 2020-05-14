#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int kthSmallest(vector<vector<int>>& mat, int k) {
    int N=mat.size();
    int M=mat[0].size();
    
    vector<int> index(N);
    for(int i=0;i<N;i++)
        index[i]=0;
    
    int sum=0;
    for(int i=0;i<N;i++)
        sum+=mat[i][index[i]];
    
    priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> Q;
    Q.push({sum,index});
    k--;
    set<vector<int>> S;
    S.insert(index);
    while(k--)
    {
        pair<int,vector<int>> temp=Q.top();
        
        Q.pop();
        for(int i=0;i<N;i++)
            if(temp.second[i]!=M-1)
            {
                temp.second[i]++;
                if(!S.count(temp.second))
                {
                    Q.push({temp.first+mat[i][temp.second[i]]-mat[i][temp.second[i]-1],temp.second});
                    S.insert(temp.second);
                }
                temp.second[i]--;
            }   
    }
    return Q.top().first;
    
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
    	int N,M,K;
    	cin>>N>>M>>K;
    	vector<vector<int>> arr(N);
    	for(int i=0;i<N;i++)
    	{
    		vector<int> temp(M);
    		for(int j=0;j<M;j++)
    			cin>>temp[j];
    		arr[i]=temp;
    	}
    	cout<<kthSmallest(arr,K)<<endl;
    }
}