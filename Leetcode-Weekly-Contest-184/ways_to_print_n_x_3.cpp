#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int numOfWays(int n) {
    ll RGR=6,RGY=6,M=1000000007;
    for(int i=2;i<=n;i++)
    {
        ll newRGR=((RGR*3)%M+(RGY*2)%M)%M;
        ll newRGY=((RGR*2)%M+(RGY*2)%M)%M;
        RGR=newRGR;
        RGY=newRGY;
    }
    return (RGR+RGY)%M;
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
        cout<<numOfWays(N)<<endl;
    }
    
}