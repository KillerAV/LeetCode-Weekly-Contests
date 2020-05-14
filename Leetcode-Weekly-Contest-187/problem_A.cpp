#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

string destCity(vector<vector<string>>& paths) {
    map<string,int> M;
    set<string> S;
    for(int i=0;i<paths.size();i++)
    {
        M[paths[i][0]]++;
        S.insert(paths[i][0]);
        S.insert(paths[i][1]);
    }
    for(auto it=S.begin();it!=S.end();it++)
        if(M[*it]==0)
            return *it;
    return "N";
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
    		string A;
    		cin>>A;
    		arr[i].push_back(A);
    		cin>>A;
    		arr[i].push_back(A);
    	}
    	cout<<destCity(arr)<<endl;
    }
}