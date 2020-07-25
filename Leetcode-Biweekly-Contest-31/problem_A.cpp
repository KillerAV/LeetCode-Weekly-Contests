#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int countOdds(int low, int high) {   
    int n=high-low+1;
    if(n%2==0)
        return n/2;
    else
        if(low%2==0)
            return n/2;
        else
            return n/2+1;
    
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
    	int low,high;
    	cin>>low>>high;
    	cout<<countOdds(low,high)<<endl;
    }
}
