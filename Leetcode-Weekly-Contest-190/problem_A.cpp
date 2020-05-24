#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int isPrefixOfWord(string sentence, string searchWord) {
    string temp;
    string s=sentence;
    s+=' ';
    int k=1;
    for(int i=0;i<s.size();i++)
        if(s[i]!=' ')
            temp+=s[i];
        else
        {
            int i=0;
            while(i<searchWord.size() && i<temp.size() && temp[i]==searchWord[i]){
                i++;
            }
            if(i==searchWord.size())
                return k;
            
            k++;
            temp.clear();
        }
    return -1;
    
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
    	string sentence,searchWord;
    	getline(cin,sentence);
    	cin>>searchWord;
    	cout<<isPrefixOfWord(sentence,searchWord)<<endl;
  
    }
}