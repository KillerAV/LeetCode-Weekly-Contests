#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<string> stringMatching(vector<string>& words) {
    vector<string> ans;
    for(int i=0;i<words.size();i++)
    {
        for(int j=0;j<words.size();j++)
            if(i!=j && words[j].find(words[i])!=string::npos)
            {
                ans.push_back(words[i]);
                break;
            }
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
	    vector<string> words(N);
	    for(int i=0;i<N;i++)
	    	cin>>words[i];
	    vector<string> ans=stringMatching(words);
	    for(int i=0;i<ans.size();i++)
	    	cout<<ans[i]<<" ";
	    cout<<endl;
	}
    
}