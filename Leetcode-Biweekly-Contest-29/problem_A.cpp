#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

double average(vector<int>& salary) {
    double ans=0;
    sort(salary.begin(),salary.end());
    for(int i=1;i+1<salary.size();i++)
        ans+=salary[i];
    int N=salary.size()-2;
    return ans/N;
    
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
    	vector<int> salary(N);
    	for(int i=0;i<N;i++)
    		cin>>salary[i];

    	cout<<average(salary)<<endl;
    	
    }
    
}
