#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int minFlips(string target) {
    int n=target.size();
    int ans=0;
    if(target[n-1]=='0')
    {
        for(int i=n-1;i>=0;)
        {
            while(i>=0 && target[i]=='0')
                i--;
            int count=0;
            while(i>=0 && target[i]=='1')
            {
                i--;
                count++;
            }
            if(count)
                ans+=2;
        }
    }
    else
    {
        int start=n-1;
        while(start>=0 && target[start]=='1')
            start--;
        ans++;
        for(int i=start;i>=0;)
        {
            while(i>=0 && target[i]=='0')
                i--;
            int count=0;
            while(i>=0 && target[i]=='1')
            {
                i--;
                count++;
            }
            if(count)
                ans+=2;
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
    	string str;
    	cin>>str;
    	cout<<minFlips(str)<<endl;
    }
}
