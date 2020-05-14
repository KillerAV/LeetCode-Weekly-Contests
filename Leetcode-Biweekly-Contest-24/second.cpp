#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int findMinFibonacciNumbers(int k) {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    while(arr[arr.size()-1]<=k)
        arr.push_back(arr[arr.size()-1]+arr[arr.size()-2]);
    
    int x=0;
    for(int i=arr.size()-1;i>=0;i--)
        while(k>=arr[i])
        {
            k-=arr[i];
            x++;
        }
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
        int K;
        cin>>K;
        cout<<findMinFibonacciNumbers(K)<<endl;
    }
    
}