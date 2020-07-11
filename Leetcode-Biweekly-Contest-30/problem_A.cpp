#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

string reformatDate(string date) {
    string dd,mm,yyyy,ans;
    int i=0;
    while(date[i]>='0' && date[i]<='9')
    {   
        dd+=date[i];
        i++;
    }   
    if(dd.size()==1)
        dd="0"+dd;
    i+=3;
   	for(int j=0;j<3;j++,i++)
    	mm+=date[i];
    i++;
    for(int j=0;j<4;j++,i++)
    	yyyy+=date[i];

    ans=yyyy;
    ans+="-";
    string a[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for(int i=0;i<12;i++)
        if(a[i]==mm)
        {
            string x;
            int a=i+1;
            x+=a%10+'0';
            a/=10;
            x+=a%10+'0';
            reverse(x.begin(),x.end());
            ans+=x;
        }
    ans+="-"+dd;
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
    	string date;
    	cin>>date;
    	cout<<reformatDate(date)<<endl;

    }
}
