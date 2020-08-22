#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

string thousandSeparator(int n) {
    string str;
    if(n==0)
        return "0";
    int i=1;
    while(n)
    {
        int temp=n%10;
        str+=temp+'0';
        n/=10;
        if(i%3==0 && n)
            str+='.';
        
        i++;
    }
    reverse(str.begin(),str.end());
    return str;
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
    	int n;
    	cin>>n;
    	cout<<thousandSeparator(n)<<endl;
    }
}
