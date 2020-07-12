#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

double getMinDistSum(vector<vector<int>>& positions) {
        
    double x=0,y=0;
    int N=positions.size();
    for(int i=0;i<N;i++)
    {
        x+=positions[i][0];
        y+=positions[i][1];
    }
    x/=N;
    y/=N;
    double ans=10000000;
    for(int i=0;i<10000;i++)
    {
        double xk=0,yk=0,dk=0,normaldk=0;
        for(int k=0;k<N;k++)
        {
            double dist=sqrt((positions[k][0]-x)*(positions[k][0]-x)+(positions[k][1]-y)*(positions[k][1]-y));
            xk+=positions[k][0]/dist;
            yk+=positions[k][1]/dist;
            dk+=1/dist;
            normaldk+=dist;
        }
        xk/=dk;
        yk/=dk;
        ans=min(ans,normaldk);
        x=xk;
        y=yk;
    }
    
    return ans;
}
int main() 
{  
    int T;
    cin>>T;
    while(T--)
    {
    	int N;
    	cin>>N;
    	vector<vector<int>> positions(N);
    	for(int i=0;i<N;i++)
    	{
    		vector<int> temp(2);
    		cin>>temp[0]>>temp[1];
    		positions[i]=temp;
    	}
    	printf("%0.5lf\n", getMinDistSum(positions));
    }    
}
