#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

string entityParser(string text) {
    string output;
    string str=text;
    for(int i=0;i<text.size();i++)
    {
        if(i+5<text.size() && str[i]=='&' && str[i+1]=='q' && str[i+2]=='u' && str[i+3]=='o' && str[i+4]=='t' && str[i+5]==';')
        {
            output+="\"";
            i+=5;
        }
        else if(i+5<text.size() && str[i]=='&' && str[i+1]=='a' && str[i+2]=='p' && str[i+3]=='o' && str[i+4]=='s' && str[i+5]==';')
        {
            output+="\'";
            i+=5;
        }
        else if(i+4<text.size() && str[i]=='&' && str[i+1]=='a' && str[i+2]=='m' && str[i+3]=='p' && str[i+4]==';')
        {
            output+="&";
            i+=4;
        }
        else if(i+3<text.size() && str[i]=='&' && str[i+1]=='g' && str[i+2]=='t' && str[i+3]==';')
        {
            output+=">";
            i+=3;
        }
        else if(i+3<text.size() && str[i]=='&' && str[i+1]=='l' && str[i+2]=='t' && str[i+3]==';')
        {
            output+="<";
            i+=3;
        }
        else if(i+6<text.size() && str[i]=='&' && str[i+1]=='f' && str[i+2]=='r' && str[i+3]=='a' && str[i+4]=='s' && str[i+5]=='l' && str[i+6]==';')
        {
            output+="/";
            i+=6;
        }
        else
            output+=str[i];
        
    }
    return output;
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
    	string text;
    	cin>>text;
    	cout<<entityParser(text)<<endl;
    }
    
}