#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool mycompare(string A, string B)
{
    return A.size()<B.size();
}
string arrangeWords(string text) {
    text[0]=text[0]+32;
    vector<string> arr;
    text+=' ';
    string temp;
    for(int i=0;i<text.size();i++)
        if(text[i]!=' ')
            temp+=text[i];
        else
        {
            arr.push_back(temp);
            temp.clear();
        }
    stable_sort(arr.begin(),arr.end(),mycompare);
    string ans;
    for(int i=0;i<arr.size();i++)
    {
        ans+=arr[i];
        if(i!=arr.size()-1)
            ans+=' ';
    }
    ans[0]=ans[0]-32;
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
    	string text;
    	cin>>text;
    	cout<<arrangeWords(text)<<endl;
    }
}