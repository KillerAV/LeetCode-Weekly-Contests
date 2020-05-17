#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int ans=0;
    for(int i=0;i<startTime.size();i++)
        if(queryTime>=startTime[i]&& queryTime<=endTime[i])
            ans++;
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
    	int N;
    	cin>>N;
    	vector<int> startTime(N),endTime(N);
    	int queryTime;
    	for(int i=0;i<N;i++)
    		cin>>startTime[i];
    	for(int i=0;i<N;i++)
    		cin>>endTime[i];
    	cin>>queryTime;
    	cout<<busyStudent(startTime,endTime,queryTime)<<endl;
    }
}