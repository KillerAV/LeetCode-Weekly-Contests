#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool hasAllCodes(string s, int k) {
    set<int> S;
    int num=0,mult=(1<<(k-1));
    for(int j=0;j<k;j++,mult/=2)
        num+=(s[j]-'0')*mult;
    S.insert(num);
    for(int j=k;j<s.size();j++)
    {
        num=(num*2)%(1<<k);
        num+=s[j]-'0';
        S.insert(num);
    }
    int x=S.size();
    return x==(1<<k);
    
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
    	string str;
    	int k;
    	cin>>str>>k;
    	if(hasAllCodes(str,k))
    		cout<<"true"<<endl;
    	else
    		cout<<"false"<<endl;
    }
}