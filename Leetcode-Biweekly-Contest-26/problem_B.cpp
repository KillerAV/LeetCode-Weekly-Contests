#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

string iost(int N)
{
    string X;
    while(N)
    {
        X+=N%10+'0';
        N/=10;
    }
    reverse(X.begin(),X.end());
    return X;
}
vector<string> simplifiedFractions(int n) {
    vector<string> ans;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int x=__gcd(i,j);
            if(x==1)
            {
                string x;
                x+=iost(i);
                x+='/';
                x+=iost(j);
                ans.push_back(x);
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
    	vector<string> ans = simplifiedFractions(N);
    	for(int i=0;i<ans.size();i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }

}