#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int func(int y)
{
	int a=0,mult=1;
	for(int i=0;i<10;i++,y/=2,mult*=2)
        if(y%2==0)
            a+=mult;
    return a;
}
int longestAwesome(string s) {
    int M[1024];
    for(int i=0;i<1024;i++)
        M[i]=1000000;
    int num=0;
    M[num]=-1;
    int ans=1;
    for(int i=0;i<s.size();i++)
    {
        int x=s[i]-'0';
        if((num & (1<<x)) == 0)
            num = (num | (1<<x));
        else
            num = (num & func(1<<x));
  
        for(int x=0;x<10;x++)
        {
            int ori=num;
            if((num & (1<<x)) == 0)
                num = (num | (1<<x));
            else
                num = (num & func(1<<x));

            ans=max(ans,i-M[num]);
            num=ori;
        }
        ans=max(ans,i-M[num]);
        M[num]=min(M[num],i);
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
    	string s;
    	cin>>s;
    	cout<<longestAwesome(s)<<endl;
    }
}
