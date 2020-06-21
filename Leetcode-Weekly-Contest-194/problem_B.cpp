#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

string convert(int N)
{
    string x;
    while(N)
    {
        x+=N%10+'0';
        N/=10;
    }
    reverse(x.begin(),x.end());
    return x;
}
vector<string> getFolderNames(vector<string>& names) {
    int N=names.size();
    vector<string> ans(N);
    map<string,int> X;
    for(int i=0;i<N;i++)
    {
        auto it=X.find(names[i]);
        if(it==X.end())
        {
            X.insert({names[i],1});
            ans[i]=names[i];
        }
        else
        {
            int num=X[names[i]];
            while(X.count(names[i]+"("+convert(num)+")"))
                num++;
            ans[i]=names[i]+"("+convert(num)+")";
            num++;
            X[names[i]]=num;
            X[ans[i]]=1;
        }
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
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
    	vector<string> names(N);
    	for(int i=0;i<N;i++)
    		cin>>names[i];
    	vector<string> ans = getFolderNames(names);
    	for(int i=0;i<N;i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }
}
