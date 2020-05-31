#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    sort(horizontalCuts.begin(),horizontalCuts.end());
    sort(verticalCuts.begin(),verticalCuts.end());
    long long maxa=0,maxb=0;
    int prevx=0;
    for(int i=0;i<horizontalCuts.size();i++)
    {
        maxa=max(maxa,(long long)(horizontalCuts[i]-prevx));
        prevx=horizontalCuts[i];
    }
    maxa=max(maxa,(long long)(h-horizontalCuts[horizontalCuts.size()-1]));
    int prevy=0;
    for(int i=0;i<verticalCuts.size();i++)
    {
        maxb=max(maxb,(long long)(verticalCuts[i]-prevy));
        prevy=verticalCuts[i];
    }
    maxb=max(maxb,(long long)(w-verticalCuts[verticalCuts.size()-1]));
    return (maxa*maxb)%1000000007;
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
    	int N,M,H,W;
    	cin>>N>>M>>H>>W;
    	vector<int> A(N),B(M);
    	for(int i=0;i<N;i++)
    		cin>>A[i];
    	for(int i=0;i<M;i++)
    		cin>>B[i];
    	cout<<maxArea(H,W,A,B)<<endl;
    }
}