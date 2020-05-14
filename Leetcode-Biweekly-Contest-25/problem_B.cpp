#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int maxDiff(int num) {
    string str;
    string a,b;
    int temp=num;
    while(temp)
    {
        str+=temp%10+'0';
        temp/=10;
    }
    int N=str.size();
    int i=N-1;
    a=str;b=str;
    while(i>=0 && a[i]=='9')
        i--;
    if(i>=0)
    {
        char ch=a[i];
        while(i>=0)
        {
            if(a[i]==ch)
                a[i]='9';
            i--;
        }
    }
    if(b[N-1]!='1')
    {
        char ch=b[N-1];
        int i=N-1;
        while(i>=0)
        {
            if(b[i]==ch)
                b[i]='1';
            i--;
        }
    }
    else
    {
        int i=N-1;
        while(i>=0 && (b[i]=='1' || b[i]=='0'))
            i--;
        if(i>=0)
        {
            char ch=b[i];
            while(i>=0)
            {
                if(b[i]==ch)
                    b[i]='0';
                i--;
            }
        }
    }
    
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int A=stoi(a);
    int B=stoi(b);
    return abs(A-B);
    
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
    	cout<<maxDiff(N)<<endl;
    }
}