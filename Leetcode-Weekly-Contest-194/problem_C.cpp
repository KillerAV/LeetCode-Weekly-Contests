#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

 vector<int> avoidFlood(vector<int>& rains) {
    int N=rains.size();
    vector<int> ans(N);
    set<int> empt;
    map<int,int> S;
    for(int i=0;i<N;i++)
        if(rains[i]==0)
            empt.insert(i);
        else
        {
            if(S.count(rains[i]))
            {
                auto it=empt.upper_bound(S[rains[i]]);
                if(it==empt.end())
                {
                    vector<int> x;
                    return x;
                }
                ans[*it]=rains[i];
                S[rains[i]]=i;
                empt.erase(it);
                ans[i]=-1;
            }
            else
            {
                S.insert({rains[i],i});
                ans[i]=-1;
            }
        }
    
    for(auto it=empt.begin();it!=empt.end();it++)
        ans[*it]=1;
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
    	vector<int> rains(N);
    	for(int i=0;i<N;i++)
    		cin>>rains[i];
    	vector<int> ans = avoidFlood(rains);
    	for(int i=0;i<N;i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
}
