#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<string> buildArray(vector<int>& target, int n) {
    vector<string> output;
    int curr=1;
    for(int i=0;i<target.size();i++,curr++){
        while(curr<target[i])
        {
            output.push_back("Push");
            output.push_back("Pop");
            curr++;
        }
        output.push_back("Push");
    }
    return output;
    
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
    	int N,K;
    	cin>>N>>K;
    	vector<int> target(K);
    	for(int i=0;i<K;i++)
    		cin>>target[i];
    	vector<string> ans=buildArray(target,N);
    	for(int i=0;i<ans.size();i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
}