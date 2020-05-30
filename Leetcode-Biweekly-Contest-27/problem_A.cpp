#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool canBeEqual(vector<int>& target, vector<int>& arr) {    
    map<int,int> M;
    for(int i=0;i<target.size();i++)
        M[target[i]]++;
    for(int i=0;i<arr.size();i++)
        M[arr[i]]--;
    
    for(auto it=M.begin();it!=M.end();it++)
        if(it->second!=0)
            return false;
    return true;
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
    	int N,M;
    	cin>>N>>M;
    	vector<int> target(N),arr(M);
    	for(int i=0;i<N;i++)
    		cin>>target[i];
    	for(int i=0;i<M;i++)
    		cin>>arr[i];

    	if(canBeEqual(target,arr))
    		cout<<"true"<<endl;
    	else
    		cout<<"false"<<endl;
    }
}