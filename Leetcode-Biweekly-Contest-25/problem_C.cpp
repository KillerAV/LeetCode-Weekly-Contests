#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool checkIfCanBreak(string s1, string s2) {
    string a=s1,b=s1,c=s2,d=s2;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<char>());
    sort(c.begin(),c.end());
    sort(d.begin(),d.end(),greater<char>());
    bool f1=1,f2=1;
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    for(int i=0;i<a.size();i++)
        if(a[i]<c[i])
            f1=0;
    for(int i=0;i<a.size();i++)
        if(c[i]<a[i])
            f2=0;
    return (f1 || f2);
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
    	string a,b;
    	cin>>a>>b;
    	cout<<checkIfCanBreak(a,b)<<endl;
    }
}