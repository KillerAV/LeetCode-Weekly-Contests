#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int ans=0,left=0,filled=numBottles;
    while(filled)
    {
        ans+=filled;
        left+=filled;
        filled=left/numExchange;
        left=left%numExchange;
    }
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
    	int numBottles,numExchange;
    	cin>>numBottles>>numExchange;
    	cout<<numWaterBottles(numBottles,numExchange)<<endl;
    }
}
