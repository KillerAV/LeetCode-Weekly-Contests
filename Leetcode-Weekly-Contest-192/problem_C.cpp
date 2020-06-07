#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<string> arr;
int i;
void initialise(string homepage) {
	arr.clear();
    arr.push_back(homepage);
    i=0;
}

void visit(string url) {
    arr.erase(arr.begin()+i+1,arr.end());
    arr.insert(arr.begin()+i+1,url);
    i=arr.size()-1;
}

string back(int steps) {
    int move=min(i,steps);
    i-=move;
    return arr[i];
}

string forward(int steps) {
    int n=arr.size();
    int move=min(n-i-1,steps);
    i+=move;
    return arr[i];
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
    	while(N--)
    	{
    		string type;
    		cin>>type;
    		if(type=="initialise")
    		{
    			string a;
    			cin>>a;
    			initialise(a);
    		}
    		else if(type=="visit")
    		{
    			string a;
    			cin>>a;
    			visit(a);
    		}
    		else if(type=="back")
    		{
    			int steps;
    			cin>>steps;
    			cout<<back(steps)<<endl;
  			}
  			else if(type=="forward")
  			{
  				int steps;
    			cin>>steps;
    			cout<<forward(steps)<<endl;
  			}
    	}
    }
    

}