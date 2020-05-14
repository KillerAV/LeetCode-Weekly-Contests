#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

string ans;
bool recursion(int n, int &k, string str)
{
    if(n==0)
    {
        if(k==1)
        {
            ans=str;
            return true;
        }
        k--;
        return false;
    }
    char prev=0;
    if(str.size()!=0)
        prev=str[str.size()-1];
    for(char x='a';x<='c';x++)
        if(prev!=x && recursion(n-1,k,str+x))
            return true;
    return false;
}
string getHappyString(int n, int k) {
    string str;
    recursion(n,k,str);
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
        int N,K;
        cin>>N>>K;
        ans="";
        cout<<getHappyString(N,K)<<endl;
    }
    
}