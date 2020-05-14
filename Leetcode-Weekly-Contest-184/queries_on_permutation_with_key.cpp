#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<int> processQueries(vector<int>& queries, int m) {
    vector<int> arr;
    for(int i=0;i<m;i++)
        arr.push_back(i+1);
    vector<int> ans;
    for(int i=0;i<queries.size();i++)
    {
        int number=queries[i],index=-1;
        vector<int> temp;
        temp.push_back(number);
        for(int i=0;i<m;i++)
            if(arr[i]==number)
                index=i;
            else
                temp.push_back(arr[i]);
        
        ans.push_back(index);
        arr=temp;
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
    	int M;
    	cin>>M;
    	int Q;
    	cin>>Q;
    	vector<int> queries(Q);
    	for(int i=0;i<Q;i++)
    		cin>>queries[i];
    	vector<int> ans=processQueries(queries,M);
    	for(int i=0;i<ans.size();i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
    
}