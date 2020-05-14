#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

string reformat(string s) {
    string digit,alph;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0' && s[i]<='9')
            digit+=s[i];
        else
            alph+=s[i];
    int a=digit.size(),b=alph.size();
    if(abs(a-b)>1)
        return "";
    string str;
    if(a<b)
        swap(digit,alph);
    
    for(int i=0;i<digit.size();i++)
    {
        str+=digit[i];
        if(i<alph.size())
            str+=alph[i];
    }
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
    	string str;
    	cin>>str;
    	cout<<reformat(str)<<endl;

    }
}