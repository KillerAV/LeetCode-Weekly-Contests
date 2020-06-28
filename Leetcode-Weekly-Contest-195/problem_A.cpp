#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool isPathCrossing(string path) {
    set<pair<int,int>> S;
    S.insert({0,0});
    int x=0,y=0;
    for(int i=0;i<path.size();i++)
    {
        if(path[i]=='N')
            x--;
        else if(path[i]=='S')
            x++;
        else if(path[i]=='E')
            y++;
        else if(path[i]=='W')
            y--;
        if(S.count({x,y}))
            return true;
        S.insert({x,y});
    }
    return false;
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
    	string path;
    	cin>>path;
    	cout<<isPathCrossing(path)<<endl;
    }
    
}
