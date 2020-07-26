#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

string restoreString(string s, vector<int>& indices) {
    string x;
    for(int i=0;i<indices.size();i++)
        x+='a';
    for(int i=0;i<indices.size();i++)
        x[indices[i]]=s[i];
    return x;
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
    	string str;
    	cin>>str;
    	vector<int> indices(N);
    	for(int i=0;i<N;i++)
    		cin>>indices[i];
    	cout<<restoreString(str,indices)<<endl;
    }
}
